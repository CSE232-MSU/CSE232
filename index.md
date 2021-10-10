---
title: Home
---

# CSE232 - Introduction to Programming II

Continuation of object-centered design and implementation in C++. Building programs from modules. Data abstractions and classes to implement abstract data types. Static and dynamic memory allocation. Data structure implementation and algorithm efficiency. Lists, tables, stacks, and queues. Templates and generic programming.

General:
- [Course Schedule](#course-schedule)
- [Exam Policies](exam_policies.html)
- [Help Room Schedule](#help-room-schedule)
- [Syllabus](syllabus.html)

Essential Sites:
- [D2L](https://d2l.msu.edu/d2l/loginh/)
- [Mimir](https://class.mimir.io/)
- [Piazza](https://piazza.com/class/kst3lbwi2ay3so)

Resources:
- [cppreference](https://en.cppreference.com/w/)
- [105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=2olsGf6JIkU)
- [Debugging Guide](debugging_guide.html)
- [OnlineGDB](https://www.onlinegdb.com/)
- [STL Algorithms Cheatsheet](https://medium.com/logicalbee/c-stl-algorithms-cheat-sheet-d92f986abe14)
- [Unix Tutorial](https://www.tutorialspoint.com/unix/index.htm)
- [C++ Formatter](http://format.krzaq.cc/) (Use the Google Style)
- [Google Style Guide](https://google.github.io/styleguide/cppguide.html)

## Course Schedule

It should be assumed that all assignments are due by 10:00 PM EST on their respective due dates. Due dates are subject to change, but if a change is made, an announcement will be made on Piazza.

Links to lecture videos, projects, and other materials will be made available as relevant dates approach. Content that is written for future weeks may change without notice until the date arrives.


<!-- [Add to Google Calendar](https://calendar.google.com/calendar/u/0?cid=anFtcGxzdGcwczFqa2FnZDV1dWZldmxqMmNAZ3JvdXAuY2FsZW5kYXIuZ29vZ2xlLmNvbQ) -->

<div align="center">
    <p id="course-progress-header"></p>
    <span class="Progress" id="course-progress-container">
        <span class="Progress-item color-bg-success-emphasis" id="course-progress"></span>
    </span>
</div>

&nbsp;

<table id="course-calendar">
    <thead>
        <tr>
            <th>Week</th>
            <th>Lectures</th>
            <th>Labs</th>
            <th>Due on Monday</th>
            <th>Due on Thursday</th>
            <th>Notes</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>00: 2021-08-30</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week00.html">Week 00</a></td>
            <td>No Lab This Week</td>
            <td></td>
            <td></td>
            <td>No Assignments are due this week (no lab or help room either).</td>
        </tr>
        <tr>
            <td>01: 2021-09-06</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week01.html">Week 01</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab01.html">Lab 01</a></td>
            <td>Homework 00 (not worth any points)</td>
            <td>Homework 01</td>
            <td>University Holiday on Monday.</td>
        </tr>
        <tr>
            <td>02: 2021-09-13</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week02.html">Week 02</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab02.html">Lab 02</a></td>
            <td>Homework 02</td>
            <td>Homework 03</td>
            <td></td>
        </tr>
        <tr>
            <td>03: 2021-09-20</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week03.html">Week 03</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab03.html">Lab 03</a></td>
            <td>Homework 04</td>
            <td>Homework 05</td>
            <td></td>
        </tr>
        <tr>
            <td>04: 2021-09-27</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week04.html">Week 04</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab04.html">Lab 04</a></td>
            <td>Homework 06</td>
            <td>Homework 07</td>
            <td></td>
        </tr>
        <tr>
            <td>05: 2021-10-04</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week05.html">Week 05</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab05.html">Lab 05</a></td>
            <td>Homework 08</td>
            <td>Homework 09</td>
            <td></td>
        </tr>
        <tr>
            <td>06: 2021-10-11</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week06.html">Week 06</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab06.html">Lab 06</a></td>
            <td>Homework 10</td>
            <td>Project 01 Due (no homework)</td>
            <td></td>
        </tr>
        <tr>
            <td>07: 2021-10-18</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week07.html">Week 07</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab07.html">Lab 07</a></td>
            <td>Homework 11</td>
            <td>Homework 12</td>
            <td></td>
        </tr>
        <tr>
            <td>08: 2021-10-25</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week08.html">Week 08</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab08.html">Lab 08</a></td>
            <td>No Monday Homework</td>
            <td>Homework 13</td>
            <td>Monday and Tuesday are Break Days. No Tuesday Labs.</td>
        </tr>
        <tr>
            <td>09: 2021-11-01</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week09.html">Week 09</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab09.html">Lab 09</a></td>
            <td>Homework 14</td>
            <td>Homework 15</td>
            <td>Midterm exam either Tuesday evening or Wednesday morning, see <a href="https://cse232-msu.github.io/CSE232/exam_policies.html">Exam Policies</a> for details.</td>
        </tr>
        <tr>
            <td>10: 2021-11-08</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week10.html">Week 10</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab10.html">Lab 10</a></td>
            <td>Homework 16</td>
            <td>Project 02 Due (no homework)</td>
            <td></td>
        </tr>
        <tr>
            <td>11: 2021-11-15</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week11.html">Week 11</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab11.html">Lab 11</a></td>
            <td>Homework 17</td>
            <td>Homework 18</td>
            <td></td>      
        </tr>
        <tr>
            <td>12: 2021-11-22</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week12.html">Week 12</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab12.html">Lab 12</a></td>
            <td>Homework 19</td>
            <td>Homework 20</td>
            <td>University Holiday on Thursday and Friday. No Thursday or Friday Labs.</td>  
        </tr>
        <tr>
            <td>13: 2021-11-29</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week13.html">Week 13</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab13.html">Lab 13</a></td>
            <td>Homework 21</td>
            <td>Project 03 (no homework)</td>
            <td></td>
        </tr>
        <tr>
            <td>14: 2021-12-06</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week14.html">Week 14</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab14.html">Lab 14</a></td>
            <td>Homework 22</td>
            <td>???</td>
            <td>Final Exam either Tuesday evening or Wednesday morning. See <a href="https://cse232-msu.github.io/CSE232/exam_policies.html">Exam Policies</a> for details.</td>
        </tr>
    </tbody>
</table>


## Help Room Schedule

Help Room is conducted through Zoom. You can find the link to the meeting on Piazza.

<!-- <table id="hr-schedule">
    <thead>
        <tr>
            <th>Sunday</th>
            <th>Monday</th>
            <th>Tuesday</th>
            <th>Wednesday</th>
            <th>Thursday</th>
            <th>Friday</th>
            <th>Saturday</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td></td>
            <td>9-11am</td>
            <td>9-11am</td>
            <td>9-11am</td>
            <td>9-11am</td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>5-7pm</td>
            <td>5-9pm</td>
            <td>5-7pm</td>
            <td>5-7pm</td>
            <td>5-9pm</td>
            <td>5-7pm</td>
            <td>5-7pm</td>
        </tr>
    </tbody>
</table> -->

Please be aware that you may not receive the attention you desire if you attend help room very near an assignment deadline. So please consider attending help room prior to the day an assignment is due as there will be less demand. 

Please direct any and all written communication to Piazza (you can post anonymously if that's something you'd prefer). Emails may not be responded to.

If you would like a one-on-one meeting with an instructor, please make a private Piazza post detailing your request and availability.
