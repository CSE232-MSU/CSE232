Outline

This lab is designed to make sure that you can access all the class reources, in particular, the class website, piazza, and mimir. Also, you should be able to compile, and run a simple c++ program. Ensure that you complete this lab, so that you can do all the work necessary for this course. run

Class resources to access all the necessary material
Activate Mimir so you can turn in your work
Do the simple assignments and make sure you can do your work.
Section 1: Class resources
Class website. This is the main link you need for this class. This contains information about the class schedule, Lab schedule, TA assignments, as well as links to the Labs, and class lecture videos.

Make sure that you can access all the class resources, and ask your TA for any help if you can't find any of the resources.

Section 2: Using C++
For this class, we are initially going to be using online compilers such as https://www.onlinegdb.com. In fact, for this lab, you can do everything online (and even for a few later labs). However, as the course progresses, you are going to want to edit, compile and run code locally. This lab is a good time to get started on this process.

Editors
Editors are like religion: most people have one but don't like what anyone else has chosen. You will have the opportunity to pick the editor of your choice as you go along. The image below lists the 4 that are available on chuck: Visual Studio Code(VSC), emacs, gedit, vim. Some basic info:

Visual Studio Code (VSC) is a modern, programmer's editor. It is very flexible, has many options, and can be used cross platform. If you want to be a programmer, this is a good one to learn so we'll start with this one.
Emacs is a very old, very configurable, editor. The joke is that emacs is an operating system disguised as an editor. This is what I use but I would not start here.
gedit is a straight-forward, editor. It is not very configurable but does a good job at just being an editor. If all else fails, I would pick gedit.
Vi/Vim is also very old, but comes as standard in many linux OS as a default editor. I wouldn't start here, but learning the basics of vi is something every programmer should do.
There is a lot of information on how to setup VSC. One of our own students, a previous TA, Matt Pasco has written a page on how to setup VSC on your local computer. The setup allows you to compile and debug from VSC, something we appear not to be able to do on the lab machines. Take a look here .
Section 3: Working with C++
Section 3.1 About C++
From Wikipedia:

C++ is a general-purpose programming language. It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.
Languages come in various "levels", from "low" meaning very close to the CPU they might run on (assembler for example) to high, such as Python which abstracts much of that away. C++ is a kind of intermediate language, without all the help you might get from a Python but higher then an assembler.

It is important to remember the C++ is a compiled language. That means that you must pass your code through another piece of software called a compiler that translates your C++ into nearly machine-ready code. Note that Python has no requirement as there is always an interpreter available for running Python code.

The greatest strength of C++ is its potential for creating fast executables and robust libraries. C and C++ provide great flexibility in controlling many of the underlying mechanism used by an executing program. A programmer can control low-level aspects of how data is stored, how information is passed and how memory is managed. When used wisely, this control can lead to a more streamlined result. This is the point of the class. You are in charge of how your code runs because you (the programmer) are responsible for most aspects of how your code runs. This is a double-edged sword as being responsible gives you more opportunities to screw up.

One of the problems with C++ is that parts of the syntax have grown cryptic. More signifcantly, the fexibility given to a programmer for controlling low-level aspects comes with responsibility. Rather than one way to express something, there may be alternatives. An experienced and knowledgeable developer can use this flexibility to pick the best alternative and improve the result. Yet both novice and experienced programmers can easily choose the wrong alternative, leading to less-efficient, and possibly flawed, software. Be careful!

Section 3.2 Doing it on your own
The best by far way to do your work (at the moment, till you have a local compiler) is though mimir as we have discussed.

mimir requires only access to a web browser and the internet. While it does not provide a full unix environment, it does provide a unix terminal and a compiler, enough to do your work
However, since you are CS students perhaps you would like to do this on your own computer. Good news, C++ is available for any platform and has been for decades. Bad news. Couple of bad news things:

Bad News 1: Getting a compiler
For Linux, you already have it. Congratulations!
For Mac OSX, you don't have it by default. However, you can get it if you follow these directions . They show you how to install part of Xcode, a large application developed by Apple for development, as well as the command line tools for your Terminal application.
Windows, you don't have it, but two things:
You have available on the lab machines Visual Studio. You can try it out there if you like.
You can download for free a copy of through DECS. Go to this page and Login (bottom left) with your EGR name and password. You can then "Start Shopping". Select "Developer Tools" (column on the left) then download "Visual Studio Enterprise". Install it on your Windows laptop (Note there is a version of Visual Studio Code but it is just an editor, no compiler).
Windows 10 also has a new feature (not yet enabled on the lab machines) called Windows Subsystem for Linux (WSL). Windows 10 does not come with a Linux command line but WSL provides one that looks very much like an Ubuntu 16.04 Linux terminal. You can set it up and run your code there, as you would on mimir. More adventurous, but take a look here . It really is quite nice!
Bad News 2
It turns out that C++ compilers are software just like any other program. Thus depending on versions and vendors, C++ compilers can have slightly different behavior.

The Rule of Compiling No matter how you develop your code, the only compiler that matters is the on on Mimir where you will turn in your code. If it compiles and runs there, great. If not, then it is up to you to get it to compile there. Only Mimir Matters

Section 4: Editing and Compiling Code
The first program you run in a new language is the Hello World program. This program does nothing put print the words â€œHello Worldâ€. It is a tradition because it does very little except focus on the mechanics of writing your first program and running it. Look at the wikibooks page Hello world for more than 200 programming language examples of hello world.

In C++, Hello World is fairly easy, but clearly more work than something like Python! Go to the mimir editor and write the following program

  #include <iostream>
      
  int main( ) {
     std::cout << "Hello World" << std::endl;
}
You can copy and paste the code into your text file (name it "lab00.cpp").

Next, the plain-text file needs to be compiled and executed. To compile with GNU's C++ compiler, type the following into the mimir terminal:

g++ -std=c++17 -Wall lab00.cpp
g++ is the GNU C++ compiler. In the above line, we have added a flag -std=c++17 to ensure that the code is compiled using the newer C++17 standard (by default, most C++ compilers use the C++98 standard, which does not include all of the features/extensions that we will be using in this class). The -Wall is useful for finding errors. Although our "Hello World" program does not contain any C++14 extensions, it is a good idea to get into the habit of including this flag.

By default, g++ will create an executable named a.out. If your compilation went correctly, you should see this newly created file in the current directory.

Finall, to execute/run the program type:

./a.out
The ./ simply means look into the current directory when attempting to find the a.out program. If all has gone according to plan, running the program should result in "Hello World" being printed to the command line.


 These Red Stars are checkpoints where you should stop and check in with your lab TA. If you are in a in-person lab, this would mean raising your hand and having the TA look over your work. If you are in a virtual Zoom lab, you should now click the "request assistance button" from your breakroom to summon your TA. "Make sure you can run the Hello World program." You should now check in with your TA before proceeding.


Note that to build a program consisting of multiple files in a directory, we will enter:

g++ -std=c++17 -Wall *.cpp
This will compile all the files that make up the source code of your program.

The typical workflow is something like:

edit your code files using your favorite editor, then save (File -> Save) your code with a .cpp suffix
In your command line terminal, enter, g++ -std=c++14 -Wall *.cpp .
If there errors (and there will be errors), read the error messags and re-edit your code. Repeat until it compiles
Once your code compiles, enter ./a.out in the terminal to run the compiled executable. and observe the ouput, hopefull the correct output
You repeat the process of edit - compile - run until you get the result desired

Section 5: Mimir and Projects
For some labs, particular this first lab, and all projects, we will be using the Mimir Platform. Mimir provides a convienent way to write, test, and submit your code. The assignments will have an associated Mimir page, including this one. Follow the directions below to submit your Lab 00 assignment for automatic grading.

Section 5.1: How to access Mimir
Mimir is required software . You have to join Mimir as it is the only way you can turn in your work for the course. In the long run, I think you will appreciate the ability to test your code before you turn it in, as well as having a simple interface via web browser requiring no software.

You should have already recieved an invite to mimir for this class. If you have not received it yet, please inform your TA. You will need to do this in order to complete all the class assignments.

In the Content section, click on the link to Mimir (obviously we aren't in Spring 2018, but you get the idea):


Once logged into Mimir, look for . From that page, you should see a link called "Lab 01". Go to it. This is the Project Submission page. On this page, you have see the project's description, and any project submissions you have turned in.

At the top right are three important buttons:

"Submit": this is the alternate method for submitting code (where you need to zip and upload your code).
"Download Starter Code": this gives you a zip file of the files we want you to edit.
"Open IDE": this opens Mimir's terminal and editor
Click the "Open IDE" button to go to Mimir's IDE. It should open a separate tab that looks like this:


Lab 00 - Programming Portion
Lab 00 consists of two (hopefully simple) tasks. Correcting a typo in the file "hello_world.cpp" and creating a new file called "academic_dishonesty.cpp".

hello_world.cpp
I tried to write a "hello_world.cpp" file to show you how easy it is, but I made a typo. Take a look at the "hello_world.cpp" file it should already be open, but it is located in a folder with the class' name -> lab00__hello_world -> lab00.

Please correct my spelling of "Hello" then save the file.

Then right-click the on the parent of the folder named "lab00", and select "Submit folder contents", be sure to select the correct assignment as well.

Now you can go to your submissions page (the other Mimir tab), and confirm that you are passing the tests regarding hello_world.cpp.

academic_dishonesty.cpp
The next part of the assignment involves making a new file called "academic_dishonesty.cpp".

Right-click on the folder named "lab00" and create a new file named "academic_dishonesty.cpp". Make sure the name is exactly what is indicated.

Note: you may need to right click on the folder tree and select "refresh" for your newly created file to exist.

Copy the contents of hello_world.cpp into this new file.

Submit the assignment again like we did before. You should pass all but the last test . We need to fix that.

Modify the file academic_dishonesty.cpp to print out the following message exactly (instead of "Hello World").

    My name is Josh Nahum. I read the syllabus and I understand the consequences of academic dishonesty.
  
The file needs to have the exact message above, except the name Josh Nahum should be changed to have your actual name instead (using only A-Z, a-z and space characters please). By submitting this assignment, you are confirming that you read the syllabus and understand the consequences of academic dishonesty.

Submit the assignment and you should pass all the tests and be done with Lab00, Congratulations!

 Demonstrate to the TA that you are passing all tests.

All the Projects and Labs for this class will be performed with Mimir, so it is important that you are familiar with it before starting Project 1.

Section 6: Collaborating with your Lab Partner
Everyone should be in pairs (or trios) for labs in this course. Pair programming is a common and productive method of software developement used in industry. It is also very useful in educational settings. Traditionally, there are two roles:

The Driver: this role is the only one allowed to touch the mouse and keyboard. They do all of the coding.
The Navigator: this role is tasked with looking over the code that was written, suggesting edits/fixes, looks for bugs, and so on. Generally, they are in charge of the "big picture" stuff, how code should be structured, coming up with names and algorithms. hey often have a separate monitor with resources (e.g. documentation) open.
If you are in a trio, I recommend having the Navigator role be broken into the Observer (who actively watches and comments on what the Driver is doing) and the Guide (who keeps open useful documents and plans out the pseudocode for the future parts).

Depending on how your TA is managing the lab, often these roles will be swapped periodically (at the TAs call) to ensure everone participates in both roles equally.

There are many ways to collaborate even if you are working together virtually. The simplest is to have the Driver share their screen and have the other roles watch and comment verbally as needed. When a different driver is needed, the current code can be shared in the Zoom chat (via file upload) with the new driver. Alternatively, if you are using VS Code or Visual Studio as your editor, the Live Share plugin allows you to invite others to join your editor session and you can have other people both see and edit the files in your editor (kinda like how Google Docs works).

In future labs, you will be compelled to work with a partner. So it would be go to figure out what you are comfortable with now.

