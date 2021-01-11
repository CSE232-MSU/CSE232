---
title: Lab - Vectors and Multi-File Compilation
---

# Lab - Vectors and Multi-File Compilation

## Miscellaneous Bash Stuff

### Command Completion

A common mistake when writing in any programming language is that of typos. One way to avoid them is to use an autocompletion feature so you don't have to type out a full name or variable. When you hit the TAB key, the terminal attempts to fill the rest of the command/file name you are typing. If there isn't a unique match (for instance, you are typing: `cp fi` and then hit TAB when there are files with the names "file_01" and "file_02" present), it will fill in as much as it can (in this case "`cp file_0`"). If you hit TAB again, the terminal will present the potential options that it can autofill with. You can specify more characters until a unique match is found.

Example:

```bash
cp f                # hit TAB
cp file_0           # hit TAB
cp file_02 f        # hit TAB
cp file_02 file_0   # hit TAB
cp file_02 file_01  
```

I recommend making use of TAB completion. We, humans, are prone to making typos, where our computer friends are not.

### `history`

The terminal remembers each command you type into it in its history. When you execute the `history` command, the terminal will report each command run with a number. Example:

```bash
  495  ls
  496  cd ../../
  497  ls
  498  ls
  499  cd ..
  500  cp file_02 file_01
  501  history
```

You can run a command from your history by noting its number. For instance, `!500` will run the `cp file_02 file_01` command again.

You can also use the `!!` command to re-execute the latest command.

### Configuration (.bashrc and .bash_profile)

Sometimes, there are bash commands you always want to run before you get to work. Perhaps, you want your terminal to configure some settings, or tell you how much disk space is left on the computer. To make this easier, there are two config files that bash looks for (in your home directory).

.bashrc is a bash script that runs everytime you invoke the `bash` command (example: `bash my_script.sh`) and when you login. .bash_profile is a script that runs when you login to your user account. Both of these are used to execute bash commands that set up your environment.

Your PATH is a list of directories that bash (or tcsh, which is the default on the lab computers) looks in when trying to run a command. Bash looks through every folder in the list (in order), trying to find a program named identically to your command input.

You can see your path by `echo`'ing it to the screen with:

```bash
echo $PATH
```

In the bash and tcsh shells, it outputs something like:

```
/soft/linux/bin:/bin:/usr/bin:/usr/sbin:/usr/X11R6/bin:/usr/cpssbin:/soft/linux/bin:/usr/X11R6/bin:/usr/local/bin:
```

This means that if I try to run `say_hello Josh`, it looks in `/soft/linux/bin` for an executable called `say_hello`, and if it can't find it, it then looks in `/bin`, then in `/usr/sbin`, and so on before giving up (the `:` character delimits the paths).

Sometimes it is useful to add other directories to this path (often for programs you want to call from the command line).

If I want to add the folder "`~/joshs_programs/`" to my PATH, because it has useful programs to run at the command line, I can add them like this:

```bash
export PATH=$PATH:~/joshs_programs      # for bash
```

```tcsh
setenv PATH $PATH\:~/joshs_programs     # for tcsh (on lab computers)
```

However, this change to the PATH will only last as long as your terminal session lasts (when you log out, it'll be gone). You'll want to add that line to your .bashrc or .bash_profile (or .tcshrc) config file if you want that in your path for future sessions.

⭐ Add the Desktop to your PATH and `echo` your PATH for the TA.

## Multi-File Compilation

Imagine that you've written a really useful function. You would like to package that function individually so you can use it in other programs. The hard way to accomplish that would be to copy that function into every new program where you might want to use it. A better idea would be to place that function in its own separate file, and then compile any new program and your trusty function into one executable. That would be lovely!

Remember this picture?

<div align="center">
<img src="../assets/images/compiler_parts.png">
</div>

`g++` (the underlying compiler) does all of these steps rather invisibly. To take advantage of it, we'll need multiple files.

### Header Files

If we are going to define a function in one file, and use that function in a separate main file, we are going to have to find a way to inform the main file about the _types_ of that function. That is, we have to tell the main file:
- The function's name,
- The type it returns,
- And the types of the parameters

The _name_ of each parameter is unimportant. It can be given, changed in the main file, or left-out. All that matters is each parameter's _type_.

If we tell the main file this information, that is enough for the C++ compiler to check that the function is being used correctly, and by "correctly", I mean that the main file is using all of the _types_ correctly in calling the function, even though it does not yet have the actual function _code_.

Providing this information is the job of a **header file**. Header files are typically written with a ".hpp" or ".h" extension, and are used to indicate the type information for C++ elements (functions, classes, or some other C++ thing). This header file is used by the compiler to ensure that, whoever is using this function, they are at least using the types correctly. Thus, without the function itself, we can know that we followed the compiler rules and used the correct types.

### Example

Make a new folder somewhere, and call it "lab6" (either with your File Explorer or the command line).

If you don't remember, you can make an empty folder by using the `mkdir` command (on Unix):

```bash
mkdir lab6
```

[Download, and extract the files in this .zip folder linked here](../assets/downloads/lab_vactors.zip). Copy these files into your lab6 folder.

Navigate your terminal to the folder, then, compile your three files with the following command:

```bash
g++ -std=c++17 -Wall  *.cpp
```

This command will compile all (`*` means all, `*.cpp` means all files ending in .cpp) the .cpp files and build an executable.

### Some Warnings

It's nice that the previous command compiles all of the files, but if you have too many files (like from different projects, or from things you were working on temporarily, etc.) it won't work. Instead, you can do it with a list of files. You can even name your executable using the `-o` flag, to be something other than the standard "a.out".

```bash
g++ -std=c++17 -Wall file1.cpp file2.cpp file3.cpp -o namedExecutable.exe
```

Something important to note, is that __we never compile header files__. All a header file provides is a list of declarations to be used by other files.

⭐ Show the TA that you downloaded the three files, compiled them, and successfully ran the executable.

### The Files

extra.cpp defines the function, `extra()`, which will be used in the main.cpp program.

extra.hpp is the header file. Notice that it only provides the declaration of the function. In the declaration, the names of the parameters are not required, only their types. **Note that the function declaration ends in a semicolon, don't forget!** There are some weird `#` statements, as you probably noticed. We'll get to those in a bit.

main.cpp is the main program. Notice that it has the following statement in it:

```c++
#include "extra.hpp"
```

This means that the main program is _including_ the declaration of the function so that the compiler may check the type use of `extra()` by main.cpp. Notice the quotes; when the `#include` expression uses quotes, it is assumed that the .hpp file is in the same directory as the other files. Include statements with angled-brackets (`<>`) denote the "standard include place" to the compiler. Since it is our own include file, we need to use quotes for it.

### The `#` Symbol

Anything beginning with `#` is part of the pre-processor. This controls aspects of how the compilation goes. In this case, we are trying to prevent a multiple definition error. What if we wanted to use `extra()` in more than one file? Your expectation is that every file that wants to use `extra()` should include the extra.hpp file for compilation to work, and you would be correct... sort of. Remember that you cannot declare a variable more than once, and the same goes for a function -- you should only declare it once. In making one executable from many files, it is possible that, by including extra.hpp in multiple files, we would declare the `extra()` function multiple times for this single executable, and C++ would complain. However, it would be weird to have to do this in some kind of order where only one file included extra.hpp, and the rest would have to assume it is available.

The way around this involves the pre-processor. Basically, there are three statements we care about:

```c++
#ifndef SOME_VARIABLE_NAME
#define SOME_VARIABLE_NAME

/*
put all *declarations* here
*/

#endif
```

This means: "if the pre-processor variable we indicate (`SOME_VARIABLE_NAME`) is not defined (`#ifndef`), go ahead and define it (`#define`) for this compilation and do everything else up to the `#endif`, (i.e., include these declarations in the compilation). If the variable is already defined, skip everything up to the `#endif` (i.e., skip the declarations)."

Thus, whichever file pulls in the header file first, defines the pre-processor variable and declares the function for the entire compilation. If some other file also includes the header file later in the compilation, the pre-processor variable is already defined, so the declarations are not included.

Of course, the simpler solution is to make use of the (not-yet-standardized) `#pragma once`. It is your call.

## Coding Assignment

Make a new folder in your lab 6 directory called "splitter", and add three new files to it: main.cpp, functions.cpp and functions.hpp.

&nbsp;

```c++
vector<string> split(const string &s, char sep=' ')
```

The `split()` function should take in a `string` and return a `vector<string>` of the individual elements in the string that are separated by a given separator character (default of `' '`). Examples: 

`split("hello mom and dad")` should return `{"hello", "mom", "and", "dad"}`

`split("1,2,3,4", ',')` should return `{"1", "2", "3", "4"}`

Open functions.hpp, and store the function declaration of `split()` there. The declaration should be the snippet of code above **with a semicolon at the end, don't forget!**.

As discussed in lecture, default parameter values **go in the header file only**. The default does not occur in the definition if it occurred in the declaration.

This header file should wrap all declarations using the `#ifndef`, `#define`, and `#endif` pre-processor statements, as discussed above. Make up your own variable name.

Open functions.cpp, and write the definition of the function, `split()`, there. Make sure it follows the declaration in functions.hpp. The parameter names do not matter, but the types do. Make sure the function signature matches for both the declaration _and_ definition.

You can compile functions.cpp (not build, at least not yet) to see if functions.cpp file is well-formed for C++. It will not build an executable, but instead a .o (object) file. The object file is the result of compilation before building an executable -- an in-between stage.

⭐ Show your TA the object file generated after compiling the functions.cpp file.

&nbsp;

```c++
void print_vector(ostream &out, const vector<string> &v)
```

This function prints all the elements of `v` to the output stream, `out`. Note that `out` and `v` are passed by reference.

Store the function in functions.cpp, and put its declaration in functions.hpp like you did for `split()`. **Don't forget the semicolon!**

Compile the function (not build, compile) to make sure it follows the rules.

**Note**: `ostream` is a category of all possible output streams (streams like `cout` and `ostringstream`). This function should be invoked with a specific `ostream` (either `cout` or `ostringstream`).

&nbsp;

Your `main()` function should go in main.cpp.

In main.cpp, be sure to `#include "functions.hpp"` (note the quotes). This makes all of the functions in functions.hpp available to main.cpp. 

Write a `main()` function that:
1. Prompts for a string to be split
2. Prompts for the single character to split the string with
3. Splits the string using the `split()` function (which returns a `vector<string>`, remember)
4. Prints the vector using the `print_vector()` function

Compile (not build) main.cpp to see that it follows the rules. If you've successfully compiled it, build the project with the output executable name as "main" to test everything.

⭐ Demonstrate a working "main" executable to your TA.

&nbsp;

### Assignment Notes

1. Consider using the `getline()` function for your implementation of `split()`.
    - `getline()` takes a delimiter character as a third argument. In combination with an input string stream, you can use `getline()` to split the string and `push_back()` each element onto the vector. 
    - Example: a call to `getline(stream, line, delim)` gets the string from `stream` (could be an `istream`, `ifstream`, `istringstream`, etc.) up to the end of `line`, or the `delim` character.

2. Default parameter values needs to be set at **declaration time**, which means that the default value for a function parameter should be in the header file (where the declaration is). If it is in the declaration, it should not be in the definition.
