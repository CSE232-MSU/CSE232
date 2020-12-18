'''
Contains a Calendar and Day class used to generate an HTML calendar table
for the master README.md file.

"Why not use CSS?" -- GitHub disables the connection between HTML and CSS
files when generating Markdown to prevent phishing attacks. So, one must
apply styling to every tag. Hopefully you can imagine why a script is
necessary for this, now.

Author: Braedyn Lettinga
Website: https://github.com/braedynl/
'''

from __future__ import annotations

import re
from datetime import datetime, timedelta
from typing import List, Tuple, Union


def ordinal_suffix(n: int) -> str:
    """
    Returns the ordinal suffix for a given number.
    """
    return {1: "st", 2: "nd", 3: "rd"}.get(n % 10 * (n % 100 not in [11, 12, 13]), "th")


class Day:
    """
    Day struct wrapper of the datetime object. Holds abstractions of date information
    used for the Calendar class to represent a single day entry.
    """

    def __init__(self, datetime_obj: datetime, week: int, text: str = '', href: str = ''):
        self.datetime_obj = datetime_obj
        self.day = datetime_obj.day
        self.month = datetime_obj.month
        self.year = datetime_obj.year
        self.date = datetime_obj.strftime('%m/%d/%Y')
        self.weekday = datetime_obj.strftime('%A').lower()
        self.hover = datetime_obj.strftime('%A, %B %d{}'.format(
            ordinal_suffix(self.day))).replace(' 0', ' ')
        self.week = week
        self.text = text
        self.href = href


class Calendar:
    """
    Represents a generic calendar.

    Attributes
    ----------
    `start_datetime_obj`
        datetime instance of the starting date.
    `calendar`
        dict instance that holds the calendar data.
    """

    def __init__(self, start_date: str, weeks: int):
        """
        Creates a `Calendar` instance.

        Parameters
        ----------
        `start_date`
            A date string in the format '%m/%d/%Y' that represents the first
            date for which the calendar should begin from.
        `weeks`
            Number of weeks that should be represented in the calendar.
        """
        if weeks < 1:
            raise ValueError('weeks must be >= 1')

        self.start_datetime_obj = datetime.strptime(
            self.__fix_date(start_date), '%m/%d/%Y')
        self.calendar = {}

        date = self.start_datetime_obj
        for week in range(1, weeks + 1):
            for _ in range(7):
                self.calendar[date.strftime('%m/%d/%Y')] = Day(date, week)
                date += timedelta(1)

    def __str__(self) -> str:
        """
        Represents the calendar as a string.
        """
        return str(self.calendar)

    def __repr__(self) -> str:
        """
        Represents the calendar as a string.
        """
        return str(self)

    def __getitem__(self, date: str) -> Day:
        """
        Retrieves the `Day` instance associated with a given date string.
        """
        return self.calendar[self.__fix_date(date)]

    def __contains__(self, date: str) -> bool:
        """
        Tests if a `Day` instance with a given date string is in the calendar.
        """
        return self.__fix_date(date) in self.calendar

    def __fix_date(self, date: str) -> str:
        """
        Tests if a given date string is in the correct format, and corrects 
        for padding zeroes if they are missing.

        Parameters
        ----------
        `date`
            A date string in the format '%m/%d/%Y'

        Returns
        -------
        `str`
            The corrected date string
        """
        if not re.match(r'\d{1,2}/\d{1,2}/\d{4}', date):
            raise ValueError(
                'invalid date string; must be in format "%m/%d/%Y"')
        month, day, year = date.split('/')
        return '{:02d}/{:02d}/{}'.format(int(month), int(day), year)

    def set_event_series(self, text_format: str, n: int, every: int, start_date: str, skip_dates: List[str] = [], href_format: str = None) -> None:
        """
        Sets a series of calendar events enumerated from 1 to `n` (inclusively).

        Parameters
        ----------
        `text_format`
            A string that should expect one, integer format() argument alike: "Project {:02d}".
            Used as the displayed text of the calendar cell.
        `n`
            The number of events in the series. If text_format="Project {:02d}" and n=10,
            "Project 01", "Project 02", ..., "Project 10", will be inserted into the calendar.
        `every`
            The number of days to skip between event entries.
        `start_date`
            A date string in the format '%m/%d/%Y' that represents the first occurrence of the event.
            Subsequent event entries will begin enumerating from this date.
        `skip_dates`
            A list of date strings in the format '%m/%d/%Y' that indicate which dates in the series
            should be skipped.
        `href_format`
            A string that should expect one, integer format() argument, alike: "https://www.example{:02d}.com".
            Used as an href attribute to the 'a' tag in the calendar HTML processed by export_html().
        """
        date = self[start_date].datetime_obj
        skip_dates = [self.__fix_date(skip_date) for skip_date in skip_dates]
        i = 1

        while i <= n:
            date_str = date.strftime('%m/%d/%Y')

            if date_str not in self:
                break
            if date_str in skip_dates:
                date += timedelta(every)
                continue

            self[date_str].text = text_format.format(i)
            if href_format:
                self[date_str].href = href_format.format(i)

            i += 1
            date += timedelta(every)

    def export_html(self, file_name: str = '.assets/calendar.html') -> None:
        """
        Exports the calendar to an HTML table.

        Parameters
        ----------
        `file_name`
            Name of the output HTML file, must end in '.html'
        """
        fp = open(file_name, 'w+')

        print('<div align="center">\n<table>\n<thead>\n<tr>', file=fp)
        for header in ['Week', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']:
            print('<th align="center">{}</th>'.format(header), file=fp)
        print('</tr>\n</thead>\n<tbody>', file=fp)

        week_n = 1
        date = self.start_datetime_obj
        stop_date = self.start_datetime_obj + timedelta(len(self.calendar))

        while date < stop_date:

            print('<tr>', file=fp)

            for i in range(8):
                date_str = date.strftime('%m/%d/%Y')
                day = self[date_str]

                if i == 0:
                    print('<td align="center">{:02d}: {:02d}/{:02d}</td>'.format(
                        week_n, day.month, day.day), file=fp)
                    continue
                if day.href:
                    print('<td align="center" title="{}"><a href="{}">{}</a></td>'.format(
                        day.hover, day.href, day.text), file=fp)
                else:
                    print(
                        '<td align="center" title="{}">{}</td>'.format(day.hover, day.text), file=fp)

                date += timedelta(1)

            print('</tr>', file=fp)
            week_n += 1

        print('</tbody>\n</table>\n</div>', file=fp)

        fp.close()


if __name__ == "__main__":
    pass
