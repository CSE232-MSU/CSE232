from course_calendar import Calendar
from progress_bar import generate_bar_html

readme_temp = open('.assets/README_TEMP.md', 'r').read()

calendar = Calendar('8/30/2020', 16)

calendar.set_event_series('Lab {:02d}', 13, 7, '9/4/2020', ['11/27/2020'])
calendar.set_event_series('Project {:02d}', 11, 7, '9/14/2020', ['10/5/2020', '11/9/2020'])

calendar_html = calendar.generate_calendar_html()
progress_bar_html = generate_bar_html('1/11/2021', '4/23/2021')

readme_temp = readme_temp.replace('&progress&', progress_bar_html).replace('&calendar&', calendar_html)

readme = open('README.md', 'w+', encoding="utf-8")
print(readme_temp, file=readme)
readme.close()