# Lab 08 - Structs

## Wildcards and Filenames

When compiling multiple file C++ projects, it is often annoying to have to specify each individual cpp file to the compiler. Example:

<pre>g++ -std=c++17 -Wall -g main.cpp stack.cpp disk.cpp io.cpp</pre>

BASH gives an alternative way to select files that match a particular pattern. Notice that the above files were all the files in the folder that ended with '.cpp'. You can use a wildcard (the asterisk '*') to denote all of those files at once. Example:

<pre>g++ -std=c++17 -Wall -g *.cpp</pre>

The `*.cpp` expands to all of the files that end with '.cpp'.

This is often useful when you want to do things to multiple files. Lets say you have a folder named `headers` that you want to move all the '.h' files to. You can do so with:

<pre>mv *.h headers/</pre>

![](Red_star.svg) Show your TA what happens when you use wildcards to open multiple '.cpp' files with the `gedit` command.

## Debugging Code with an IDE (Visual Studio 2019)

Spring 2020 students: Due to COVID-19 this section of the lab is optional. You won't be responsible for this material.

While the debugger (GDB) that we taught in Lab05 is portable and useful, interacting with a command line debugger can be difficult, as the compiler and debugger are separate entities. Fortunately, there exist integrated development environments (IDEs) that provide a complete environment for developing, running, and debugging code. For the purposes of demonstration, we are going to use Visual Studio 2019, a program for Windows. Other IDEs exist for other operating systems (e.g. XCode for Mac, VS Code with plugins for Linux), and which IDE you use can vary with programming language and personal preference. Feel free to try out several IDEs so that you can see what you like!

Visual Studio 2019 comes installed by default on the lab machines. Opening Visual Studio 2019 should provide you with an opening screen that appears as so:

![](lab08addition_files/vs_open.jpeg)

#### Setting up a new project

First, create an empty directory named "Lab08" in your Documents or Desktop folder (Use either Windows Explorer or right click > new folder on the Desktop). We will then "Create a new project" in this folder to create and test our code. In Visual Studio, click "Create a new project" option. You should be presented with new window like this:

![](lab08addition_files/create_new_project.jpeg)

Select the Console App that runs the code in a Windows terminal. You will then be presented with a screen like this:

![](lab08addition_files/configure_your_project.jpeg)

Browse to the "Lab08" folder that you created, and then enter a project name in the corresponding text box (I recommend "Lab08"). Also check the "Place solution ..." checkbox. At this point you can click "Create" and a project will be created.

![](lab08addition_files/default_code.jpeg)

Now replace the default code with the contents of the badString.cpp from Lab05.

![](lab08addition_files/badstring.jpeg)

On the far left of the central text box, there is a vertical gray bar. While it may look like a decorative addition, it serves an important function: it allows you to set breakpoints. As a reminder, a breakpoint is a stopping point during your code's execution that the debugger will recognize. Click on the grey bar to set a breakpoint, and a red dot will show up like this:

![](lab08addition_files/first_breakpoint.jpeg)

To remove the breakpoint, simply click on the dot again to make it go away. To match the breakpoints used in lab05, we want to set a breakpoint at lines 11 and 35 in the code. This should result in a setup that displays as follows:

![](lab08addition_files/second_breakpoint.jpeg)

Now that we have set up breakpoints, we need to actually run the debugger. To do so, simply click on the green arrow in the box labelled "Local Windows Debugger". After building, the terminal window will pop up and the layout of the screen will change. It should look something like this:

![](lab08addition_files/debugger_running.jpeg)

There are several important things to note here. First, we have two new boxes: Autos and Call Stack. Autos is a collection of variables that the debugger has listed as currently active in the scope of the execution. The other option at the bottom of that box, Locals, displays the local variables currently in use. Both the variable name, value, and type are all displayed for your convenience. The other box, Call Stack, shows a hierarchy of the function calls that have been made. As we have hit the first breakpoint, we are in the main function.

Lastly, the bar at the top has changed. There are now several debugger options available to move through the program. Let's look at these options in detail:

![](lab08addition_files/debugging_commands.jpeg)

From left to right, we have:

*   Continue - This allows the program to continue running until the next breakpoint or the end of execution
*   Find In Files - A more advanced option that we won't need here
*   Break All - The pause button, this stops the program where it is currently running
*   Stop Debugging - The red square, this stops the program execution entirely
*   Restart - This restarts the program execution from the beginning
*   Show Next Statement - This moves to the next statement in the execution order on the atomic level - generally not effective
*   Step Into - This steps into the lower level of function execution. If we were in the main function and were on a line calling fn2, this would step into the execution of fn2
*   Step Over - This executes the currently line of code and moves to the next line or statement to be executed - extremely useful
*   Step Out - This steps out of a function to a higher level. If we were in fn2 and stepped out, we would step back into the main function execution

If you continue from the previous breakpoint in main, you will reach the breakpoint in fn2\. Use the Step Over functionality to step through the program and discover where it breaks.

While you should remember the issues with the code from Lab05, I encourage you to play around with the functionality that Visual Studio 2019 provides and see how you could have solved the issues with this debugger as opposed to GDB.

![](Red_star.svg) Show your TA the Autos and Call Stack windows and explain what they are showing.

## Programming Assignment

This lab will have you apply generic algorithms to various programming problems.

We strongly recommend watching this video ([https://www.youtube.com/watch?v=2olsGf6JIkU](https://www.youtube.com/watch?v=2olsGf6JIkU)) prior to the lab.

Download this file: [lab08.cpp](lab08/lab08.cpp)

Write definitions for the 4 functions described. You are not to use any loops (no for loops or while loops), but must instead use algorithms from the `algorithm` and `numeric` libraries.