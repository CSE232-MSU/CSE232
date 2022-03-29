---
title: Lab - Git Version Control
---

# Lab - Git Version Control

## Ask Me Anything - TA Edition

Before you get assigned to work in your pairs, please use the beginning of this lab to ask your TA about concepts that you have been having a hard time grasping. You can ask about recent topics (like converting constructors) or older concepts like what it means to put `cin >> str` in a while loop's conditional clause. And, I'm sure some of you are still uncomfortable with pointers, references, and const.

Now is the time to ask questions and hear from your TA. You are also welcome to ask about your TAs background and interests. Many of them have even taken this course some time ago. They all have useful insights on future CSE courses you may be considering.

## Lab Assignment

### Introduction to Version Control with git and GitHub
One of the most important tools every software developer uses on a daily basis is version control.
Version control is software that can track and share changes to a code base (repository) with others.
"git" is the most popular of the version control systems and GitHub the most popular online host for git repositories.  

For this part of the lab, both partners will do all the tasks.

### Initial Setup
Make a free account on <a href="https://github.com/">GitHub.com</a>. 
Then complete the introductory tutorial named  <a href="https://guides.github.com/activities/hello-world/">"Read the Guide"</a>.
In this tutorial, you will make a public repository. You can give it a fun name if you like.

⭐ Show your TA the merged pull request as directed by the tutorial

### Collaboration

* Find your partner's newly created repository on GitHub.
* Click the "Fork" button in the top-right of the repository page to make your own copy of their repository.
* Edit and commit changes to your copy of their repository. (Perhaps leave a nice compliment.) 
* Click on the "New Pull Request" button and initiate a pull request for the changes you just made.
* Accept the pull request from your partner and confirm the changes made.


### git
GitHub is a useful website for sharing git repositories with the wider world, but most or your work with version control will be on your local computer.
For this part of the lab, you need to create a new private repository.
Then click on the green "Clone or Download" button and select the "HTTPS" option. Copy the HTTPS URL to the clipboard (to be used later).
This next part of the lab will be done in the Coding Rooms IDE terminal (or any other terminal that has git installed).

1. `cd` to the directory where you want a local copy of the repository to be placed.
2. Run `git clone https...` where the link is the url you copied from your GitHub repository.
3. You should be prompted for your GitHub username and a personal access token (_not_ your GitHub password). [Follow these instructions to obtain a personal access token with "repo" permissions.](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token)

Next we need to give git some information about yourself.

1. Run `git config --global push.default simple`
2. Run `git config --global user.name "Your Name Here"` where Your Name should be replaced with your actual name (or a fake name if you like).
3. Run `git config --global user.email "blah@msu.edu"` where the email should be replaced with your email (or a fake email if you like).

Next we will make changes to the repository. Note: most git commands require your current working directory to be inside the the repository to work.

1. Right click on the left-sidebar and refresh it to see the repository you cloned (it should be in a folder with the name of the respository).
2. `cd` into the newly created repository folder.
3. Edit the README.md file to have your name in it (or create this file if it doesn't exist). Save it.
4. Run `git status` to have git inform you of any changes to the repo it detects. It should show you that the README file has changed.
5. Run `git add README.md` to instruct git that it should track that change.
6. Run `git commit -m "Changed the README"` to have git save the changes to the history. You can replace the commit message with anything you like.
7. Run `git push` to have git share the commits (history) with the repo it was cloned from (the private repo on GitHub.)
8. If you refresh the repo page on GitHub, you should now see the changes you made to the README file.


### Adding Code to the Repo
This next part of the lab will involve you editing code in your repository.

1. Find some code you wrote for a previous lab and add that to your repository (copy the example.cpp file into the repository folder).
2. Run `git status`to confirm that git notices the presence of the project.cpp file.
3. Run `git add example.cpp` (be sure to use the actual name for the file) and then `git commit -m "example added"` to add and commit your example file.

Next you need to modify your to demonstrate a new commit.

1. Ensure your solution doesn't have redundant or repeated code.
2. Ensure that the variable and function names are clear and correctly spelled.
3. Ensure that you are using const and references everywhere possible to avoid unneeded work.
4. Ensure that you have adequate comments for each function and explain complicated functionality.

Once you have improved your solution (note, you may not receive credit if your pushed code is not well styled), you can add, commit, and push those changes to GitHub. 

⭐ Show your TA the code and the git log in your local repository.

### Git Problems?
`git` is a complicated program with many working parts. 
Without teaching you quite a bit more about how it works, it can be difficult to know how to fix certain problems.
But if your local repo is giving you trouble, one easy fix is to clone a new copy of the repo from GitHub and work with that one (make sure to copy and commit any changed files from the old repo before deleting it).


<!--


<h3>The Problem</h3>
<p>
    We are going to work on making our own classes with private data members and special accessors.
    We are going to build a Circular Buffer class,
    a common data structure with well known accessors.
</p>

<h3>Some Background</h3>
<p>
    Our Circular Buffer will be a data structure that stores <code>long</code> values.
    A Circular Buffer is a fixed size FIFO (First In, First Out) data structure.
    It is essentially a line (a queue).
    First thing added (the READ position in the diagram) is the first thing read.
    The next thing added is at the WRITE position.
    It is the last thing added, the last thing read.
    The underlying data structure for this approach has a fixed size data structure.
    It can become empty, it can become full.
    It does not grow or shrink in size over the course of the run of the program.
</p>
<img src="https://i.stack.imgur.com/qmPQ6.png" alt="">
<p>
    Things you can do with your Circular Buffer:
</p>
<ul>
    <li>
        You can add to the Circular Buffer. An element is added at the write position.
        The write position is then advanced.
    </li>
    <li>
        You can remove an element. The element at the read position is removed.
        The read position is then advanced.
    </li>
    <li>You can test if it is full.</li>
    <li>You can test if it is empty.</li>
</ul>

<h3>Your Tasks</h3>
<p>We are going to make a <code>CircBuf</code> class with these characteristics and test it.</p>

<h4>The Class</h4>
<p>
    The <code>CircBuff</code> class will have an underlying data member of your choice called
    <code>buffer</code> (a vector, a deque) of fixed size.
    This is a private data member, which will represent the underlying data array.
    <code>buffer</code> is private, you cannot access it from a main program using the class.
    Overall, we have 5 underlying elements in the <code>CircBuf</code>. Their need will be shown below.
</p>
<ul>
    <li>size (the maximum size of the buffer)</li>
    <li>count (the number of active elements in the buffer)</li>
    <li>front (an index to the next element that will be read)</li>
    <li>back (an index to where the next element will be written)</li>
    <li>buffer (series of longs)</li>
</ul>

<h4>Interface, circbuf.h file</h4>
<ul>
    <li><code>CircBuf</code> constructor, one argument, the <b>fixed size</b> buffer of <code>long</code>.
        <ul>
            <li>takes a default of 10, thus allowing for a default constructor.</li>
        </ul>
    </li>
    <li>
        <code>long pop_front()</code> member function, no parameters
        <ul>
            <li>if <code>CircBuf</code> is not empty, returns the <code>long</code> indexed by front and then advances front by one.</li>
            <li>if the <code>CircBuf</code> is empty, throws a <code>runtime_error</code>, <em>see the notes below about this</em>.</li>
        </ul>
        <p>
            <img src="Red_star.svg" style="width:1cm">
            Show your TA your completed <code>pop_front</code> method.
        </p>
    </li>
    <li>
        <code>bool remove()</code> member function, no parameters
        <ul>
            <li>if <code>CircBuf</code> is not empty, advances front by one and returns true.</li>
            <li>if the <code>CircBuf</code> is empty, returns false.</li>
        </ul>
    </li>
    <li>
        <code>bool add(long)</code> member function, single long parameter
        <ul>
            <li>
                if <code>CircBuf</code> is not full, places the parameter in <code>buffer</code> at the index indicated by <code>back</code>,
                advances the <code>back</code> by one and returns true.
            </li>
            <li>if <code>CircBuf</code> is full, returns false.</li>
        </ul>
    </li>
    <li>
        <code>bool empty()</code> member function, no parameters
        <ul>
            <li>returns true if the <code>CircBuf</code> is empty, false otherwise.</li>
        </ul>
    </li>
    <li>
        <code>bool full()</code> member function, no parameters
        <ul>
            <li>returns true if the <code>CircBuf</code> is full, false otherwise.</li>
        </ul>
    </li>
    <li>
        <code>ostream& operator<<(ostream &out, const CircBuf &cb)</code> This is a <b>friend</b> function (not a member).
        It prints the underlying buffer array and other elements of the class. Example output:
        <pre>
DUMP Front:0, Back:4, Cnt:2
1, 2, 1, 2,
</pre>
    </li>
</ul>

<h4>Implementation, circbuf.cpp</h4>
<p>
    There are a number of ways to implement this data structure.
    The important thing to note is the circular nature of the buffer.
    The two indices: <code>front</code> (where elements are read from) and <code>back</code> (where elements are added).
    They can wrap around the buffer like we have done with clock arithmetic:
</p>
<ul>
    <li>
        if <code>back</code> goes past the last index of the data structure,
        it "wraps around" to the first index using the modulus operator (%) based on the fixed buffer size
    </li>
    <li>the same is true for <code>front</code></li>
    <li>in this way you can keep reusing the underlying buffer.</li>
</ul>
<img src="lab10/indicies.png">

<h3>Notes</h3>
<ul>
    <li><code>front == back</code> in two situations: full and empty. How to differentiate full from empty?</li>
<li>
    We talked about handling exceptions, but here is a reminder:
<ul>
    <li>you <code>#include&lt;stdexcept></code></li>
    <li>to use a particular error, you <code>using std::runtime_error;</code></li>
    <li>
        The C++ keyword is <code>throw</code>.
        When you throw an exception you are telling C++ and error occurred.
        That is, you have detected an error condition and are indicating the error to C++.
        You may or may not have a catcher on the other side to deal with the error,
        but that is not the focus today.
    </li>
    <li>
        If you try to access the front of an empty <code>CircBuf</code>, you should:
        <ul>
            <li><code>throw runtime_error("Accessing an empty Circular Buffer");</code></li>
        </ul>
    </li>
    <li>There are a couple of predefined errors in C++, one is a <code>runtime_error</code>. That is as good as any other for this case.</li>
    <li>
        When you <code>throw</code> the error,
        you are actually making an instance of the <code>runtime_error</code> class.
        The constructor can take a string argument which is stored in the error and can be used to help sort out the error.
    </li>
    <li>
        There is an example of a catch (how to deal with an error) in the "main.cpp" if you want to see how it works.
    </li>
</ul>
</li>
</ul>

<h3>Test</h3>
<p>
    Implement your class and get it to run with the provided <a href="lab10/main.cpp">main.cpp</a>.
    You output should look exactly like the following:
</p>
<pre>
Front:1
DUMP Front:1, Back:2, Cnt:1
1, 2, 0, 0,

Front:2
Empty?:true
DUMP Front:2, Back:2, Cnt:0
1, 2, 0, 0,

Add 4 elements
DUMP Front:2, Back:2, Cnt:4
29, 30, 27, 28,

Remove all elements
Elements removed:
27, 28, 29, 30,
DUMP Front:2, Back:2, Cnt:0
29, 30, 27, 28,

Fill er up
Full?: true
DUMP Front:2, Back:2, Cnt:4
4, 9, 0, 1,
Drain it
Empty?:true
Yo, cannot access an empty buffer. Real error msg follows
Accessing an empty Circular Buffer</pre>
<p>
    <img src="Red_star.svg" style="width:1cm">
    Show your TA when you complete this portion of the lab.
</p>

<h3>More Overloading</h3>
<ul>
    <li>
        <p>
            It might seem a little odd, but you could overload the <code>+</code> operator to place the next element
            in the buffer (a different way to do add). It would have to allow statements like the following.
        </p>
        <pre>
cb = cb + 5;
cb = 5 + cb;</pre>
        <p>
            In this case, the operator would make a new CircBuf,
            with the element added to the end.
            Thus this would be the addition of a CircBuf and a long.
        </p>
        <p>
            What to do for the fixed size of the newly made CircBuf?
            You could make the new buffer a straight copy of cb and throw an error
            if it exceeds the size. If not big enough, you could also make it one bigger.
            Which would be better?
        </p>
    </li>
    <li>
        <p>
            If you are <b>really</b> bored, you could create the addition of two CircBuf.
            It would take the two contents and combine them. Order here would be important
            (contents of the lhs first followed by the rhs).
        </p>
        <pre>
cb = cb + another_buff  # cb contents first, another_buf second
cb = another_buf + cb   # another_buf contents first, cb second</pre>
        <p>
            Again, what to do with the fixed size of the returned buffer?
            This is a tougher call. It seems likely that the combined buffers could be too big
            (bigger than either of the two argument CircBufs).
            Should we throw an error or make the new CircBuf big enough to hold the result?
            Interesting problem.
        </p>
    </li>
</ul>
<p>See, class design can be lots of fun!?</p>
<p>
    <img src="Red_star.svg" style="width:1cm">
    Show your TA when you complete the lab.
</p>


-->

