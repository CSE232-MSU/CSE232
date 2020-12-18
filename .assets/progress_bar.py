'''
Contains two functions used in creating a progress bar
based on a given starting and end date. The progress
is based on the date at which the script is being ran.

Author: Braedyn Lettinga
'''

from datetime import datetime, timedelta
from math import floor


def create_bar_str(p: float) -> str:
    """
    Creates a progress bar based on a given percentage.

    Parameters
    ----------
    `p`
        Percentage of the progress bar.

    Returns
    -------
    `str`
        Progress bar represented as a string.
    """
    progress_bar = {'width': 14, 'fill': '⬛', 'empty': '⬜'}

    fill_w = floor(p * progress_bar['width'])
    empty_w = progress_bar['width'] - fill_w

    return (fill_w * progress_bar['fill']) + (empty_w * progress_bar['empty'])


def generate_bar_html(start_date: str, end_date: str) -> str:
    """
    Generates a markdown-compatible HTML set that represents the
    progress bar.

    Parameters
    ----------
    `start_date`
        Starting date of the progress bar in "%m/%d/%Y" format.
    `end_date`
        Ending date of the progress bar in "%m/%d/%Y" format.

    Returns
    -------
    `str`
        Progress bar HTML as a string.
    """
    today = datetime.now()
    semester_start = datetime.strptime(start_date, '%m/%d/%Y')
    semester_end = datetime.strptime(end_date, '%m/%d/%Y')

    N = semester_end - semester_start
    n = semester_end - today

    p = 1 - (n.days / N.days)
    if p < 0:
        p = 0
    elif p > 1:
        p = 1

    bar_str = create_bar_str(p)
    return '<div align="center"><b>Semester Progress ({:.0%})</b></div>\n<div align="center">{}</div>\n&nbsp;'.format(p, bar_str)
