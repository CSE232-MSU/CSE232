# Updating the Master README File

GitHub's Markdown renderer is beautiful, but, deep within that beauty, there's a dark and ugly secret. Want to know what it is?

<div align="center">
    <p>GitHub Markdown disables the style attribute on all HTML tags.</p>
</div>

[The reason for why is described here](https://stackoverflow.com/questions/20598628/do-style-tags-work-in-markdown), but, we don't care about reasons, we care about _work-arounds_. Let's talk about how to update the course schedule, and how to update the master README in general.

**Important**: changes to the master README file will be overwritten, i.e., they don't matter, and they will not remain if you update the README "officially", as described below.

## Updating Non-Calendar Things

In the .assets/ folder, you'll find a file named [README_TEMP.md](../README_TEMP.md). This is a "template" of the master README that is used by the Python script in the same folder, [update_readme.py](../update_readme.py).

update_readme.py cares about one thing, and _only_ one thing: "&calendar&".

What is "&calendar&"? It's an encoded "variable" in the template that update_readme.py finds, and replaces with the calendar's HTML (which update_readme.py generates). **You are free to edit the template however you like, but do not touch the &calendar& string whatsoever**.

After you've gone ahead and made your edits, run the update_readme.py script once on a local machine, and commit your changes. Congratulations, you've edited the master README!

## Updating Calendar Things

In the .assets/ folder is a Python script called [update_readme.py](../update_readme.py). It contains two classes: `Calendar`, and `Day`. The `Day` class acts like a C-style `struct`, where the `Calendar` is essentially a dictionary of `Day` instances.

You can make *any* arrangement of calendar events given the three functions I'll be describing below.

At the bottom of update_readme.py is a chunk of code left for anyone to fill-out:

```python
if __name__ == "__main__":

    ### ⬇️ CHANGE AS NECESSARY BELOW ⬇️ ###
    STARTING_DATE = '12/27/2020'  
    WEEKS = 16

    calendar = Calendar(start_date=STARTING_DATE, weeks=WEEKS)


    ### ⬇️ DO NOT CHANGE BELOW ⬇️ ###
    calendar_html = calendar.generate_calendar_html()

    os.chdir(os.path.dirname(os.path.realpath(__file__)))

    template = open('README_TEMP.md', 'r').read()
    template = template.replace('&calendar&', calendar_html)

    readme = open('../README.md', 'w+', encoding="utf-8")
    print(template, file=readme)
    readme.close()
```

(Note that this may have changed slightly since when this document was written -- refer to comments in the script)

You'll want to make your changes to the calendar above the `### ⬇️ DO NOT CHANGE BELOW ⬇️ ###` comment. But, of course, how can you change it?

&nbsp;

### The Constructor

```python
def __init__(self, start_date: str, weeks: int):
```

This is the constructor. It takes a starting date in the format `"%m/%d/%Y"` (e.g. `"1/18/2021"`, month/day/year), and a number of weeks. **The starting date must be a Sunday**.

With the following code,

```python
calendar = Calendar(start_date='12/27/2020', weeks=16)
```

the generated HTML looks like:

<div align="center">
<table>
<thead>
<tr>
<th align="center">Week</th>
<th align="center">Sunday</th>
<th align="center">Monday</th>
<th align="center">Tuesday</th>
<th align="center">Wednesday</th>
<th align="center">Thursday</th>
<th align="center">Friday</th>
<th align="center">Saturday</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">01: 12/27</td>
<td align="center" title="Sunday, December 27th"></td>
<td align="center" title="Monday, December 28th"></td>
<td align="center" title="Tuesday, December 29th"></td>
<td align="center" title="Wednesday, December 30th"></td>
<td align="center" title="Thursday, December 31st"></td>
<td align="center" title="Friday, January 1st"></td>
<td align="center" title="Saturday, January 2nd"></td>
</tr>
<tr>
<td align="center">02: 01/03</td>
<td align="center" title="Sunday, January 3rd"></td>
<td align="center" title="Monday, January 4th"></td>
<td align="center" title="Tuesday, January 5th"></td>
<td align="center" title="Wednesday, January 6th"></td>
<td align="center" title="Thursday, January 7th"></td>
<td align="center" title="Friday, January 8th"></td>
<td align="center" title="Saturday, January 9th"></td>
</tr>
<tr>
<td align="center">03: 01/10</td>
<td align="center" title="Sunday, January 10th"></td>
<td align="center" title="Monday, January 11th"></td>
<td align="center" title="Tuesday, January 12th"></td>
<td align="center" title="Wednesday, January 13th"></td>
<td align="center" title="Thursday, January 14th"></td>
<td align="center" title="Friday, January 15th"></td>
<td align="center" title="Saturday, January 16th"></td>
</tr>
<tr>
<td align="center">04: 01/17</td>
<td align="center" title="Sunday, January 17th"></td>
<td align="center" title="Monday, January 18th"></td>
<td align="center" title="Tuesday, January 19th"></td>
<td align="center" title="Wednesday, January 20th"></td>
<td align="center" title="Thursday, January 21st"></td>
<td align="center" title="Friday, January 22nd"></td>
<td align="center" title="Saturday, January 23rd"></td>
</tr>
<tr>
<td align="center">05: 01/24</td>
<td align="center" title="Sunday, January 24th"></td>
<td align="center" title="Monday, January 25th"></td>
<td align="center" title="Tuesday, January 26th"></td>
<td align="center" title="Wednesday, January 27th"></td>
<td align="center" title="Thursday, January 28th"></td>
<td align="center" title="Friday, January 29th"></td>
<td align="center" title="Saturday, January 30th"></td>
</tr>
<tr>
<td align="center">06: 01/31</td>
<td align="center" title="Sunday, January 31st"></td>
<td align="center" title="Monday, February 1st"></td>
<td align="center" title="Tuesday, February 2nd"></td>
<td align="center" title="Wednesday, February 3rd"></td>
<td align="center" title="Thursday, February 4th"></td>
<td align="center" title="Friday, February 5th"></td>
<td align="center" title="Saturday, February 6th"></td>
</tr>
<tr>
<td align="center">07: 02/07</td>
<td align="center" title="Sunday, February 7th"></td>
<td align="center" title="Monday, February 8th"></td>
<td align="center" title="Tuesday, February 9th"></td>
<td align="center" title="Wednesday, February 10th"></td>
<td align="center" title="Thursday, February 11th"></td>
<td align="center" title="Friday, February 12th"></td>
<td align="center" title="Saturday, February 13th"></td>
</tr>
<tr>
<td align="center">08: 02/14</td>
<td align="center" title="Sunday, February 14th"></td>
<td align="center" title="Monday, February 15th"></td>
<td align="center" title="Tuesday, February 16th"></td>
<td align="center" title="Wednesday, February 17th"></td>
<td align="center" title="Thursday, February 18th"></td>
<td align="center" title="Friday, February 19th"></td>
<td align="center" title="Saturday, February 20th"></td>
</tr>
<tr>
<td align="center">09: 02/21</td>
<td align="center" title="Sunday, February 21st"></td>
<td align="center" title="Monday, February 22nd"></td>
<td align="center" title="Tuesday, February 23rd"></td>
<td align="center" title="Wednesday, February 24th"></td>
<td align="center" title="Thursday, February 25th"></td>
<td align="center" title="Friday, February 26th"></td>
<td align="center" title="Saturday, February 27th"></td>
</tr>
<tr>
<td align="center">10: 02/28</td>
<td align="center" title="Sunday, February 28th"></td>
<td align="center" title="Monday, March 1st"></td>
<td align="center" title="Tuesday, March 2nd"></td>
<td align="center" title="Wednesday, March 3rd"></td>
<td align="center" title="Thursday, March 4th"></td>
<td align="center" title="Friday, March 5th"></td>
<td align="center" title="Saturday, March 6th"></td>
</tr>
<tr>
<td align="center">11: 03/07</td>
<td align="center" title="Sunday, March 7th"></td>
<td align="center" title="Monday, March 8th"></td>
<td align="center" title="Tuesday, March 9th"></td>
<td align="center" title="Wednesday, March 10th"></td>
<td align="center" title="Thursday, March 11th"></td>
<td align="center" title="Friday, March 12th"></td>
<td align="center" title="Saturday, March 13th"></td>
</tr>
<tr>
<td align="center">12: 03/14</td>
<td align="center" title="Sunday, March 14th"></td>
<td align="center" title="Monday, March 15th"></td>
<td align="center" title="Tuesday, March 16th"></td>
<td align="center" title="Wednesday, March 17th"></td>
<td align="center" title="Thursday, March 18th"></td>
<td align="center" title="Friday, March 19th"></td>
<td align="center" title="Saturday, March 20th"></td>
</tr>
<tr>
<td align="center">13: 03/21</td>
<td align="center" title="Sunday, March 21st"></td>
<td align="center" title="Monday, March 22nd"></td>
<td align="center" title="Tuesday, March 23rd"></td>
<td align="center" title="Wednesday, March 24th"></td>
<td align="center" title="Thursday, March 25th"></td>
<td align="center" title="Friday, March 26th"></td>
<td align="center" title="Saturday, March 27th"></td>
</tr>
<tr>
<td align="center">14: 03/28</td>
<td align="center" title="Sunday, March 28th"></td>
<td align="center" title="Monday, March 29th"></td>
<td align="center" title="Tuesday, March 30th"></td>
<td align="center" title="Wednesday, March 31st"></td>
<td align="center" title="Thursday, April 1st"></td>
<td align="center" title="Friday, April 2nd"></td>
<td align="center" title="Saturday, April 3rd"></td>
</tr>
<tr>
<td align="center">15: 04/04</td>
<td align="center" title="Sunday, April 4th"></td>
<td align="center" title="Monday, April 5th"></td>
<td align="center" title="Tuesday, April 6th"></td>
<td align="center" title="Wednesday, April 7th"></td>
<td align="center" title="Thursday, April 8th"></td>
<td align="center" title="Friday, April 9th"></td>
<td align="center" title="Saturday, April 10th"></td>
</tr>
<tr>
<td align="center">16: 04/11</td>
<td align="center" title="Sunday, April 11th"></td>
<td align="center" title="Monday, April 12th"></td>
<td align="center" title="Tuesday, April 13th"></td>
<td align="center" title="Wednesday, April 14th"></td>
<td align="center" title="Thursday, April 15th"></td>
<td align="center" title="Friday, April 16th"></td>
<td align="center" title="Saturday, April 17th"></td>
</tr>
</tbody>
</table>
</div>

In other words, an empty calendar.

So, how do we add events to the calendar?

&nbsp;

### Adding Single Events

As stated before, the `Calendar` class is essentially a dictionary of `Day` structs. You can use the `[]` operator with a `"%m/%d/%Y"` formatted date-string to access a particular `Day`, where you can then supply a string to the `Day`'s `text` attribute to appear on the output calendar.

Example:

```python
calendar = Calendar(start_date='12/27/2020', weeks=16)

calendar['2/15/2021'].text = "Assignment 1"
```

Output calendar HTML:

<div align="center">
<table>
<thead>
<tr>
<th align="center">Week</th>
<th align="center">Sunday</th>
<th align="center">Monday</th>
<th align="center">Tuesday</th>
<th align="center">Wednesday</th>
<th align="center">Thursday</th>
<th align="center">Friday</th>
<th align="center">Saturday</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">01: 12/27</td>
<td align="center" title="Sunday, December 27th"></td>
<td align="center" title="Monday, December 28th"></td>
<td align="center" title="Tuesday, December 29th"></td>
<td align="center" title="Wednesday, December 30th"></td>
<td align="center" title="Thursday, December 31st"></td>
<td align="center" title="Friday, January 1st"></td>
<td align="center" title="Saturday, January 2nd"></td>
</tr>
<tr>
<td align="center">02: 01/03</td>
<td align="center" title="Sunday, January 3rd"></td>
<td align="center" title="Monday, January 4th"></td>
<td align="center" title="Tuesday, January 5th"></td>
<td align="center" title="Wednesday, January 6th"></td>
<td align="center" title="Thursday, January 7th"></td>
<td align="center" title="Friday, January 8th"></td>
<td align="center" title="Saturday, January 9th"></td>
</tr>
<tr>
<td align="center">03: 01/10</td>
<td align="center" title="Sunday, January 10th"></td>
<td align="center" title="Monday, January 11th"></td>
<td align="center" title="Tuesday, January 12th"></td>
<td align="center" title="Wednesday, January 13th"></td>
<td align="center" title="Thursday, January 14th"></td>
<td align="center" title="Friday, January 15th"></td>
<td align="center" title="Saturday, January 16th"></td>
</tr>
<tr>
<td align="center">04: 01/17</td>
<td align="center" title="Sunday, January 17th"></td>
<td align="center" title="Monday, January 18th"></td>
<td align="center" title="Tuesday, January 19th"></td>
<td align="center" title="Wednesday, January 20th"></td>
<td align="center" title="Thursday, January 21st"></td>
<td align="center" title="Friday, January 22nd"></td>
<td align="center" title="Saturday, January 23rd"></td>
</tr>
<tr>
<td align="center">05: 01/24</td>
<td align="center" title="Sunday, January 24th"></td>
<td align="center" title="Monday, January 25th"></td>
<td align="center" title="Tuesday, January 26th"></td>
<td align="center" title="Wednesday, January 27th"></td>
<td align="center" title="Thursday, January 28th"></td>
<td align="center" title="Friday, January 29th"></td>
<td align="center" title="Saturday, January 30th"></td>
</tr>
<tr>
<td align="center">06: 01/31</td>
<td align="center" title="Sunday, January 31st"></td>
<td align="center" title="Monday, February 1st"></td>
<td align="center" title="Tuesday, February 2nd"></td>
<td align="center" title="Wednesday, February 3rd"></td>
<td align="center" title="Thursday, February 4th"></td>
<td align="center" title="Friday, February 5th"></td>
<td align="center" title="Saturday, February 6th"></td>
</tr>
<tr>
<td align="center">07: 02/07</td>
<td align="center" title="Sunday, February 7th"></td>
<td align="center" title="Monday, February 8th"></td>
<td align="center" title="Tuesday, February 9th"></td>
<td align="center" title="Wednesday, February 10th"></td>
<td align="center" title="Thursday, February 11th"></td>
<td align="center" title="Friday, February 12th"></td>
<td align="center" title="Saturday, February 13th"></td>
</tr>
<tr>
<td align="center">08: 02/14</td>
<td align="center" title="Sunday, February 14th"></td>
<td align="center" title="Monday, February 15th">Assignment 1</td>
<td align="center" title="Tuesday, February 16th"></td>
<td align="center" title="Wednesday, February 17th"></td>
<td align="center" title="Thursday, February 18th"></td>
<td align="center" title="Friday, February 19th"></td>
<td align="center" title="Saturday, February 20th"></td>
</tr>
<tr>
<td align="center">09: 02/21</td>
<td align="center" title="Sunday, February 21st"></td>
<td align="center" title="Monday, February 22nd"></td>
<td align="center" title="Tuesday, February 23rd"></td>
<td align="center" title="Wednesday, February 24th"></td>
<td align="center" title="Thursday, February 25th"></td>
<td align="center" title="Friday, February 26th"></td>
<td align="center" title="Saturday, February 27th"></td>
</tr>
<tr>
<td align="center">10: 02/28</td>
<td align="center" title="Sunday, February 28th"></td>
<td align="center" title="Monday, March 1st"></td>
<td align="center" title="Tuesday, March 2nd"></td>
<td align="center" title="Wednesday, March 3rd"></td>
<td align="center" title="Thursday, March 4th"></td>
<td align="center" title="Friday, March 5th"></td>
<td align="center" title="Saturday, March 6th"></td>
</tr>
<tr>
<td align="center">11: 03/07</td>
<td align="center" title="Sunday, March 7th"></td>
<td align="center" title="Monday, March 8th"></td>
<td align="center" title="Tuesday, March 9th"></td>
<td align="center" title="Wednesday, March 10th"></td>
<td align="center" title="Thursday, March 11th"></td>
<td align="center" title="Friday, March 12th"></td>
<td align="center" title="Saturday, March 13th"></td>
</tr>
<tr>
<td align="center">12: 03/14</td>
<td align="center" title="Sunday, March 14th"></td>
<td align="center" title="Monday, March 15th"></td>
<td align="center" title="Tuesday, March 16th"></td>
<td align="center" title="Wednesday, March 17th"></td>
<td align="center" title="Thursday, March 18th"></td>
<td align="center" title="Friday, March 19th"></td>
<td align="center" title="Saturday, March 20th"></td>
</tr>
<tr>
<td align="center">13: 03/21</td>
<td align="center" title="Sunday, March 21st"></td>
<td align="center" title="Monday, March 22nd"></td>
<td align="center" title="Tuesday, March 23rd"></td>
<td align="center" title="Wednesday, March 24th"></td>
<td align="center" title="Thursday, March 25th"></td>
<td align="center" title="Friday, March 26th"></td>
<td align="center" title="Saturday, March 27th"></td>
</tr>
<tr>
<td align="center">14: 03/28</td>
<td align="center" title="Sunday, March 28th"></td>
<td align="center" title="Monday, March 29th"></td>
<td align="center" title="Tuesday, March 30th"></td>
<td align="center" title="Wednesday, March 31st"></td>
<td align="center" title="Thursday, April 1st"></td>
<td align="center" title="Friday, April 2nd"></td>
<td align="center" title="Saturday, April 3rd"></td>
</tr>
<tr>
<td align="center">15: 04/04</td>
<td align="center" title="Sunday, April 4th"></td>
<td align="center" title="Monday, April 5th"></td>
<td align="center" title="Tuesday, April 6th"></td>
<td align="center" title="Wednesday, April 7th"></td>
<td align="center" title="Thursday, April 8th"></td>
<td align="center" title="Friday, April 9th"></td>
<td align="center" title="Saturday, April 10th"></td>
</tr>
<tr>
<td align="center">16: 04/11</td>
<td align="center" title="Sunday, April 11th"></td>
<td align="center" title="Monday, April 12th"></td>
<td align="center" title="Tuesday, April 13th"></td>
<td align="center" title="Wednesday, April 14th"></td>
<td align="center" title="Thursday, April 15th"></td>
<td align="center" title="Friday, April 16th"></td>
<td align="center" title="Saturday, April 17th"></td>
</tr>
</tbody>
</table>
</div>

The `Day` struct also has an `href` attribute, which `Calendar` will interpret to make the text a link for the output calendar.

Example:

```python
calendar = Calendar(start_date='12/27/2020', weeks=16)

calendar['2/15/2021'].text = "Assignment 1"
calendar['2/15/2021'].href = "https://www.github.com/"
```

Output calendar HTML:

<div align="center">
<table>
<thead>
<tr>
<th align="center">Week</th>
<th align="center">Sunday</th>
<th align="center">Monday</th>
<th align="center">Tuesday</th>
<th align="center">Wednesday</th>
<th align="center">Thursday</th>
<th align="center">Friday</th>
<th align="center">Saturday</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">01: 12/27</td>
<td align="center" title="Sunday, December 27th"></td>
<td align="center" title="Monday, December 28th"></td>
<td align="center" title="Tuesday, December 29th"></td>
<td align="center" title="Wednesday, December 30th"></td>
<td align="center" title="Thursday, December 31st"></td>
<td align="center" title="Friday, January 1st"></td>
<td align="center" title="Saturday, January 2nd"></td>
</tr>
<tr>
<td align="center">02: 01/03</td>
<td align="center" title="Sunday, January 3rd"></td>
<td align="center" title="Monday, January 4th"></td>
<td align="center" title="Tuesday, January 5th"></td>
<td align="center" title="Wednesday, January 6th"></td>
<td align="center" title="Thursday, January 7th"></td>
<td align="center" title="Friday, January 8th"></td>
<td align="center" title="Saturday, January 9th"></td>
</tr>
<tr>
<td align="center">03: 01/10</td>
<td align="center" title="Sunday, January 10th"></td>
<td align="center" title="Monday, January 11th"></td>
<td align="center" title="Tuesday, January 12th"></td>
<td align="center" title="Wednesday, January 13th"></td>
<td align="center" title="Thursday, January 14th"></td>
<td align="center" title="Friday, January 15th"></td>
<td align="center" title="Saturday, January 16th"></td>
</tr>
<tr>
<td align="center">04: 01/17</td>
<td align="center" title="Sunday, January 17th"></td>
<td align="center" title="Monday, January 18th"></td>
<td align="center" title="Tuesday, January 19th"></td>
<td align="center" title="Wednesday, January 20th"></td>
<td align="center" title="Thursday, January 21st"></td>
<td align="center" title="Friday, January 22nd"></td>
<td align="center" title="Saturday, January 23rd"></td>
</tr>
<tr>
<td align="center">05: 01/24</td>
<td align="center" title="Sunday, January 24th"></td>
<td align="center" title="Monday, January 25th"></td>
<td align="center" title="Tuesday, January 26th"></td>
<td align="center" title="Wednesday, January 27th"></td>
<td align="center" title="Thursday, January 28th"></td>
<td align="center" title="Friday, January 29th"></td>
<td align="center" title="Saturday, January 30th"></td>
</tr>
<tr>
<td align="center">06: 01/31</td>
<td align="center" title="Sunday, January 31st"></td>
<td align="center" title="Monday, February 1st"></td>
<td align="center" title="Tuesday, February 2nd"></td>
<td align="center" title="Wednesday, February 3rd"></td>
<td align="center" title="Thursday, February 4th"></td>
<td align="center" title="Friday, February 5th"></td>
<td align="center" title="Saturday, February 6th"></td>
</tr>
<tr>
<td align="center">07: 02/07</td>
<td align="center" title="Sunday, February 7th"></td>
<td align="center" title="Monday, February 8th"></td>
<td align="center" title="Tuesday, February 9th"></td>
<td align="center" title="Wednesday, February 10th"></td>
<td align="center" title="Thursday, February 11th"></td>
<td align="center" title="Friday, February 12th"></td>
<td align="center" title="Saturday, February 13th"></td>
</tr>
<tr>
<td align="center">08: 02/14</td>
<td align="center" title="Sunday, February 14th"></td>
<td align="center" title="Monday, February 15th"><a href="https://www.github.com/">Assignment 1</a></td>
<td align="center" title="Tuesday, February 16th"></td>
<td align="center" title="Wednesday, February 17th"></td>
<td align="center" title="Thursday, February 18th"></td>
<td align="center" title="Friday, February 19th"></td>
<td align="center" title="Saturday, February 20th"></td>
</tr>
<tr>
<td align="center">09: 02/21</td>
<td align="center" title="Sunday, February 21st"></td>
<td align="center" title="Monday, February 22nd"></td>
<td align="center" title="Tuesday, February 23rd"></td>
<td align="center" title="Wednesday, February 24th"></td>
<td align="center" title="Thursday, February 25th"></td>
<td align="center" title="Friday, February 26th"></td>
<td align="center" title="Saturday, February 27th"></td>
</tr>
<tr>
<td align="center">10: 02/28</td>
<td align="center" title="Sunday, February 28th"></td>
<td align="center" title="Monday, March 1st"></td>
<td align="center" title="Tuesday, March 2nd"></td>
<td align="center" title="Wednesday, March 3rd"></td>
<td align="center" title="Thursday, March 4th"></td>
<td align="center" title="Friday, March 5th"></td>
<td align="center" title="Saturday, March 6th"></td>
</tr>
<tr>
<td align="center">11: 03/07</td>
<td align="center" title="Sunday, March 7th"></td>
<td align="center" title="Monday, March 8th"></td>
<td align="center" title="Tuesday, March 9th"></td>
<td align="center" title="Wednesday, March 10th"></td>
<td align="center" title="Thursday, March 11th"></td>
<td align="center" title="Friday, March 12th"></td>
<td align="center" title="Saturday, March 13th"></td>
</tr>
<tr>
<td align="center">12: 03/14</td>
<td align="center" title="Sunday, March 14th"></td>
<td align="center" title="Monday, March 15th"></td>
<td align="center" title="Tuesday, March 16th"></td>
<td align="center" title="Wednesday, March 17th"></td>
<td align="center" title="Thursday, March 18th"></td>
<td align="center" title="Friday, March 19th"></td>
<td align="center" title="Saturday, March 20th"></td>
</tr>
<tr>
<td align="center">13: 03/21</td>
<td align="center" title="Sunday, March 21st"></td>
<td align="center" title="Monday, March 22nd"></td>
<td align="center" title="Tuesday, March 23rd"></td>
<td align="center" title="Wednesday, March 24th"></td>
<td align="center" title="Thursday, March 25th"></td>
<td align="center" title="Friday, March 26th"></td>
<td align="center" title="Saturday, March 27th"></td>
</tr>
<tr>
<td align="center">14: 03/28</td>
<td align="center" title="Sunday, March 28th"></td>
<td align="center" title="Monday, March 29th"></td>
<td align="center" title="Tuesday, March 30th"></td>
<td align="center" title="Wednesday, March 31st"></td>
<td align="center" title="Thursday, April 1st"></td>
<td align="center" title="Friday, April 2nd"></td>
<td align="center" title="Saturday, April 3rd"></td>
</tr>
<tr>
<td align="center">15: 04/04</td>
<td align="center" title="Sunday, April 4th"></td>
<td align="center" title="Monday, April 5th"></td>
<td align="center" title="Tuesday, April 6th"></td>
<td align="center" title="Wednesday, April 7th"></td>
<td align="center" title="Thursday, April 8th"></td>
<td align="center" title="Friday, April 9th"></td>
<td align="center" title="Saturday, April 10th"></td>
</tr>
<tr>
<td align="center">16: 04/11</td>
<td align="center" title="Sunday, April 11th"></td>
<td align="center" title="Monday, April 12th"></td>
<td align="center" title="Tuesday, April 13th"></td>
<td align="center" title="Wednesday, April 14th"></td>
<td align="center" title="Thursday, April 15th"></td>
<td align="center" title="Friday, April 16th"></td>
<td align="center" title="Saturday, April 17th"></td>
</tr>
</tbody>
</table>
</div>

&nbsp;

### Adding a Series of Events

```python
def set_event_series(self, text_format: str, end: int, every: int, start_date: str, skip_dates: List[str] = [], href_format: str = None, start: int = 1, step: int = 1) -> None:
```

Obviously, setting individual days can be a pain if you have a multitude of assignments to place. This method function can help with that problem.

`text_format` takes a string that should expect one, integer `.format()` argument alike: `"Project {:02d}"`.

`end` is the number of occurrences in the event series to end on. If `text_format="Project {:02d}"` and `end=10`, for example, then `"Project 01"`, `"Project 02"`, ..., `"Project 10"` will be placed onto the calendar.

`every` is the number of days between events in the series. It's often that you'll want weekly assignments, and so you'd provide `every=7`, for example.

`start_date` is a date-string in the format `"%m/%d/%Y"` for which will be the first occurrence of the event series. The rest of the series will begin enumerating from this date.

`skip_dates` is a list of date-strings in the format `"%m/%d/%Y"` to skip during the enumeration.

`href_format` takes a string that should expect one, integer `.format()` argument alike: `"https://www.somewebsite.com/{:02d}/"`. These strings should be URLs, and is convenient if you have links associated with each event enumerated in a parallel manner to the `text_format` argument.

`start` is the first number of the series to begin from. Default is 1.

`step` is the interval between enumerations in the series. Default is 1.

Example:

```python
calendar = Calendar(start_date='12/27/2020', weeks=16)

calendar.set_event_series(
    text_format="Project {:02d}",  # Project XX
    end=11,                        # 1, 2, ..., 11
    every=7,                       # every week
    start_date='1/8/2021',         # from 1/8/2021 (a Friday)
    skip_dates=['2/19/2021']       # skip 2/19/2021
)
```

Output calendar HTML:

<div align="center">
<table>
<thead>
<tr>
<th align="center">Week</th>
<th align="center">Sunday</th>
<th align="center">Monday</th>
<th align="center">Tuesday</th>
<th align="center">Wednesday</th>
<th align="center">Thursday</th>
<th align="center">Friday</th>
<th align="center">Saturday</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">01: 12/27</td>
<td align="center" title="Sunday, December 27th"></td>
<td align="center" title="Monday, December 28th"></td>
<td align="center" title="Tuesday, December 29th"></td>
<td align="center" title="Wednesday, December 30th"></td>
<td align="center" title="Thursday, December 31st"></td>
<td align="center" title="Friday, January 1st"></td>
<td align="center" title="Saturday, January 2nd"></td>
</tr>
<tr>
<td align="center">02: 01/03</td>
<td align="center" title="Sunday, January 3rd"></td>
<td align="center" title="Monday, January 4th"></td>
<td align="center" title="Tuesday, January 5th"></td>
<td align="center" title="Wednesday, January 6th"></td>
<td align="center" title="Thursday, January 7th"></td>
<td align="center" title="Friday, January 8th">Project 01</td>
<td align="center" title="Saturday, January 9th"></td>
</tr>
<tr>
<td align="center">03: 01/10</td>
<td align="center" title="Sunday, January 10th"></td>
<td align="center" title="Monday, January 11th"></td>
<td align="center" title="Tuesday, January 12th"></td>
<td align="center" title="Wednesday, January 13th"></td>
<td align="center" title="Thursday, January 14th"></td>
<td align="center" title="Friday, January 15th">Project 02</td>
<td align="center" title="Saturday, January 16th"></td>
</tr>
<tr>
<td align="center">04: 01/17</td>
<td align="center" title="Sunday, January 17th"></td>
<td align="center" title="Monday, January 18th"></td>
<td align="center" title="Tuesday, January 19th"></td>
<td align="center" title="Wednesday, January 20th"></td>
<td align="center" title="Thursday, January 21st"></td>
<td align="center" title="Friday, January 22nd">Project 03</td>
<td align="center" title="Saturday, January 23rd"></td>
</tr>
<tr>
<td align="center">05: 01/24</td>
<td align="center" title="Sunday, January 24th"></td>
<td align="center" title="Monday, January 25th"></td>
<td align="center" title="Tuesday, January 26th"></td>
<td align="center" title="Wednesday, January 27th"></td>
<td align="center" title="Thursday, January 28th"></td>
<td align="center" title="Friday, January 29th">Project 04</td>
<td align="center" title="Saturday, January 30th"></td>
</tr>
<tr>
<td align="center">06: 01/31</td>
<td align="center" title="Sunday, January 31st"></td>
<td align="center" title="Monday, February 1st"></td>
<td align="center" title="Tuesday, February 2nd"></td>
<td align="center" title="Wednesday, February 3rd"></td>
<td align="center" title="Thursday, February 4th"></td>
<td align="center" title="Friday, February 5th">Project 05</td>
<td align="center" title="Saturday, February 6th"></td>
</tr>
<tr>
<td align="center">07: 02/07</td>
<td align="center" title="Sunday, February 7th"></td>
<td align="center" title="Monday, February 8th"></td>
<td align="center" title="Tuesday, February 9th"></td>
<td align="center" title="Wednesday, February 10th"></td>
<td align="center" title="Thursday, February 11th"></td>
<td align="center" title="Friday, February 12th">Project 06</td>
<td align="center" title="Saturday, February 13th"></td>
</tr>
<tr>
<td align="center">08: 02/14</td>
<td align="center" title="Sunday, February 14th"></td>
<td align="center" title="Monday, February 15th"></td>
<td align="center" title="Tuesday, February 16th"></td>
<td align="center" title="Wednesday, February 17th"></td>
<td align="center" title="Thursday, February 18th"></td>
<td align="center" title="Friday, February 19th"></td>
<td align="center" title="Saturday, February 20th"></td>
</tr>
<tr>
<td align="center">09: 02/21</td>
<td align="center" title="Sunday, February 21st"></td>
<td align="center" title="Monday, February 22nd"></td>
<td align="center" title="Tuesday, February 23rd"></td>
<td align="center" title="Wednesday, February 24th"></td>
<td align="center" title="Thursday, February 25th"></td>
<td align="center" title="Friday, February 26th">Project 07</td>
<td align="center" title="Saturday, February 27th"></td>
</tr>
<tr>
<td align="center">10: 02/28</td>
<td align="center" title="Sunday, February 28th"></td>
<td align="center" title="Monday, March 1st"></td>
<td align="center" title="Tuesday, March 2nd"></td>
<td align="center" title="Wednesday, March 3rd"></td>
<td align="center" title="Thursday, March 4th"></td>
<td align="center" title="Friday, March 5th">Project 08</td>
<td align="center" title="Saturday, March 6th"></td>
</tr>
<tr>
<td align="center">11: 03/07</td>
<td align="center" title="Sunday, March 7th"></td>
<td align="center" title="Monday, March 8th"></td>
<td align="center" title="Tuesday, March 9th"></td>
<td align="center" title="Wednesday, March 10th"></td>
<td align="center" title="Thursday, March 11th"></td>
<td align="center" title="Friday, March 12th">Project 09</td>
<td align="center" title="Saturday, March 13th"></td>
</tr>
<tr>
<td align="center">12: 03/14</td>
<td align="center" title="Sunday, March 14th"></td>
<td align="center" title="Monday, March 15th"></td>
<td align="center" title="Tuesday, March 16th"></td>
<td align="center" title="Wednesday, March 17th"></td>
<td align="center" title="Thursday, March 18th"></td>
<td align="center" title="Friday, March 19th">Project 10</td>
<td align="center" title="Saturday, March 20th"></td>
</tr>
<tr>
<td align="center">13: 03/21</td>
<td align="center" title="Sunday, March 21st"></td>
<td align="center" title="Monday, March 22nd"></td>
<td align="center" title="Tuesday, March 23rd"></td>
<td align="center" title="Wednesday, March 24th"></td>
<td align="center" title="Thursday, March 25th"></td>
<td align="center" title="Friday, March 26th">Project 11</td>
<td align="center" title="Saturday, March 27th"></td>
</tr>
<tr>
<td align="center">14: 03/28</td>
<td align="center" title="Sunday, March 28th"></td>
<td align="center" title="Monday, March 29th"></td>
<td align="center" title="Tuesday, March 30th"></td>
<td align="center" title="Wednesday, March 31st"></td>
<td align="center" title="Thursday, April 1st"></td>
<td align="center" title="Friday, April 2nd"></td>
<td align="center" title="Saturday, April 3rd"></td>
</tr>
<tr>
<td align="center">15: 04/04</td>
<td align="center" title="Sunday, April 4th"></td>
<td align="center" title="Monday, April 5th"></td>
<td align="center" title="Tuesday, April 6th"></td>
<td align="center" title="Wednesday, April 7th"></td>
<td align="center" title="Thursday, April 8th"></td>
<td align="center" title="Friday, April 9th"></td>
<td align="center" title="Saturday, April 10th"></td>
</tr>
<tr>
<td align="center">16: 04/11</td>
<td align="center" title="Sunday, April 11th"></td>
<td align="center" title="Monday, April 12th"></td>
<td align="center" title="Tuesday, April 13th"></td>
<td align="center" title="Wednesday, April 14th"></td>
<td align="center" title="Thursday, April 15th"></td>
<td align="center" title="Friday, April 16th"></td>
<td align="center" title="Saturday, April 17th"></td>
</tr>
</tbody>
</table>
</div>

&nbsp;

### Comitting

Comitting to the repository is fairly straightforward once you've filled out your desired calendar at the bottom of update_readme.py. Simply run the script, and you're done! The master README file will be changed with your updates to the `calendar` variable.

If you go to see the changes, and made some sort of mistake on the output calendar, you can discard your changes in whatever git manager you're using, and re-write your calendar logic as necessary. Simply run the script again until you end up with your desired calendar.
