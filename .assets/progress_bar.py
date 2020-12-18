
from datetime import datetime, timedelta
from math import floor


def create_bar_str(p: float) -> str:
    progress_bar = {'width': 14, 'fill': '⬛', 'empty': '⬜'}

    fill_w = floor(p * progress_bar['width'])
    empty_w = progress_bar['width'] - fill_w

    return (fill_w * progress_bar['fill']) + (empty_w * progress_bar['empty'])

def generate_bar_html(date_start: str, date_end: str) -> str:

    today = datetime.now()
    semester_start = datetime.strptime(date_start, '%m/%d/%Y')
    semester_end = datetime.strptime(date_end, '%m/%d/%Y')

    N = semester_end - semester_start    # number of days in the semester
    n = semester_end - today             # number of days from now until the end of the semester

    p = 1 - (n.days / N.days)            # percentage of completion

    if p < 0: 
        p = 0
    elif p > 1:
        p = 1

    bar_str = create_bar_str(p)

    return '<div align="center"><b>Semester Progress ({:.0%})</b></div>\n<div align="center">{}</div>'.format(p, bar_str)
