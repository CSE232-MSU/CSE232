---
title: Home
---

# CSE 232 - Introduction to Programming II

Continuation of object-centered design and implementation in C++. Building programs from modules. Data abstractions and classes to implement abstract data types. Static and dynamic memory allocation. Data structure implementation and algorithm efficiency. Lists, tables, stacks, and queues. Templates and generic programming.

General:
- [Course Schedule](#course-schedule)
- [Exam Policies](exam_policies.html)
- [Help Room Schedule](#help-room-schedule)
- [Syllabus](syllabus.html)

Essential Sites:
- [D2L](https://d2l.msu.edu/d2l/loginh/)
- [Coding Rooms](coding_rooms_setup.html)
- [Piazza](https://piazza.com/msu/fall2022/cse232/home)

Resources:
- [cppreference](https://en.cppreference.com/w/)
- [105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=2olsGf6JIkU)
- [Debugging Guide](debugging_guide.html)
- [OnlineGDB](https://www.onlinegdb.com/)
- [STL Algorithms (and Rest of C++) Cheatsheet](https://hackingcpp.com/cpp/cheat_sheets.html)
- [Unix Tutorial](https://www.tutorialspoint.com/unix/index.htm)
- [C++ Formatter](http://format.krzaq.cc/) (Use the Google Style)
- [Google Style Guide](https://google.github.io/styleguide/cppguide.html)

## Course Schedule

It should be assumed that all assignments are due by 10:00 PM ET on their respective due dates. Due dates are subject to change, but if a change is made, an announcement will be posted to Piazza.

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
            <td>2022-08-29</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week00.html">Week 00</a></td>
            <td>No Lab This Week</td>
            <td>No Monday Homework</td>
            <td>No Thursday Homework</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-09-05</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week01.html">Week 01</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab01.html">Lab 01</a></td>
            <td>Homework 00 (not worth any points)</td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>2022-09-12</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week02.html">Week 02</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab02.html">Lab 02</a></td>
            <td>Homework 01</td>
            <td>Homework 02</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-09-19</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week03.html">Week 03</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab03.html">Lab 03</a></td>
            <td>Homework 03</td>
            <td>Homework 04</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-09-26</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week04.html">Week 04</a></td>
            <td><a href="https://cse232-msu.github.io/CSE232/labs/lab04.html">Lab 04</a></td>
            <td>Homework 05</td>
            <td>Homework 06</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-10-03</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week05.html">Week 05</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab05.html">Lab 05</a></td> -->
            <td>Lab 05</td> 
            <td>Homework 07</td>
            <td>Homework 08</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-10-10</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week06.html">Week 06</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab06.html">Lab 06</a></td> -->
            <td>Lab 06</td> 
            <td></td>
            <td>Project 01 Due</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-10-17</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week07.html">Week 07</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab07.html">Lab 07</a></td> -->
            <td>Lab 07</td> 
            <td>Homework 09</td>
            <td>Homework 10</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-10-24</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week08.html">Week 08</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab08.html">Lab 08</a></td> -->
            <td>Lab 08</td> 
            <td>No Homework (Break Days)</td>
            <td>Homework 11</td>
            <td>Due to the Break Days, Tuesday Labs will complete this lab during the week of Thanksgiving. No Tuesday Labs this week. The asynchronous lab will be due the week of Thanksgiving.</td>
        </tr>
        <tr>
            <td>2022-10-31</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week09.html">Week 09</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab09.html">Lab 09</a></td> -->
            <td>Lab 09</td> 
            <td>Homework 12</td>
            <td></td>
            <td>Midterm Exam: see <a href="https://cse232-msu.github.io/CSE232/exam_policies.html">Exam Policies</a> for details.</td>
        </tr>
        <tr>
            <td>2022-11-07</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week10.html">Week 10</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab10.html">Lab 10</a></td> -->
            <td>Lab 10</td> 
            <td></td>
            <td>Project 02 Due</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-11-14</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week11.html">Week 11</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab11.html">Lab 11</a></td> -->
            <td>Lab 11</td> 
            <td>Homework 13</td>
            <td>Homework 14</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-11-21</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week12.html">Week 12</a></td>
            <td>See Lab 08 from Week 08</td>
            <td>Homework 15</td>
            <td>No Homework (Thanksgiving Break)</td>
            <td>Tuesday Labs will complete Lab 08 this week. Asynchronous Lab 08s are also due this week on Wednesday. No Thursday or Friday Labs.</td>      
        </tr>
        <tr>
            <td>2022-11-28</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week13.html">Week 13</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab12.html">Lab 12</a></td> -->
            <td>Lab 12</td> 
            <td>Homework 16</td>
            <td>Homework 17</td>
            <td></td>  
        </tr>
        <tr>
            <td>2022-12-05</td>
            <td><a href="https://cse232-msu.github.io/CSE232/lectures/week14.html">Week 14</a></td>
<!--             <td><a href="https://cse232-msu.github.io/CSE232/labs/lab13.html">Lab 13</a></td> -->
            <td>Lab 13</td> 
            <td>Homework 18</td>
            <td>Project 03 Due</td>
            <td></td>
        </tr>
        <tr>
            <td>2022-12-12 Finals Week</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td>Final Exam: see <a href="https://cse232-msu.github.io/CSE232/exam_policies.html">Exam Policies</a> for details.</td>
        </tr>
    </tbody>
</table>


## Help Room Schedule

Help Room is conducted through Zoom. You can find the link to the meeting on Piazza. Help Room will begin on 2022-09-06 (Tuesday).

Please be aware that you may not receive the attention you desire if you attend help room very near an assignment deadline. So please consider attending help room prior to the day an assignment is due as there will be less demand. 

Please direct any and all written communication to Piazza (you can post anonymously if that's something you'd prefer). Emails may not be responded to.

If you would like a one-on-one meeting with an instructor, please make a private Piazza post detailing your request and availability.
