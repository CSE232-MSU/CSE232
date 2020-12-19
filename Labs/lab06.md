# Lab 06 - Vectors and Multi-File Compilation

## Miscellaneous Bash

The following topics are useful information for effectively using the terminal (and its language, BASH).

### Command Completion

One very common mistake in typing in any programming language are small typos that break your program or instruction. One way to avoid them is to use an autocompletion feature so you don't have to type out a full name or variable. When you hit the `TAB` key, the terminal attempts to fill the rest of the command of filename you are typing. If there isn't a unique match (for instance, you are typeing: "cp fi" and then hit TAB when there are files with the names "file_01" and "file_02" present), it will fill in as much as it can (in this case "cp file_0"). If you hit TAB again, the terminal will present the potential options that it can autofill with. You can specify more characters until a unique match is found.

Example:

<pre>cp f<TAB>
cp file_0<TAB>
cp file_02 f<TAB>
cp file_02 file_0<TAB>
cp file_02 file_01</pre>

I recommend making use of tab completion as the terminal doesn't make typos, and humans do.

### History

The terminal remembers each command you type into it in its `history`. When you execute the `history` command, the terminal will report each command run, with a number. Example:

<pre>  495  ls
  496  cd ../../
  497  ls
  498  ls
  499  cd ..
  500  cp file_02 file_01
  501  history</pre>

You can run a command again by noting its number. For instance, `!500` will run the `cp` command again.

A neat trick is the `!!` command which runs the last command again.

### Configuration (.bashrc and .bash_profile)

Sometimes there are bash commands you always want to run before you get to work. Perhaps, you want your terminal to configure some settings, or tell you how much disk space you have left. To make this easier, there are two config files that BASH looks for (in your HOME directory).

.bashrc is BASH script file is run everytime you invoke bash (example: `bash my_script.sh`) and when you login in. .bash_profile is a script that runs when you login to your user account. Both of these are used to execute BASH commands that set up your environment.

### $PATH

Your PATH is a list of directories that BASH (or tcsh, which is the default on the lab computers) looks in when trying to run a command. BASH looks through every folder in the list (in order) trying to find a program named the same as your command.

You can see your path by 'echo'ing it to the screen with:

<pre>echo $PATH</pre>

In the BASH and tcsh shells it outputs something like:

<pre>/soft/linux/bin:/bin:/usr/bin:/usr/sbin:/usr/X11R6/bin:/usr/cpssbin:/soft/linux/bin:/usr/X11R6/bin:/usr/local/bin:</pre>

This means if I try to run `say_hello Josh`, it looks in `/soft/linux/bin` for an executable called `say_hello`, and if it can't find it, if then looks in `/bin`, then in `/usr/sbin`, and so on before giving up.

Sometimes it is useful to add other directories to this path (often for programs you want to call from the command line). You do so by adding the directory to the PATH. Example, I want to add the folder `~/joshs_programs/` to my PATH because it has useful programs to run at the command line.

<pre>export PATH=$PATH:~/joshs_programs # for bash
setenv PATH $PATH\:~/joshs_programs # for tcsh (on lab computers)
</pre>

However, this change to the PATH will only last as long as your terminal session lasts (when you log out it is gone.) You want to add that line to your .bashrc or .bash_profile (or .tcshrc) config file if you want that in your path for future sessions.

![](Red_star.svg) Add the Desktop to your PATH and echo your PATH for the TA.

## Lab Assignment

### The Problem

We are going to work on two things:

1.  First lab coding vectors
2.  Understanding how we can break our program out into different files and create one executable from those files

We start with the second part. However, look for your programming tasks (there are two) to accomplish at the end of this file. Don't forget!!!

### Separate Compilation of Files

#### Why?

Imagine that you write a really useful function (which hopefully you will today). You would like to package the function up individually so you could use it in other programs. The hard way to accomplish that would be to have to copy that function into every new program where you might want to use it. A better idea would be to place that function in its own separate file, and then compile any new program and your trusty function into one executable. That would be lovely!

#### How?

Remember this picture?

![](lab06/compiler_parts.png)

g++ (the underlying compiler) does all of these steps rather invisibly. To take advantage of it, we need multiple files.

#### Header Files

If we are going to define a function in one file and use the function in a main file, we are going to have to find a way to inform the main file about the **types** of the function. That is, we have to tell the main file:

*   the function's **name**
*   the **type** the function returns
*   the **type** of the parameters the function uses
    *   the **name** of each parameter is **unimportant**. It can be given, changed in the main function or just left out. All that matters is each parameter's **type**

If we tell the main function this information, that is enough for the C++ compiler to check that the function is being used correctly in main, and by correctly I mean that main is using all the types correctly in calling the function, even though it does not yet have available the actual function code.

Providing this information is the job of a _header file_. Header files that users write typically end in `.hpp`, and are used to indicate the type information of a some C++ elements (of functions, or classes, or some other C++ thing). This header file is used by the compiler to make sure that, whoever is using this function, they are at least using the types correctly. Thus without the function itself, we can know that we followed the compiler rules and used the correct types.

#### Example

Make a new directory/folder, call it lab6, as you have been doing all along (either with your File Browser and the Create Folder dropdown or with the command line command mkdir).

The `mkdir` command takes a folder name and creates that (empty) folder. Example:

<pre>mkdir lab6</pre>

Download the following three files. Copy these files to your desktop (easiest, right click each file, then Save As into your lab 6 directory/folder).

*   [main.cpp](lab06/main.cpp)
*   [extra.cpp](lab06/extra.cpp)
*   [extra.hpp](lab06/extra.hpp)

Navigate your terminal to the "lab6" folder. Then compiler your three files with the following command:

<pre>g++ -std=c++17 -Wall  *.cpp</pre>

That means, it will compile all (* means all names, *.cpp means all files ending in .cpp) the .cpp files and build an executable.

##### Two warnings!

1.  It's nice that the previous command compiles all the files, but if you have too many files (from different projects, things you are working on temporarily etc.) it won't work. Instead, you can do it with a list of files. You can even name your executable using the -o modifier to be something than the dreaded `a.out`.

    <pre>g++ -std=c++17 -Wall file1.cpp file2.cpp file3.cpp -o namedExecutable.exe</pre>

2.  We never compile a `.hpp` file. That doesn't make any sense. All a .hpp file provides is a list of declarations to be used by other files. It is never compiled and would not show up in the list of files to compile (shown above).

![](Red_star.svg) Show your TA that you got the three files, made a project, compiled and ran it.

#### The Files

*   `extra.cpp` : It defines the function `extra` which will be used in the `main` program.
*   `extra.hpp` : This is the header file. Notice that is only really provides the declaration of the function.
    *   In the declaration, the names of the parameters are not required, only their types.
    *   Note that the function declaration **ends in a ; (semicolon)**. Don't forget!!!
    *   There are some weird # statements, we'll get to that.
*   `main.cpp` : This is the main program. Notice that it has the following statement in it:

    <pre>#include "extra.hpp"</pre>

    This means that the main program is "including" the declaration of the function so that the compiler may check the type use of `extra` by `main`. Notice the quotes. When the `include` uses quotes, it is assumed that the .hpp file is in the same directory as the other files. Includes with `<>` means get the includes from the "standard include place". Since it is our include file, we need to use quotes for it.

#### Weird # in headers

Anything beginning with `#` is part of the pre-processor. This controls aspects of how the compilation goes. In this case, we are trying to prevent a multiple definition error. What if we wanted to use `extra` in a more than one file? Your expectation is that every file that wants to use extra should include the `extra.hpp` file for compilation to work, and you would be correct. Sort of. Remember that you cannot declare a variable more than once, and the same goes for a function. You should only declare it once. In making one executable from many files, it is possible that, by including `extra.hpp` in multiple files, we would declare the extra function multiple times for this single executable. C++ would complain. However, it would be weird to have to do this in some kind of order where only one file included `extra.hpp` and assume the rest would have to assume it is available.

The way around this involves the pre-processor. Basically there are three statements we care about:

<pre>#ifndef SOME_VARIABLE_NAME
#define SOME_VARIABLE_NAME</pre>

... all the **declarations** in this .hpp file

<pre>#endif</pre>

This means. "If the pre-processor variable we indicate (`SOME_VARIABLE_NAME`) is not defined (`#ifndef`), go ahead and define it (`#define`) for this compilation and do everything else up to the `#endif`, meaning include the declarations in the compilation. If the variable is already defined, skip everything up to the `#endif`, meaning skip the declarations"

Thus whichever file pulls in the header file first, defines the pre-processor variable and declares the function for the entire compilation. If some other file also includes the header file later in the compilation, the pre-processor variable is already defined so the declarations are not included.

Of course, the simpler solution is to make use of the (not-yet-standardized) `#pragma once`. Your call.

### Programming Task 1

Make a new project in your lab 6 directory called `splitter`. We want to add three new files to the project: `main.cpp`, `functions.cpp` and `functions.hpp`.

*   Make a new file, then save it as `main.cpp`
*   Now make the `functions.cpp` and the `functions.hpp` file.

#### Function split

The `split` function should take in a `string` and return a `vector<string>` of the individual elements in the string that are separated by the separator character (default ' ', space). Thus: `"hello mom and dad"` → `{"hello", "mom", "and", "dad"}`

1.  Open `functions.hpp` and store the function declaration of `split` there. The declaration should be:

    <pre>vector<string> split (const string &s, char separator=' ');</pre>

2.  As discussed in lecture, default parameter values **go in the header file only**. The default does not occur in the definition if it occurred in the declaration.
3.  This header file should wrap all declarations using the `#ifndef`, `#define`, `#endif` as discussed above. Make up your own variable.
4.  Open `functions.cpp` and write the definition of the function `split`. Make sure it follows the declaration in `functions.hpp`. The parameter names do not matter but the types do. Make sure the function signature (as discussed in lecture) match for the declaration and definition.
5.  You can compile `functions.cpp` (not build, at least not yet) to see if `functions.cpp` is well-formed for C++. It will not build an executable, but instead a .o (object) file. The object file is the result of compilation but before building an executable, an in-between stage.

    ![](Red_star.svg) Show your TA the object file generated when compiling just the `functions.cpp` file.

#### Function print_vector

This function prints all the elements of `vector<string> v` to the `ostream out` provided as a reference parameter (it must be a reference). Note `out` and `v` are passed by reference.

*   `print_vector` : Store the function `print_vector` in `functions.cpp`, put its declaration in `functions.hpp`. It should look a lot like the below:

    <pre>void print_vector (ostream &out, const vector<string> &v);</pre>

*   compile the function (not build, compile) to make sure it follows the rules.
*   Note: ostream is a category of all possible output streams (streams like `cout` and `ostringstream`). This function should be invoked with a specific ostream (either `cout` or `ostringstream`).

#### Function main

The `main` function goes in `main.cpp`.

*   In main.cpp make sure you `#include "functions.hpp"` (note the quotes), making those functions available to `main`. Write a `main` function that:
    1.  prompts for a string to be split
    2.  prompts for the single character to split the string with
    3.  splits the string using the `split` function, which returns a vector.
    4.  prints the vector using the `print_vector` function
*   compile (not build) main to see that it follows the rules

#### Build the executable

Now build the project with the output executable name "main".

![](Red_star.svg) Demonstrate a working "main" executable.

#### Assignment Notes

Couple ways to do the `split` function

*   `getline`
    *   `getline` takes a delimiter character as a third argument. In combination with an input string stream you can use `getline` to split up the string and `push_back` each element onto the vector.
    *   Example, `getline(stream, line, delim)` gets the string from the stream (istream, ifstream, istringstream, etc.) up to the end of the line or the delim character.
*   **Default parameter value.** The default parameter value needs to be set at **declaration time**, which means that the default value for a function parameter should be in the header file (the declaration). If it is in the declaration, it is not required to be in the definition, and by convention should not be.
