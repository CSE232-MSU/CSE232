# CSE232 - Introduction to Programming II

Continuation of object-centered design and implementation in C++. Building programs from modules. Data abstractions and classes to implement abstract data types. Static and dynamic memory allocation. Data structure implementation and algorithm efficiency. Lists, tables, stacks, and queues. Templates and generic programming.

General:
- [Announcements](#announcements)
- [Course Schedule](#course-schedule)
- [Help Room Schedule](#help-room-schedule)
- [Past Exams](https://cse.msu.edu/~cse232/Exam_Content/)
- [Section Instructors]()
- [Syllabus](SYLLABUS.md)

Essential Sites:
- [D2L](https://d2l.msu.edu/d2l/loginh/)
- [Mimir](https://class.mimir.io/)
- [Piazza]()

Resources:
- [STL Algorithms Cheatsheet](https://medium.com/logicalbee/c-stl-algorithms-cheat-sheet-d92f986abe14)
- [cplusplus](https://cplusplus.com/reference/)
- [cppreference](https://en.cppreference.com/w/)
- [OnlineGDB](https://www.onlinegdb.com/)
- [UNIX Tutorial](https://www.tutorialspoint.com/unix/index.htm)
- [105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=2olsGf6JIkU)

## Announcements

Posted: 1/10/20

<blockquote>
<p>Welcome to CSE232! 🎉</p>
<p>Please go through <a href="Labs/lab00.md">Lab 00</a> to get started with the course. It'll have you set up Mimir, Visual Studio Code, and a C++ compiler. We expect that you'll have all of these resources available by your first class meeting.</p>
<p>— Braedyn Lettinga</p>
</blockquote>

## Course Schedule

It should be assumed that all assignments are due by 10:00 PM EST on their respective due dates. Due dates are subject to change, but if a change is made, an announcement will be made on Piazza.

Links to lecture videos, projects, and other materials will be made available as relevant dates approach. Content that is written for future weeks may change without notice until the date arrives.

You can hover over a calendar cell to see its precise date (sorry mobile users).

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
<td align="center">00: 01/10</td>
<td align="center" title="Sunday, January 10th 2021 (01/10/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2000">Week 00 Lectures</a></td>
<td align="center" title="Monday, January 11th 2021 (01/11/2021)"></td>
<td align="center" title="Tuesday, January 12th 2021 (01/12/2021)"></td>
<td align="center" title="Wednesday, January 13th 2021 (01/13/2021)"></td>
<td align="center" title="Thursday, January 14th 2021 (01/14/2021)"></td>
<td align="center" title="Friday, January 15th 2021 (01/15/2021)"></td>
<td align="center" title="Saturday, January 16th 2021 (01/16/2021)"></td>
</tr>
<tr>
<td align="center">01: 01/17</td>
<td align="center" title="Sunday, January 17th 2021 (01/17/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2001">Week 01 Lectures</a></td>
<td align="center" title="Monday, January 18th 2021 (01/18/2021)"></td>
<td align="center" title="Tuesday, January 19th 2021 (01/19/2021)"></td>
<td align="center" title="Wednesday, January 20th 2021 (01/20/2021)"></td>
<td align="center" title="Thursday, January 21st 2021 (01/21/2021)"></td>
<td align="center" title="Friday, January 22nd 2021 (01/22/2021)"></td>
<td align="center" title="Saturday, January 23rd 2021 (01/23/2021)"></td>
</tr>
<tr>
<td align="center">02: 01/24</td>
<td align="center" title="Sunday, January 24th 2021 (01/24/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2002">Week 02 Lectures</a></td>
<td align="center" title="Monday, January 25th 2021 (01/25/2021)"></td>
<td align="center" title="Tuesday, January 26th 2021 (01/26/2021)"></td>
<td align="center" title="Wednesday, January 27th 2021 (01/27/2021)"></td>
<td align="center" title="Thursday, January 28th 2021 (01/28/2021)"></td>
<td align="center" title="Friday, January 29th 2021 (01/29/2021)"></td>
<td align="center" title="Saturday, January 30th 2021 (01/30/2021)"></td>
</tr>
<tr>
<td align="center">03: 01/31</td>
<td align="center" title="Sunday, January 31st 2021 (01/31/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2003">Week 03 Lectures</a></td>
<td align="center" title="Monday, February 1st 2021 (02/01/2021)"></td>
<td align="center" title="Tuesday, February 2nd 2021 (02/02/2021)"></td>
<td align="center" title="Wednesday, February 3rd 2021 (02/03/2021)"></td>
<td align="center" title="Thursday, February 4th 2021 (02/04/2021)"></td>
<td align="center" title="Friday, February 5th 2021 (02/05/2021)"></td>
<td align="center" title="Saturday, February 6th 2021 (02/06/2021)"></td>
</tr>
<tr>
<td align="center">04: 02/07</td>
<td align="center" title="Sunday, February 7th 2021 (02/07/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2004">Week 04 Lectures</a></td>
<td align="center" title="Monday, February 8th 2021 (02/08/2021)"></td>
<td align="center" title="Tuesday, February 9th 2021 (02/09/2021)"></td>
<td align="center" title="Wednesday, February 10th 2021 (02/10/2021)"></td>
<td align="center" title="Thursday, February 11th 2021 (02/11/2021)"></td>
<td align="center" title="Friday, February 12th 2021 (02/12/2021)"></td>
<td align="center" title="Saturday, February 13th 2021 (02/13/2021)"></td>
</tr>
<tr>
<td align="center">05: 02/14</td>
<td align="center" title="Sunday, February 14th 2021 (02/14/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2005">Week 05 Lectures</a></td>
<td align="center" title="Monday, February 15th 2021 (02/15/2021)"></td>
<td align="center" title="Tuesday, February 16th 2021 (02/16/2021)"></td>
<td align="center" title="Wednesday, February 17th 2021 (02/17/2021)"></td>
<td align="center" title="Thursday, February 18th 2021 (02/18/2021)"></td>
<td align="center" title="Friday, February 19th 2021 (02/19/2021)"></td>
<td align="center" title="Saturday, February 20th 2021 (02/20/2021)"></td>
</tr>
<tr>
<td align="center">06: 02/21</td>
<td align="center" title="Sunday, February 21st 2021 (02/21/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2006">Week 06 Lectures</a></td>
<td align="center" title="Monday, February 22nd 2021 (02/22/2021)"></td>
<td align="center" title="Tuesday, February 23rd 2021 (02/23/2021)"></td>
<td align="center" title="Wednesday, February 24th 2021 (02/24/2021)"></td>
<td align="center" title="Thursday, February 25th 2021 (02/25/2021)"></td>
<td align="center" title="Friday, February 26th 2021 (02/26/2021)"></td>
<td align="center" title="Saturday, February 27th 2021 (02/27/2021)"></td>
</tr>
<tr>
<td align="center">07: 02/28</td>
<td align="center" title="Sunday, February 28th 2021 (02/28/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2007">Week 07 Lectures</a></td>
<td align="center" title="Monday, March 1st 2021 (03/01/2021)"></td>
<td align="center" title="Tuesday, March 2nd 2021 (03/02/2021)"></td>
<td align="center" title="Wednesday, March 3rd 2021 (03/03/2021)"></td>
<td align="center" title="Thursday, March 4th 2021 (03/04/2021)"></td>
<td align="center" title="Friday, March 5th 2021 (03/05/2021)"></td>
<td align="center" title="Saturday, March 6th 2021 (03/06/2021)"></td>
</tr>
<tr>
<td align="center">08: 03/07</td>
<td align="center" title="Sunday, March 7th 2021 (03/07/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2008">Week 08 Lectures</a></td>
<td align="center" title="Monday, March 8th 2021 (03/08/2021)"></td>
<td align="center" title="Tuesday, March 9th 2021 (03/09/2021)"></td>
<td align="center" title="Wednesday, March 10th 2021 (03/10/2021)"></td>
<td align="center" title="Thursday, March 11th 2021 (03/11/2021)"></td>
<td align="center" title="Friday, March 12th 2021 (03/12/2021)"></td>
<td align="center" title="Saturday, March 13th 2021 (03/13/2021)"></td>
</tr>
<tr>
<td align="center">09: 03/14</td>
<td align="center" title="Sunday, March 14th 2021 (03/14/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2009">Week 09 Lectures</a></td>
<td align="center" title="Monday, March 15th 2021 (03/15/2021)"></td>
<td align="center" title="Tuesday, March 16th 2021 (03/16/2021)"></td>
<td align="center" title="Wednesday, March 17th 2021 (03/17/2021)"></td>
<td align="center" title="Thursday, March 18th 2021 (03/18/2021)"></td>
<td align="center" title="Friday, March 19th 2021 (03/19/2021)"></td>
<td align="center" title="Saturday, March 20th 2021 (03/20/2021)"></td>
</tr>
<tr>
<td align="center">10: 03/21</td>
<td align="center" title="Sunday, March 21st 2021 (03/21/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2010">Week 10 Lectures</a></td>
<td align="center" title="Monday, March 22nd 2021 (03/22/2021)"></td>
<td align="center" title="Tuesday, March 23rd 2021 (03/23/2021)"></td>
<td align="center" title="Wednesday, March 24th 2021 (03/24/2021)"></td>
<td align="center" title="Thursday, March 25th 2021 (03/25/2021)"></td>
<td align="center" title="Friday, March 26th 2021 (03/26/2021)"></td>
<td align="center" title="Saturday, March 27th 2021 (03/27/2021)"></td>
</tr>
<tr>
<td align="center">11: 03/28</td>
<td align="center" title="Sunday, March 28th 2021 (03/28/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2011">Week 11 Lectures</a></td>
<td align="center" title="Monday, March 29th 2021 (03/29/2021)"></td>
<td align="center" title="Tuesday, March 30th 2021 (03/30/2021)"></td>
<td align="center" title="Wednesday, March 31st 2021 (03/31/2021)"></td>
<td align="center" title="Thursday, April 1st 2021 (04/01/2021)"></td>
<td align="center" title="Friday, April 2nd 2021 (04/02/2021)"></td>
<td align="center" title="Saturday, April 3rd 2021 (04/03/2021)"></td>
</tr>
<tr>
<td align="center">12: 04/04</td>
<td align="center" title="Sunday, April 4th 2021 (04/04/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2012">Week 12 Lectures</a></td>
<td align="center" title="Monday, April 5th 2021 (04/05/2021)"></td>
<td align="center" title="Tuesday, April 6th 2021 (04/06/2021)"></td>
<td align="center" title="Wednesday, April 7th 2021 (04/07/2021)"></td>
<td align="center" title="Thursday, April 8th 2021 (04/08/2021)"></td>
<td align="center" title="Friday, April 9th 2021 (04/09/2021)"></td>
<td align="center" title="Saturday, April 10th 2021 (04/10/2021)"></td>
</tr>
<tr>
<td align="center">13: 04/11</td>
<td align="center" title="Sunday, April 11th 2021 (04/11/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2013">Week 13 Lectures</a></td>
<td align="center" title="Monday, April 12th 2021 (04/12/2021)"></td>
<td align="center" title="Tuesday, April 13th 2021 (04/13/2021)"></td>
<td align="center" title="Wednesday, April 14th 2021 (04/14/2021)"></td>
<td align="center" title="Thursday, April 15th 2021 (04/15/2021)"></td>
<td align="center" title="Friday, April 16th 2021 (04/16/2021)"></td>
<td align="center" title="Saturday, April 17th 2021 (04/17/2021)"></td>
</tr>
<tr>
<td align="center">14: 04/18</td>
<td align="center" title="Sunday, April 18th 2021 (04/18/2021)"><a href="https://github.com/braedynl/CSE232/tree/main/Lectures/Week%2014">Week 14 Lectures</a></td>
<td align="center" title="Monday, April 19th 2021 (04/19/2021)"></td>
<td align="center" title="Tuesday, April 20th 2021 (04/20/2021)"></td>
<td align="center" title="Wednesday, April 21st 2021 (04/21/2021)"></td>
<td align="center" title="Thursday, April 22nd 2021 (04/22/2021)"></td>
<td align="center" title="Friday, April 23rd 2021 (04/23/2021)"></td>
<td align="center" title="Saturday, April 24th 2021 (04/24/2021)"></td>
</tr>
<tr>
<td align="center">15: 04/25</td>
<td align="center" title="Sunday, April 25th 2021 (04/25/2021)"></td>
<td align="center" title="Monday, April 26th 2021 (04/26/2021)"></td>
<td align="center" title="Tuesday, April 27th 2021 (04/27/2021)"></td>
<td align="center" title="Wednesday, April 28th 2021 (04/28/2021)"></td>
<td align="center" title="Thursday, April 29th 2021 (04/29/2021)"></td>
<td align="center" title="Friday, April 30th 2021 (04/30/2021)"></td>
<td align="center" title="Saturday, May 1st 2021 (05/01/2021)"></td>
</tr>
</tbody>
</table>
</div>


## Help Room Schedule

Help Room is conducted through Zoom. You can find the session details and instructions on how to join on Piazza.

Please direct any and all written communication to Piazza (you can post anonymously if that's something you'd prefer). Emails may not be responded to.

If you would like a one-on-one meeting with an instructor, please make a private Piazza post detailing your request and availability.

| Sunday | Monday | Tuesday | Wednesday | Thursday | Friday | Saturday |
| :---:  | :---:  | :---:   | :---:     | :---:    | :---:  | :---:    |
||09:00-11:00AM|09:00-11:00AM|09:00-11:00AM|09:00-11:00AM|09:00-11:00AM|
||03:00-05:00PM|03:00-05:00PM|03:00-05:00PM|03:00-05:00PM|||
|07:00-09:00PM|07:00-09:00PM|07:00-09:00PM|07:00-09:00PM|07:00-09:00PM|07:00-09:00PM|07:00-09:00PM|

___

<div align="center">
    <p>© Michigan State University</p>
</div>
