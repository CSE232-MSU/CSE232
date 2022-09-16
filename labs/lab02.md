---
title: Lab - Input and Output
---

# Lab - Input and Output

## Directory Navigation in the Terminal

At the beginning of most labs, there will be a section on new skills to make you more proficient at the command line. Many tasks are easiest to perform at the terminal, so becoming comfortable there is important. Many of the labs after this one will expect a basic familiarity of the command line, so pay special attention to these sections.

Log into the Coding Rooms Assignment and open the IDE. Use the shell in Coding Room's IDE to follow along.

### `pwd`

The first command you need to learn is one of the simplest, `pwd`. At the terminal, type the command `pwd` and hit enter.

`pwd` is short for "print working directory". It outputs the path of the working directory i.e., the series of nested folders that your terminal currently has open. If you get lost, (and it is easy to do with only the text-based terminal for navigation), `pwd` will show you where you are.

### `ls`

The `ls` command outputs the names of all of the folders and files in the working directory. `ls` is short for "list" (as in "list" the contents).

Depending on your terminal's configuration, folder names may end with a `/`, or be denoted in some other form. Some terminals also add colorized output to `ls` to denote different types of files. For instance, Coding Rooms' shell has folders in blue, and files in white.

### `mkdir`

The `mkdir` command is short for "make directory" and allows you to create a new folder in the current working directory.

Try:

```bash
mkdir my_folder
```

This will create a new sub-folder called "my_folder".

### `cd`

The `cd` command is short for "change directory". It allows you to change your working directory to a different folder.

Lets say you run `pwd` and you get the output of:

```bash
/home/joshua/cse_232__summer_202X/lab02_new_horizons
```

Your current working directory is named "lab02_new_horizons". If you run `ls`, you would get:

```bash
my_folder
new_horizons.cpp
```

This means that there are two items in this folder, a file called "new_horizons.cpp" ad a subfolder named "my_folder".  If you wanted to do things in your subfolder, use the `cd` command:

```bash
cd my_folder
```

Then you would be in the folder named "my_folder", you can confirm such with `pwd` and `ls`.

### Special Directory Names

There are a few "special" directory names that you need to know. The first is the home directory. This directory's name is usually the username of the account, and it contains all of the user's files and folders. Inside the home folder is the "Desktop" folder (for all the things on your desktop), the "Downloads" folder and other folders as well (like "Music", "Videos", "Applications", etc.). The home folder is often specified using the tilde symbol (`~`). So if you want to `cd` to your home folder, run:

```bash
cd ~
```

**Note**: on most systems, running `cd` with no arguments also takes you to the home folder.

Sometimes you want to go the parent folder of your working directory. In the example above, we moved from the folder "lab02_new_horizons" to its imaginary subfolder "my_folder". Trying to get back by running...

```bash
cd lab02_new_horizons
```

...would fail because there is no folder named "lab02_new_horizons" in "my_folder".

The way to go to the parent directory (in this case, "lab01_new_horizons"), you need to run:

```bash
cd ..
```

The `..` is a strange way to symbolize the parent directory. In fact, `.` denotes the current working directory, a fact that will be useful to know in later labs.

The last "special" directory is the root directory. The root directory is the directory that is the ultimate parent of all the other directories on the computer. It is denoted by a single `/` symbol. In fact, you can specify any folder on the computer by starting with the root directory and working your way to the directory you actually want. So the path `/home/joshua/cse_232__summer_2023/lab02_new_horizons` specifies that the folder I want is:

- In the root folder (the starting `/`)
- In the folder named "home"
- In the folder named "joshua"
- In the folder named "cse_232__summer_2023"
- And it is named "lab02_new_horizons"

⭐ Please show your TA that you can use the commands: `pwd`, `ls`, `mkdir`, and `cd`.

### Formatting your code

The C++ compiler is extremely permissive as to the format of the code it accepts.  All whitespace (spaces, tabs, newlines) is treated the same and in most cases isn't even needed.

For example, consider the code snippet (don't worry about understanding it yet):

```c++
if (last_name == "Nahum") {
  std::cout << "Hello Dr. Josh!" << std::endl;
}
```

It will function identically if we change all of the spacing:

```c++
if(
last_name ==
"Nahum" ){std::cout<<
    "Hello Dr. Josh!"      <<std::endl;}
```

However, our brains have a harder time parsing poorly formatted code. We will cover how to format your code manually, but there is a nice tool to format your code automatically: `clang-format`. The details for how the tool can be configured [can be found here](https://clang.llvm.org/docs/ClangFormat.html).

Let's say you have a file named "main.cpp". To use `clang-format` to auto-format your code, run:

`clang-format --style=Google -i main.cpp`

The above line will format the main.cpp file according to the Google Style Guide (more on that later).

To install `clang-format` on Coding Rooms, run:

`sudo apt install clang-format`

and specify `Y` at the confirmation step.

## Coding Assignment

### Background

The New Horizons spacecraft, launched January 19th 2006, is the first earth spacecraft to have made contact with the planet, Pluto. On January 1st, 2019 it was scheduled to make contact with the first Kuiper belt object, KBO-2014-KU69. The [NASA update page](http://pluto.jhuapl.edu/Mission/Where-is-New-Horizons/index.php) reported it at a distance of 37.33 Astronomical Units (AU) from the Sun, traveling away at 14.33 km/sec (8.90 mi/sec) on 12/30/2016.

For this lab, you will use the `cin` and `cout` streams, along with some simple mathematics for calculating New Horizon's distance from the Sun. The important part of the assignment is to learn the skills needed to access the class website, access a project description, and create a new program in C++.

### Program Specifications

Your program will prompt the user for an integer number (a number without decimal points) that indicates the number of days _after_ 12/30/2016, starting at a distance 37.33 AU from the Sun. You will calculate the distance of New Horizons from the Sun using the above numbers from 12/30/2016 (assume velocity is constant) _plus_ the user provided number of days, and report:

- Distance in kilometers (1 AU = 149,598,000 km) on a line by itself
- Distance in miles (1 AU = 92,955,800 mile) on a line by itself
- Round trip time for radio communication in hours. Radio waves travel at the speed of light, listed at 299,792,458 meters/second, on a line by itself
  - In actuality, the orbital mechanics needed to actually model this are beyond the scope of this lab. But for simplicity, you can assume the radio station is on the sun. 
- Provide 2 decimal points of accuracy using `std::fixed` and `std::setprecision`. Both are contained within the `<iomanip>` header, and you can use them as follows:

```c++
std::cout << std::fixed << std::setprecision(2);
```

⭐ Please show the TA your working program.

### Assignment Notes

There is a Coding Rooms assignment for this lab that you can use to test your program.

There are some rounding issues here, so be careful! To make the kilometer/mile calculations, use the constants (speed and distance) provided. To make the round trip calculation, use your distance in km and the speed of light constant provided. You'll get slightly different answers if you try to convert the two distances or the two speeds.

You will need to work with the `cin` and `cout` streams and their operators `>>` (for `cin`) and `<<` (for `cout`). You will also need to declare the appropriate variables: `int` (a 64 bit integer) for values like days, and `double` for calculation values.

`cout` takes either variable values or strings (between `" "`) and outputs them to the console. You can use multiple `<<` operators on the same cout stream, usually ending with `endl`. 

Assuming the variable, `int_var`, has the value 23...

```c++
std::cout << "This is a string: " << int_var << " the end"
          << std::endl;
```

...this small program would output:

```
This is a string: 23 the end
```

`cin` will take an input value from the command line into a variable of _a particular type_. It does so until it hits a space (space separated values) or an end of a line. For example:

```c++
std::cin >> int_var;
```

If you run the program and then enter an integer value to the command line, it will be read into the variable with no conversion required.

```c++
int multiplier
std::cin >> number;
int number;
std::cin >> multiplier;

std::cout << "The number " << number << " times "<< multiplier
          << " is " << number * multiplier << std::endl;
```

With inputs 10 and 2 respectively, we get:

```
The number 10 times 2 is 20
```

The operations on these numbers are: + (sum), - (difference), * (product), / (division) and % (modulus, integer only). The last two deserve special comment.

If an integer is divided by another integer, the result is an integer, with any would-be decimal always rounded down. Thus the result of `6 / 4` is `1`. In contrast, `6.0 / 4` is `1.5`. That is, the decimal point in the first values indicates that we are using a floating point value, and the `/` operator results in the **integer quotient if using integers, and floats if using floats**.

The result of `6 % 4` is the integer remainder of the division, thus `2` (6 divided by 4 is 1, with a remainder of 2). There is no symbol equivalent for `%` in floating point math.

### Things to Think About

- What happens when you try to divide by zero when you run your program?
- What happens when `std::cin` obtains a letter instead of a number?


## Honors Material - Writing Programs for the Command Line

In the lab above you learned how to use a command line and how to write simple C++ programs.  Here, you will learn how to combine the two and write your own program that accepts arguments from the command-line.

### Background

All C++ programs must begin with a `main()` function, but it turns out that your main function can also take specific "arguments", which will be generated on the command line.  (you will learn more about functions and arguments in lab 4)

Try out this program:

```c++
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "The name of this program is: " << argv[0] << std::endl;

  if (argc > 1) {
    std::cout << "A total of " << argc << " words were typed to run this command" << std::endl;
    std::cout << "The first argument is: " << argv[1] << std::endl;
  } else {
    std::cout << "No arguments provided." << std::endl;
  }
}
```

Compile it and run it.  Now try running it again with some arguments; for example:

```bash
  ./a.out one two three
```

You should see as output:

```
The name of this program is: ./a.out
A total of 4 words were typed to run this command
The first argument is: one
```

Looking back at the program, here are some key ideas to understand.

The variable `argc` will automatically be set to the count of "words" that were used on the command line (where words can be filenames, numbers, paths or anything separated by spaces).  You can use this value to know how many arguments were provided by the user.  Note that this DOES count the name of the executable itself, so it will never be less than one.

The variable `argv` holds the set of all of arguments that were passed in as strings.  You use `[` and `]` around a number to indicate which argument you are interested in.  The name of the program being run will always be argv[0].  The rest may or may not exist depending on what else the user typed on the command line.  You need to make sure that you check to make sure argc is large enough -- if you try to access a command-line argument that doesn't exist, your program won't work correctly.

### Assignment

There is a Coding Rooms honors assignment for this lab that you can use to test your program.

You are going to write a simple command-line adder.  To do so, use the main function with `argc` and `argv` exactly as in the sample program above.  You will also need to be able to convert the command-line inputs to numbers, find the sum of those numbers, and output the results.

How do you convert an command-line argument into a number?  You need to use the function `atoi()`.  This function can be found in the header `cstdlib`, which you can access by putting a `#include <cstdlib>` at the top of your program.

In order to use `atoi()` simply send it the argument that you want converted and it will return the corresponding integer value.  For example:

```c++
  int first_argument = std::atoi(argv[1]);
```

For this implementation, you must look at the number of inputs (`argc`) and add up one, two, or three command line values, outputting the results.  If no command-line arguments are provided, you should print "No inputs."  If more than three arguments are provided, print "Too many inputs."  Otherwise print a single number representing the sum of the values included.

### Trivia

If you are curious about where the above names come from, this section will fill in those details. (If you don't care, feel free to skip, but often understanding context will help you figure out other details about the language that you encounter in the future.)

The include file [`cstdlib`](https://en.cppreference.com/w/cpp/header/cstdlib) is short for the "C Standard Library".  As you know, the C++ language is a extension of the older [C language](https://en.wikipedia.org/wiki/C_(programming_language)), with many additional features.  The C++ standard library has many different files that you can include with useful functionality.  The original C library was smaller, with a number of core functions stored in a header file called `stdlib.h` (and others in files like `math.h` or `string.h`).  C++ kept all these functions but renamed the header files dropping the `.h` and putting a c out front (so `cstdlib`, `cmath`, `cstring`, etc.)  You'll find other functionality in cstdlib, such as exit() for terminating a program early, or rand() for generating a pseudo-random number.  Most of these functions have improved versions in the more modern C++ library, but command line arguments haven't been updated since they were created in C.

The specific function that you used above, [`atoi`](https://en.cppreference.com/w/cpp/string/byte/atoi) stands for "ASCII to Integer".  [ASCII](https://en.wikipedia.org/wiki/ASCII) is the name for the default encoding of characters used to make strings in C and C++.  In ASCII, the values zero through 127 each have a special meaning, covering the alphabet (upper- and lowercase letters), digits, punctuation symbols, and a number of special characters (newlines, tabs, etc.).  This function will read in the digits encoded at the beginning of a string and convert them to their numerical (integer) value in C++.
