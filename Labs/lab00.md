# Lab 00 - Getting Started

This lab is designed to make sure that you can access all the class resources. In particular: the class website, Piazza, and mimir. Also, you should be able to compile, and run a simple C++ program. Ensure that you complete this lab, so that you can do all the work necessary for this course.

## Class resources

[Link to class website](https://github.com/braedynl/CSE232). This is the main link you need for this course. It hosts the course schedule, TA assignments, lectures, and more.

Please make sure that you can access all of these resources, and ask your TA for help if you can't find any of them.

## Using C++

For this class, we are initially going to be using online compilers such as [onlinegdb](https://www.onlinegdb.com). In fact, for this lab, you can do everything online (and even for a few later labs). However, as the course progresses, you are going to want to edit, compile and run code locally. This lab is a good time to get started on this process.

### Editors

Editors are like religion: most people have one, but don't like what anyone else has chosen. You will have the opportunity to pick the editor of your choice as you go along.

- [Visual Studio Code](https://code.visualstudio.com/) (VSC or VSCode) is a modern programmer's editor. It is very flexible, has many options, and can be used cross-platform. If you want to be a programmer, this is a good one to learn so we'll start with this one.
- [Emacs](https://www.gnu.org/software/emacs/) is a very old, very configurable, editor. The joke is that emacs is an operating system disguised as an editor. This is what I use but I would not start here.
- [gedit](https://gedit.en.softonic.com/) is a straight-forward editor. It is not very configurable but does a good job at just being an editor. If all else fails, I would pick gedit.
- [Vi/Vim](https://www.vim.org/download.php) is also very old, but comes as standard in many Linux operating systems as a default editor. I wouldn't start here, but learning the basics of vi is something every programmer should do. There is a lot of information on how to setup VSC. One of our own students, a previous TA, Matt Pasco has written a page on how to setup VSC on your local computer. The setup allows you to compile and debug from VSC, something we appear not to be able to do on the lab machines. [Take a look here](http://www.cse.msu.edu/~pascomat).

## Working with C++

### About C++

From Wikipedia:

> C++ is a general-purpose programming language. It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.

Languages come in various "levels", from "low" (meaning very close to the CPU they might run on) to "high" (meaning very far from the CPU they might run on). Python is a great example of a high-level language. C++ is like an intermediate language; it doesn't give you all the help you might recieve from Python, but it gives you much more help than Assembly.

It is important to remember that C++ is a compiled language. That means that you must pass your code through another piece of software, called a **compiler**, that translates your C++ into nearly machine-ready code. Note that Python has no requirement, as there is always an **interpreter** available for running Python code.

The greatest strength of C++ is its potential for creating fast executables and robust libraries. C and C++ provide great flexibility in controlling many of the underlying mechanisms used by an executing program. A programmer can control low-level aspects of how data is stored, how information is passed, and how memory is managed. When used wisely, this control can lead to a more streamlined result -- this is the point of the class. You are in charge of how your code runs because you, the programmer, are responsible for most aspects of how your code runs. This is a double-edged sword, as being responsible gives you more opportunities to screw up.

One of the problems with C++ is that parts of the syntax have grown cryptic. Rather than one way to express something, there may be alternatives. An experienced and knowledgeable developer can use this flexibility to pick the best alternative and improve the result. Yet both novice and experienced programmers can easily choose the wrong alternative, leading to less-efficient, and possibly flawed, software. Be careful!

### Doing it on your own

The best way to do your work (until you have a local compiler) is though Mimir.

* Mimir only requires access to a web browser and the internet. While it does not provide a full Unix environment, it does provide a Unix terminal and compiler.

However, because you are CS students, perhaps you would like to do this on your own computer. Good news; C++ is available for any platform, and has been for decades. Bad news; see the following paragraphs...

### Bad News 1: Getting a Compiler

*   Linux users: you already have one, congratulations!
*   Mac OS users: you don't have one. However, you can get it if you follow these [directions](http://osxdaily.com/2014/02/12/install-command-line-tools-mac-os-x/). They show you how to install part of Xcode, a large application developed by Apple for development, as well as the command line tools for your [Terminal](https://www.imore.com/how-use-terminal-mac-when-you-have-no-idea-where-start) application.
*   Windows users: you don't have one, but two things:
    *   You have available on the lab machines Visual Studio. You can try it out there if you like.
    *   You can download for free a copy of through DECS. Go to [this page](https://www.egr.msu.edu/decs/help-support/how-to/microsoft-imagine) and Login (bottom left) with your EGR name and password. You can then "Start Shopping". Select "Developer Tools" (column on the left) then download "Visual Studio Enterprise". Install it on your Windows laptop (Note there is a version of Visual Studio Code but it is just an editor, no compiler).
*   Windows 10 also has a new feature (not yet enabled on the lab machines) called Windows Subsystem for Linux (WSL). Windows 10 does not come with a Linux command line but WSL provides one that looks very much like an Ubuntu 16.04 Linux terminal. You can set it up and run your code there, as you would on Mimir. More adventurous, but take a look [here](https://winaero.com/blog/enable-wsl-windows-10-fall-creators-update/). It really is quite nice!

### Bad News 2: Compiler Differences

It turns out that C++ compilers are just like any other program. Thus, depending on versions and vendors, C++ compilers can have slightly different behavior.

**The Rule of Compiling**: no matter how you develop your code, the only compiler that matters is the one on Mimir, i.e., the one that will be testing your code. If it compiles and runs there, great. If not, then it is up to you to get it to compile there.

## Editing and Compiling C++

The first program you run in any new language is the "Hello world" program. This program does nothing but print the statement "Hello world". It is a tradition because it does little except focus on the mechanics of writing your first program and running it. You can look at the wikibooks [Hello world](https://en.wikibooks.org/wiki/Computer_Programming/Hello_world) page for more than 200 programming language interpretations of Hello world.

In C++, Hello world is fairly easy, but clearly more work than in Python! Go to the Mimir editor and write the following program:

```c++
#include <iostream>

int main() {
    std::cout << "Hello world" << std::endl;
}
```

You can copy and paste this code into your file (name it "lab00.cpp").

Next, the plain-text file needs to be compiled and executed. To compile with GNU's C++ compiler, type the following into the Mimir terminal:

```cmd
g++ -std=c++17 -Wall lab00.cpp
```

`g++` is the GNU C++ compiler. In the above line, we have added a `-std=c++17` flag to ensure that the code is compiled using the newer C++17 standard (by default, most C++ compilers use the C++98 standard, which does not include all of the features/extensions that we will be using in this class).
Although our Hello world program does not contain any C++17 extensions, it is a good idea to get into the habit of including this flag. The `-Wall` flag is useful for finding errors, it's an abbreviation for "warnings -- all".

By default, `g++` will create an executable named **a.out**. If your compilation was successful, you should see this newly created file in your current directory.

To execute/run the program, type:

```cmd
a.out
```

If all has gone according to plan, running the program should result in `"Hello world!"` being printed to the command line.

⭐ These star emojis are checkpoints where you should stop and check in with your lab TA. If you are in an in-person lab, this would mean raising your hand and having the TA look over your work. If you are in a virtual Zoom lab, you should now click the "request assistance button" from your breakroom to summon your TA.

Note that to build a program consisting of multiple files in a directory, we will enter:

```cmd
g++ -std=c++17 -Wall *.cpp
```

This will compile all the files that make up the source code of your program.

The typical workflow is something like:

- Edit your code using your favorite editor, then save it (ensuring that the file has a `.cpp` suffix).
- In your terminal, enter, `g++ -std=c++17 -Wall {your file's name}.cpp`.
- If there errors (and there *will* be errors), read the error messags and re-edit your code. Repeat until it compiles.
- Once your code compiles, enter `a.out` in the terminal to run the compiled executable, and observe the (hopefully correct) output for testing.

You repeat the process of edit, compile, run until you get the desired result.

## Mimir

For some labs, and **all projects**, we will be using Mimir. Mimir provides a convienent way to write, test, and submit code. The assignments will have an associated Mimir page, including this one. Follow the directions below to submit your Lab 00 assignment for automatic grading.

### How to access Mimir

Mimir is **required software**. You **have** to join Mimir, as it is the only way you can turn in your work for the course. In the long run, I think you will appreciate the ability to test your code before you turn it in, as well as having a simple interface via your web browser.

You should have already recieved an invitation to Mimir for this class. If you have not yet received it, _please inform your TA_. You will need to do this in order to complete all of the class assignments.

In the Active Coursework section, find and click the link to the Lab 00 assignment (obviously we aren't in Spring 2018, but you get the idea):

![](../.assets/images/mimir_start.png)

Once you've clicked the assignment, you'll be brought to the assignment's Submission page. On this page, you'll have the project's description, and a link to upload your assignment.

At the top-right are three important buttons:
- "Submit", this is the button you'll want to use to upload your code
- "Download Starter Code", this gives you a .zip file of the code we want you to edit.
- "Open IDE", this opens Mimir's terminal and editor

Click the "Open IDE" button to go to Mimir's IDE. It should open a separate tab that looks like this:

![](../.assets/images/mimir_ide_start.png)

## Coding Assignment

Lab 00 consists of two (hopefully simple) tasks. Correcting a typo in the file "hello_world.cpp" and creating a new file called "academic_dishonesty.cpp".

### hello_world.cpp

I tried to write a "hello_world.cpp" file to show you how easy it is, but I made a typo. Take a look at the "hello_world.cpp" file. It should already be open, but it is located in a folder with the class' name -> lab00__hello_world -> lab00.

Please correct my spelling of "Hello", then save the file.

Then, right-click on the **parent** of the folder named "lab00", and select "Submit folder contents". Be sure to select the correct assignment as well.

Now you can go to your submissions page (the other Mimir tab), and confirm that you are passing the tests regarding hello_world.cpp.

### academic_dishonesty.cpp

The next part of the assignment involves making a new file called "academic_dishonesty.cpp".

Right-click on the folder named "lab00" and create a new file named "academic_dishonesty.cpp". Make sure the name is _exactly_ what is indicated.

**Note**: you may need to right-click on the folder tree and select "refresh" for your newly created file to exist.

Copy the contents of hello_world.cpp into this new file.

Submit the assignment again like we did before. You should pass _all but the last test_. We need to fix that.

Modify the file academic_dishonesty.cpp to print out the following message _exactly_ (instead of `"Hello world"`):

```
"My name is Josh Nahum. I read the syllabus and I understand the consequences of academic dishonesty."
```

The file needs to have the exact message above, but the name `Josh Nahum` should be changed to have *your* name instead (using only alphabetical characters and spaces). By submitting this assignment, you are confirming that you read the [syllabus](../SYLLABUS.md) and understand the consequences of academic dishonesty.

Submit the assignment -- you should pass all of the tests. Congratulations!

⭐ Demonstrate to your TA that you are passing all of the tests.

All assignments in this class will be administered through Mimir, so it is important that you are familiar with it before jumping in to future labs and projects.

## Collaboration on Labs

Everyone should be in pairs (or trios) for labs in this course. Pair programming is a common and productive method of software developement used in the industry. It is also very useful in educational settings. 

Traditionally, there are two roles:
- The "Driver": this role is the only one allowed to touch the mouse and keyboard. They do all of the coding.
- The "Navigator": this role is tasked with looking over the code that was written, suggesting edits/fixes, looks for bugs, and so on. Generally, they are in charge of the "big picture" stuff, how code should be structured, coming up with names and algorithms, etc.

If you are in a trio, I recommend having the Navigator role be broken into the "Observer" (who actively watches and comments on what the Driver is doing) and the "Guide" (who keeps open useful documents and plans out the pseudocode for future parts).

Depending on how your TA is managing the lab, these roles will often be swapped periodically (at the TA's call) to ensure everone participates in both roles equally.

There are many ways to collaborate even if you are working together virtually. The simplest is to have the Driver share their screen and have the other roles watch and comment verbally as needed. When a different driver is needed, the current code can be shared in the Zoom chat (via file upload) with the new driver. Alternatively, if you are using VSCode as your editor, the [Live Share plugin](https://visualstudio.microsoft.com/services/live-share/) allows you to invite others to join your editor session (like Google Docs).

In future labs, you will be compelled to work with a partner. So, I recommend figuring out who you are comfortable with right now.
