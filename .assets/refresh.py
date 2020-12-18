'''
Refreshes the master README.md file with the current calendar and
progress bar.

Author: Braedyn Lettinga
Dependencies: gitpython
'''

from datetime import datetime

import git
from pytz import timezone

from course_calendar import Calendar
from progress_bar import generate_bar_html


def commit_readme(commit_message: str) -> None:
    repo = git.Repo()
    origin = repo.remote('origin')

    repo.index.add(['README.md'])

    repo.index.commit(commit_message)
    origin.push()


readme_temp = open('.assets/README_TEMP.md', 'r').read()

### 🠗 CHANGE AS NECESSARY 🠗 ###
STARTING_DATE = '12/27/2020'  # (starting date must be a Sunday)
ENDING_DATE = '4/23/2021'

calendar = Calendar(STARTING_DATE, 16)

### 🠗 DO NOT CHANGE 🠗 ###
calendar_html = calendar.generate_calendar_html()
progress_bar_html = generate_bar_html(STARTING_DATE, ENDING_DATE)

readme_temp = readme_temp.replace(
    '&progress&', progress_bar_html).replace('&calendar&', calendar_html)

readme = open('README.md', 'w+', encoding="utf-8")
print(readme_temp, file=readme)
readme.close()

today = datetime.now(tz=timezone('US/Eastern'))

commit_readme('Auto Refresh @ {}'.format(today.strftime('%m/%d/%Y %I:%M %p EST')))
