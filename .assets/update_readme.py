'''
Contains a Calendar and Day class used to generate an HTML calendar table
for the master README.md file.

Run this script on a local machine to update the master README.md file with
changes to the template (which is in this folder; .assets/README_TEMP.md).

You can make changes to the course schedule at the bottom of this script.

Author: Braedyn Lettinga
'''

import os
import re
from datetime import datetime, timedelta
from typing import List


def ordinal_suffix(n: int) -> str:
    """
    Returns the ordinal suffix for a given number.
    """
    return {1: "st", 2: "nd", 3: "rd"}.get(n % 10 * (n % 100 not in [11, 12, 13]), "th")


def fix_date_str(date: str) -> str:
    """
    Tests if a given date string is in the correct format, and corrects 
    for padding zeroes if they are missing.

    Parameters
    ----------
    `date`
        A date string in the format '%m/%d/%Y'. May be missing padding
        zeroes.

    Returns
    -------
    `str`
        The corrected date string
    """
    if not re.match(r'\d{1,2}/\d{1,2}/\d{4}', date):
        raise ValueError(
            'invalid date string; must be in format "%m/%d/%Y" (padding zeroes may be omitted)')
    month, day, year = date.split('/')
    return '{:02d}/{:02d}/{}'.format(int(month), int(day), year)


class Day:
    """
    Struct wrapper of the datetime object. Holds abstractions of date information
    used for the Calendar class to represent a single day entry.
    """

    def __init__(self, datetime_obj: datetime, text: str = '', href: str = ''):
        self.datetime_obj = datetime_obj
        self.day = datetime_obj.day
        self.month = datetime_obj.month
        self.year = datetime_obj.year
        self.date = datetime_obj.strftime('%m/%d/%Y')
        self.weekday = datetime_obj.strftime('%A').lower()
        self.hover = datetime_obj.strftime('%A, %B %d{} %Y (%m/%d/%Y)'.format(
            ordinal_suffix(self.day))).replace(' 0', ' ')
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
            date for which the calendar should begin from. Must be a Sunday.
        `weeks`
            Number of weeks that should be represented in the calendar.
        """
        if weeks < 1:
            raise ValueError('weeks must be >= 1')

        self.start_datetime_obj = datetime.strptime(start_date, '%m/%d/%Y')

        if self.start_datetime_obj.weekday() != 6:
            raise ValueError('starting date must be a Sunday')

        self.calendar = {}

        date = self.start_datetime_obj
        for _ in range(0, weeks):
            for _ in range(7):
                self.calendar[date.strftime('%m/%d/%Y')] = Day(date)
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
        return self.calendar[fix_date_str(date)]

    def __contains__(self, date: str) -> bool:
        """
        Tests if a `Day` instance with a given date string is in the calendar.
        """
        return fix_date_str(date) in self.calendar

    def set_event_series(self, text_format: str, end: int, every: int, start_date: str, skip_dates: List[str] = [], 
                         href_format: str = None, start: int = 1, step: int = 1) -> None:
        """
        Sets a series of calendar events enumerated from `start` to `end` (inclusively) in `step` intervals.

        Parameters
        ----------
        `text_format`
            A string that should expect one, integer format() argument alike: "Project {:02d}".
            Used as the displayed text of the calendar cell.
        `end`
            The number of events in the series. If text_format="Project {:02d}" and end=10,
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
            Used as an href attribute to the 'a' tag in the calendar HTML processed by generate_calendar_html().
        `start`
            Optional argument to begin enumeration from a different number, defaulted to 1.
        `step`
            Optional argument to skip enumerations by a particular step amount.
        """
        date = self[start_date].datetime_obj
        date_str = date.strftime('%m/%d/%Y')
        skip_dates = [fix_date_str(skip_date) for skip_date in skip_dates]

        while (start <= end) and (date_str in self):
            
            if date_str in skip_dates:
                date += timedelta(every)
                continue

            self[date_str].text = text_format.format(start)
            if href_format:
                self[date_str].href = href_format.format(start)

            start += step
            date += timedelta(every)
            date_str = date.strftime('%m/%d/%Y')

    def generate_calendar_html(self) -> str:
        """
        Exports the calendar to an HTML table as a string.
        """
        html = ''

        html += '<div align="center">\n<table>\n<thead>\n<tr>\n'
        for header in ['Week', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']:
            html += '<th align="center">{}</th>\n'.format(header)
        html += '</tr>\n</thead>\n<tbody>\n'

        week_n = 0
        date = self.start_datetime_obj
        stop_date = self.start_datetime_obj + timedelta(len(self.calendar))

        while date < stop_date:

            html += '<tr>\n'

            for i in range(8):
                date_str = date.strftime('%m/%d/%Y')
                day = self[date_str]

                if i == 0:
                    html += '<td align="center">{:02d}: {:02d}/{:02d}</td>\n'.format(
                        week_n, day.month, day.day)
                    continue
                if day.href:
                    html += '<td align="center" title="{}"><a href="{}">{}</a></td>\n'.format(
                        day.hover, day.href, day.text)
                else:
                    html += '<td align="center" title="{}">{}</td>\n'.format(
                        day.hover, day.text)

                date += timedelta(1)

            html += '</tr>\n'
            week_n += 1

        html += '</tbody>\n</table>\n</div>\n'

        return html


if __name__ == "__main__":

    ### ⬇️ CHANGE AS NECESSARY BELOW ⬇️ ###
    STARTING_DATE = '1/10/2021'  
    WEEKS = 16

    calendar = Calendar(start_date=STARTING_DATE, weeks=WEEKS)

    calendar.set_event_series(
        text_format='Week {:02d} Lectures',
        end=14,
        every=7,
        start_date='1/10/2021',
        skip_dates=[],
        href_format='https://github.com/braedynl/CSE232/tree/main/Lectures/Week%20{:02d}',
        start=0,
        step=1
    )

    ### ⬇️ DO NOT CHANGE BELOW ⬇️ ###
    calendar_html = calendar.generate_calendar_html()

    os.chdir(os.path.dirname(os.path.realpath(__file__)))

    template = open('README_TEMP.md', 'r').read()
    template = template.replace('&calendar&', calendar_html)

    readme = open('../README.md', 'w+', encoding="utf-8")
    print(template, file=readme)
    readme.close()
