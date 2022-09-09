---
title: Lab - Getting Started
---

# Lab - Getting Started

This lab is designed to get you acquainted with the class resources and recommended code editor.

## Class Resources

Course Website: <https://cse232-msu.github.io/CSE232/>

Piazza: <https://piazza.com>

Coding Rooms: <https://app.codingrooms.com/app/>


Please ensure that you can access all of the CSE232 resources listed here.


## Writing in C++

For this class, we recommend using Visual Studio Code (or VSCode). **You are free to use other code editors, but, you are responsible for knowing how to work with it**. 

[We have thoroughly-documented tutorials on how to setup a C++ VSCode environment, with an active debugger as well.](../vscode_setup.html)

Please come back to this page when you have VSCode ready to go.

### Code Editors

- [Visual Studio Code](https://code.visualstudio.com/) is a modern programmer's editor. It is free, flexible, and can be used cross-platform. Plug-ins allow for almost any language support or feature that you might need.  If you want to be a programmer, this is a good one to learn.
- [Xcode](https://developer.apple.com/xcode/) is another, very modern code editor that is exclusive to MacOS. It is a powerful, high-end programming environment, but can have a steep learning curve for people new to it.
- [Emacs](https://www.gnu.org/software/emacs/) is a very old, very configurable, editor that can run on a command line. Developers have regularly added new features to emacs for decades, leading to the joke that emacs is an operating system disguised as an editor.
- [Vim](https://www.vim.org/download.php) is also very old, but comes as standard in many Linux operating systems as a default editor. You shouldn't start here, but learning the basics of Vim is something every programmer should do.
- [Notepad++](https://notepad-plus-plus.org/) is a Windows file editor. It is not very configurable but does a good job at just being an editor. If all else fails, Notepad++ is a good fallback editor on a Windows machine.

Many other editors exist that you can also use if you feel more comfortable with them, though with any other that VSCode we will not be able to help you if you run into problems.


## Working with C++

### About C++

From Wikipedia:

> C++ is a general-purpose programming language. It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.

Languages come in various "levels", from "low" (meaning very close to the CPU they might run on) to "high" (meaning very far from the CPU they might run on). Python is a great example of a high-level language. Assembly languages are low-level languages that let you directly control the CPU of a machine.  C++ is an intermediate language; it doesn't give you all the help you would receive from Python, but it does allow you to have more control over the machine that it is running on while still being easier to understand and work with than assembly languages.

It is important to remember that C++ is a compiled language. That means that you must pass your code through another piece of software, called a **compiler**, that translates your C++ into (nearly) machine-ready code. Note that Python has no compilation requirement; instead there is an **interpreter** available for running Python code whenever you need it.

The greatest strength of C++ is its potential for creating efficient executables and robust libraries. A programmer can control low-level aspects of how data is stored, how information is passed, and how memory is managed. When used wisely, this control can lead to a more streamlined result; a well-written C++ program is typically somewhere between 10 and 100 times faster than the equivalent Python program.  In this course you will learn proper C++ techniques to build effective programs. You, the programmer, will be responsible for most aspects of how your code runs giving you substantial power. This is a double-edged sword, as being responsible gives you more opportunities to screw up.

One of the problems with C++ is that parts of the syntax have grown cryptic. There may be *many* ways of expressing the same thing. An experienced and knowledgeable developer can use this flexibility to pick the best alternative and improve the result. Yet, both novice and experienced programmers can easily choose the wrong alternative, leading to less-efficient, and possibly flawed, software. You will need to be careful, but you will learn rules and guidelines to help you make the right decisions.

### Compiler Differences

The VSCode installation tutorials above are split by operating system for one fundamental reason: MacOS users will be compiling their code with Clang, and Windows users will be compiling their code with GCC. C++ compilers are just like any other program -- depending on versions and vendors, compilers can have slightly differing behavior. The underlying C++ standard is well defined, however, and thus as long as you follow the standard, your code should compile correctly everywhere.  That said, we have an important "Rule of Compiling" for this class...

**The Rule of Compiling**: no matter how you develop your code, the only compiler that matters is the one on Coding Rooms, i.e., the one that will be testing your code. If it compiles and runs there, great. If not, then it is up to you to get it to compile there.

## Editing and Compiling C++

The first program you run in any new language is the "Hello world" program. This program does nothing but print the statement "Hello world". It is a tradition because it does little except focus on the mechanics of writing your first program and running it. You can look at the wikibooks [Hello world](https://en.wikibooks.org/wiki/Computer_Programming/Hello_world) page for more than 200 language interpretations.

In C++, Hello world is fairly easy, but clearly more work than in Python!

```c++
#include <iostream>

int main() {
    std::cout << "Hello world" << std::endl;
}
```

Write or copy-paste this code into a file named "main.cpp" to follow along.

To compile our Hello world program, type the following into terminal (Console/Shell):

```cmd
g++ -std=c++17 -Wall main.cpp 
```

`g++` is the GNU C++ compiler. In the above line, we have added a `-std=c++17` flag to ensure that the code is compiled using the C++17 standard.
Although our Hello world program does not contain any C++17 extensions, it is a good idea to get into the habit of including this flag as different compilers default to different standards (to get the newest standard, try `-std=c++20` instead; all newer compilers will allow C++ 20, but not ones more than a couple of years old). The `-Wall` flag is useful for finding errors, it's an abbreviation for "warnings, all".

By default, `g++` will create an executable named **a.out** (or **a.exe**, depending on the compiler). If your compilation was successful, you should see this newly created file in your current directory.

To execute/run the program, type:

```bash
./a.out
```

or, if you have an a.exe file:

```bash
./a.exe
```

If all has gone according to plan, running the program should result in "Hello world" being printed to the command line.

The typical workflow is something like:

- Edit your code using your favorite editor, then save it (ensuring that the file has a ".cpp" suffix).
- In your terminal, enter `g++ -std=c++17 -Wall {your file's name}.cpp`.
- If there are errors (and there *will* be errors), read the messages and edit your code. Repeat until it compiles.
- Once your code compiles, run the `a.out`/`a.exe` executable, and observe the (hopefully correct) output for testing.

You repeat this process of edit-compile-run until you get the desired result.

## Coding Rooms

For some labs, and **all projects**, we will be using Coding Rooms. Coding Rooms provides a convenient way to write, test, and submit code. Most assignments will have an associated Coding Rooms page like this one. Follow the directions below to submit your Lab 01 assignment for automatic grading.


### Accessing Coding Rooms

If you haven not yet accessed Coding Rooms, follow the instructions [here](../coding_rooms_setup.html) to try it out.


### The Unix Terminal

In future labs, there will be short sections dedicated to learning more about the terminal. Windows users are strongly recommended to install the Windows Subsystem for Linux (WSL), where MacOS/Linux users can follow along using their local terminal if they so choose.

The Coding Rooms IDE can also be used to write C/C++ code. We'll be coding here today just so there's a bit of exposure to the Coding Rooms IDE interface, and in case some students were unable to get a local code editor running on their machines.

## Coding Assignment

Lab 01 consists of one (hopefully simple) task. Changing the program's output in the main.cpp file.

### main.cpp

Modify main.cpp to print out the following message _exactly_ (instead of `"Hello world"`):

```
"My name is Josh Nahum. I read the syllabus and I understand the consequences of academic dishonesty."
```

The file needs to have the exact message above, but the name `Josh Nahum` should be changed to have *your* name instead (using only alphabetical characters and spaces). By submitting this assignment, you are confirming that you read the [syllabus](../syllabus.html) and understand the consequences of academic dishonesty.

Submit the assignment -- you should pass all of the tests. Congratulations!

## Collaboration on Labs

Everyone should be in pairs (or trios) for future labs. Pair programming is a common and productive method of software development used in the industry. It is also effective in educational settings. 

Traditionally, there are two roles:
- "Driver" - this role is the only one allowed to touch the mouse and keyboard. They do all of the coding.
- "Navigator" - this role is tasked with looking over the code that was written, suggesting edits/fixes, looks for bugs, and so on. Generally, they are in charge of keeping the "big picture" in mind, how code should be structured, coming up with names and algorithms, etc.

If you are in a trio, consider dividing the Navigator role into the "Observer" (who actively watches and comments on what the Driver is doing) and the "Guide" (who keeps open useful documents and plans out the pseudocode for future parts).

Depending on how your TA is managing the lab, these roles will often be swapped periodically (at the TA's call) to ensure everyone participates in both roles equally.

There are many ways to collaborate even if you are working together virtually. The simplest is to have the Driver share their screen and have the other roles watch and comment verbally as needed. When a different driver is needed, the current code can be shared in the Zoom chat (via file upload) with the new driver. Alternatively, if you are using VSCode as your editor, the [Live Share extension](https://visualstudio.microsoft.com/services/live-share/) allows you to invite others to join your editor session to make modifications in real time (like Google Docs).

In future labs, you will be compelled to work with a partner. So, we recommend starting to figure out who you are comfortable working with now.

# Honors Material

Students who are doing the honors option in CSE 232 are expected to do some extra work that allows them to go a further in depth into the material.  Each lab will have this additional honors material in the final section; students in the honors option must complete this additional work for the lab to count toward your grade.  If you are not planning to get honors credit for this course you are still welcome to complete this section, but it will not affect your course grade in any way.

## C++ compilers

In the laboratory above, you compiled your Hello World program using C++17, the specification for the language that was formalized in 2017 and incorporated into all major compilers over the subsequent year or two.  The newest C++ standard is C++20 (from 2020), which has only recently been fully incorporated into compilers.  For some of the honors labs you will need to be able to use C++20, so please make sure that you can compile your Hello World program using it on your own machine (Coding rooms will use the correct compiler settings for testing).

```cmd
g++ -std=c++20 -Wall main.cpp 
```

Or, if you have a slightly older compiler you may need to use "2a" instead of "20":

```cmd
g++ -std=c++2a -Wall main.cpp 
```

If your compiler gives you an error, you may need to upgrade to a more modern compiler.  That said, one of the improvements in C++20 is improved warnings and errors, so once you have it we do recommend that you use it for all of your projects.

The C++ standard committees are currently meeting trying to finalize the C++23 standard over the next year's time.  At various points in this course we may give you a previews of some of the exciting new features coming to C++.

## Additional Resources

As you are learning the nuances of C++, you will often find yourself having questions about the details of the language or why a particular section of your code is not working as you would expect.  While asking questions on Piazza will help you overcome these hurdles, if you want a faster solution (and one that will remain useful after this course) you should take a look at these resources:

- [CPPReference.com](https://en.cppreference.com/w/) is effectively an online textbook for C++ that is continually updated and covers all versions of the language with clear examples.

- [StackOverflow.com](https://stackoverflow.com/) is a website for asking and answering questions across many different programming languages.  Unlike many other such sites, answers are peer reviewed and tend to be of higher quality than what can be found elsewhere.  As always, use your own judgement when evaluating answers and do not copy over code directly without proper citation.

- [begin(C++)](https://gist.github.com/johnmcfarlane/1b2d9c83e4d3f700ba61e2df4077c613) is an actively maintained list of other C++ resources, many of which will be most useful after you are comfortable with the basics of C++, but will help you refine your coding practices to be quicker, easier to read, and less error prone.

Some of these resources will go into far more depth than you are likely ready for, but you will find them to be more and more useful as you get comfortable with them and with the C++ language.

## Honors Lab Questions

Go to Coding Rooms via the link in D2L and click on "Honors Lab 01" (under the Week 01 material) to find a series of questions to answer associated with this lab.
