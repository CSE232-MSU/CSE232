#!/usr/bin/env python3
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
    date
        A date string in the format '%Y-%m-%d'. May be missing padding
        zeroes.

    Returns
    -------
    str
        The corrected date string
    """
    if not re.match(r'\d{4}-\d{1,2}-\d{1,2}', date):
        raise ValueError('invalid date string; must be in format "%Y-%m-%d" (padding zeroes may be omitted)')
    year, month, day = date.split('-')
    return '{}-{:02d}-{:02d}'.format(year, int(month), int(day))


class CalendarCell:

    def __init__(self, text: str = '', href: str = ''):
        self.text = text
        self.href = href

class Assignment(CalendarCell):

    def __init__(self, datetime_obj: datetime, text: str = '', href: str = ''):
        super().__init__(text, href)
        self.datetime_obj = datetime_obj
        self.day = datetime_obj.day
        self.month = datetime_obj.month
        self.year = datetime_obj.year
        self.date = datetime_obj.strftime('%Y-%m-%d')
        self.weekday = datetime_obj.strftime('%A').lower()
        self.hover = datetime_obj.strftime('%A, %B %d{} %Y (%m/%d/%Y)'.format(ordinal_suffix(self.day))).replace(' 0', ' ')


class Calendar:
    """
    Represents a generic calendar.

    Attributes
    ----------
    start_datetime_obj
        datetime instance of the starting date.
    calendar
        dict instance that holds the calendar data.
    """

    def __init__(self, start_date: str, weeks: int):
        """
        Creates a Calendar instance.

        Parameters
        ----------
        start_date
            A date string in the format '%Y-%m-%d' that represents the first
            date for which the calendar should begin from. Must be a Sunday.
        weeks
            Number of weeks that should be represented in the calendar.
        """
        if weeks < 1:
            raise ValueError('weeks must be >= 1')

        self.start_datetime_obj = datetime.strptime(start_date, '%Y-%m-%d')

        if self.start_datetime_obj.weekday() != 6:
            raise ValueError('starting date must be a Sunday')

        self.calendar = {}
        self.lectures = {}
        self.labs = {}

        date = self.start_datetime_obj
        for week_n in range(weeks):
            for _ in range(7):
                self.calendar[date.strftime('%Y-%m-%d')] = Assignment(date)
                date += timedelta(1)
            self.lectures[week_n] = CalendarCell()
            self.labs[week_n] = CalendarCell()

    def __str__(self) -> str:
        """
        Represents the calendar as a string.
        """
        return str(self.calendar)

    __repr__ = __str__

    def __getitem__(self, date: str) -> Assignment:
        """
        Retrieves the Day instance associated with a given date string.
        """
        return self.calendar[fix_date_str(date)]

    def __contains__(self, date: str) -> bool:
        """
        Tests if a Day instance with a given date string is in the calendar.
        """
        return fix_date_str(date) in self.calendar

    def set_event_series(self, text_format: str, end: int, every: int, start_date: str, skip_dates: List[str] = [], 
                         href_format: str = None, start: int = 1, step: int = 1) -> None:
        """
        Sets a series of calendar events enumerated from start to end (inclusively) in step intervals.

        Parameters
        ----------
        text_format
            A string that should expect one, integer format() argument alike: "Project {:02d}".
            Used as the displayed text of the calendar cell.
        end
            The number of events in the series. If text_format="Project {:02d}" and end=10,
            "Project 01", "Project 02", ..., "Project 10", will be inserted into the calendar.
        every
            The number of days to skip between event entries.
        start_date
            A date string in the format '%Y-%m-%d' that represents the first occurrence of the event.
            Subsequent event entries will begin enumerating from this date.
        skip_dates
            A list of date strings in the format '%Y-%m-%d' that indicate which dates in the series
            should be skipped.
        href_format
            A string that should expect one, integer format() argument, alike: "https://www.example{:02d}.com".
            Used as an href attribute to the 'a' tag in the calendar HTML processed by generate_calendar_html().
        start
            Optional argument to begin enumeration from a different number, defaulted to 1.
        step
            Optional argument to skip enumerations by a particular step amount, defaulted to 1.
        """
        date = self[start_date].datetime_obj
        date_str = date.strftime('%Y-%m-%d')
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
            date_str = date.strftime('%Y-%m-%d')

    def set_lecture_series(self, text_format: str, href_format: str, start: int, end: int) -> None:
        """
        Sets a series of weekly lectures enumerated from `start` to `end` inclusively.

        Parameters
        ----------
        text_format
            A string that should expect one, integer format() argument alike: "Week {:02d} Lectures".
            Used as the displayed text of the calendar cell.
        href_format
            A string that should expect one, integer format() argument, alike: "https://www.example{:02d}.com".
            Used as an href attribute to the 'a' tag in the calendar HTML processed by generate_calendar_html().
        start
            Starting week number.
        end
            Ending week number.
        """
        for week_n in range(start, end + 1):
            self.lectures[week_n].text = text_format.format(week_n)
            self.lectures[week_n].href = href_format.format(week_n)

    def set_lab_series(self, text_format: str, href_format: str, start: int, end: int) -> None:
        """
        Sets a series of weekly labs enumerated from `start` to `end` inclusively.

        Parameters
        ----------
        text_format
            A string that should expect one, integer format() argument alike: "Week {:02d} Lab".
            Used as the displayed text of the calendar cell.
        href_format
            A string that should expect one, integer format() argument, alike: "https://www.example{:02d}.com".
            Used as an href attribute to the 'a' tag in the calendar HTML processed by generate_calendar_html().
        start
            Starting week number.
        end
            Ending week number.
        """
        for week_n in range(start, end + 1):
            self.labs[week_n].text = text_format.format(week_n)
            self.labs[week_n].href = href_format.format(week_n)

    def generate_calendar_html(self) -> str:
        """
        Exports the calendar to an HTML table as a string.
        """
        html = ''

        html += '<div align="center">\n<table>\n<thead>\n<tr>\n'
        for header in ['Week', 'Lectures', 'Lab', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']:
            html += '<th align="center">{}</th>\n'.format(header)
        html += '</tr>\n</thead>\n<tbody>\n'

        week_n = 0
        date = self.start_datetime_obj
        stop_date = self.start_datetime_obj + timedelta(len(self.calendar))

        while date < stop_date:

            html += '<tr>\n'

            for i in range(10):
                date_str = date.strftime('%Y-%m-%d')
                day = self[date_str]

                if i == 0:
                    html += '<td align="center">{:02d}: {}</td>\n'.format(week_n, day.date)
                    continue
                if i == 1:
                    lecture = self.lectures[week_n]
                    html += '<td align="center"><a href="{}">{}</a></td>\n'.format(lecture.href, lecture.text)
                    continue
                if i == 2:
                    lab = self.labs[week_n]
                    html += '<td align="center"><a href="{}">{}</a></td>\n'.format(lab.href, lab.text)
                    continue
                if day.href:
                    html += '<td align="center" title="{}"><a href="{}">{}</a></td>\n'.format(day.hover, day.href, day.text)
                else:
                    html += '<td align="center" title="{}">{}</td>\n'.format(day.hover, day.text)

                date += timedelta(1)

            html += '</tr>\n'
            week_n += 1

        html += '</tbody>\n</table>\n</div>\n'

        return html


if __name__ == "__main__":

    ### ⬇️ CHANGE AS NECESSARY BELOW ⬇️ ###
    STARTING_DATE = '2021-1-10'
    WEEKS = 16

    calendar = Calendar(start_date=STARTING_DATE, weeks=WEEKS)

    calendar.set_lecture_series(
        text_format='Week {:02d}',
        href_format= 'https://cse232-msu.github.io/CSE232/schedule/week{:02d}/',
        start=0,
        end=14
    )

    calendar.set_lab_series(
        text_format='Lab {:02d}',
        href_format='https://github.com/CSE232-MSU/CSE232/blob/main/Labs/lab{:02d}.md',
        start=0,
        end=11
    )

    calendar.set_event_series(
        text_format='Homework {:02d}',
        end=20,
        every=7,
        start_date='2021-1-18',
        href_format='https://class.mimir.io/',
        start=0,
        step=2
    )

    calendar.set_event_series(
        text_format='Homework {:02d}',
        end=19,
        every=7,
        start_date='2021-1-21',
        href_format='https://class.mimir.io/',
        start=1,
        step=2
    )

    calendar['2021-4-26'].text = 'Tentative Final Exam'

    ### ⬇️ DO NOT CHANGE BELOW ⬇️ ###
    calendar_html = calendar.generate_calendar_html()

    os.chdir(os.path.dirname(os.path.realpath(__file__)))

    template = open('README_TEMP.md', 'r', encoding="utf-8").read()
    template = template.replace('&calendar&', calendar_html)

    readme = open('../README.md', 'w+', encoding="utf-8")
    print(template, file=readme)
    readme.close()
