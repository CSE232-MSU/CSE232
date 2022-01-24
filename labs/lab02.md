---
title: Lab - Input and Output
---

# Lab - Input and Output

## Directory Navigation in the Terminal

At the beginning of most labs, there will be a section on new skills to make you more proficent at the command line. Many tasks can only be performed at the terminal (or are easier to perform at the terminal), so becoming comfortable there is important. Many of the classes after this one will expect at least a basic familiarity of the command line, so pay special attention to these sections.

Log into the Coding Rooms Assignment and open the IDE. Use the shell in Coding Room's IDE to follow along.

### `pwd`

The first command you need to learn is one of the simplest, `pwd`. At the terminal, type the command `pwd` and hit enter.

`pwd` is short for "print working directory". It outputs the path of the working directory i.e., the directory your terminal currently has open. If you get lost, (and it is easy to do with only the text-based terminal for navigation), `pwd` can show you where you are.

### `ls`

The `ls` command outputs the names of all of the folders and files in the working directory. `ls` is short for "list" (as in "list" the contents).

Depending on your terminal's configuration, folder names may end with a `/`, or be denoted in some other form. Some terminals also add colorized output to `ls` to denote different types of files. For instance, Coding Rooms' shell has folders in blue, and files in white.

### `cd`

The `cd` command is short for "change directory". It allows you to change your working directory to a different folder.

Lets say you run `pwd` and you get the output of:

```bash
/home/joshua/cse_232__summer_202X/lab02_new_horizons
```

Your current working directory is named "lab02_new_horizons". If you run `ls`, you would get:

```bash
new_horizons.cpp
```

This means that there is only one thing in this folder, a file called "new_horizons.cpp". 

However, if there was a subfolder in your working directory named "my_folder", you would see it listed by `ls`. If you wanted to do things in that subfolder, you would use the `cd` command like so:

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

The `..` is a strange way to symbolize the parent directory. In fact, `.` denotes the working directory, a fact that will be useful to know in later labs.

The last "special" directory is the root directory. The root directory is the directory that is the ultimate parent of all the other directories on the computer. It is denoted by a single `/` symbol. In fact, you can specify any folder on the computer by starting with the root directory and working your way to the directory you actually want. So the path `/home/joshua/cse_232__summer_2023/lab02_new_horizons` specifies that the folder I want is:

- In the root folder (the starting `/`)
- In the folder named "home"
- In the folder named "joshua"
- In the folder named "cse_232__summer_2023"
- And it is named "lab02_new_horizons"

⭐ Please show your TA that you can use the commands: `pwd`, `ls` and `cd`.

### Formatting your code

The C++ compiler is extremely permissive as to the format of the code it accepts. However, our brains have a harder time parsing poorly formatted code. We will be covering how to format your code manually, but there is a nice tool to format your code automatically: `clang-format`. The details for how the tool can be configured [can be found here](https://clang.llvm.org/docs/ClangFormat.html), but for this course, all that is needed is to log into chuck.egr.msu.edu to use the tool.

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

Your program will prompt the user for an integer number (a number without decimal points) that indicates the number of days _after_ 12/30/2016, starting at a distance 37.33 AU from the Sun. You will calculate the distance of New Horizons from the Sun using the numbers from 12/30/2016 (assume velocity is constant) _plus_ the user provided number of days, and report:

- Distance in kilometers (1 AU = 149,598,000 km) on a line by itself
- Distance in miles (1 AU = 92,955,800 mile) on a line by itself
- Round trip time for radio communication in hours. Radio waves travel at the speed of light, listed at 299,792,458 meters/second, on a line by itself
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

If you enter an integer value to the command line, it will be read into the variable with no conversion required.

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

If an integer is divided by another integer, the result is an integer. Thus the result of `6 / 4` is `1`. In contrast, `6.0 / 4` is `1.5`. That is, the `/` operator results in the **integer quotient if using integers, and floats if using floats**. The result of `6 % 4` is the integer remainder of the division, thus `2` (6 divided by 4 is 1, with a remainder of 2). There is no equivalent for `%` in floating point math.

### Things to Think About

- What happens when you try to divide by zero when you run your program?
- What happens when `std::cin` obtains a letter instead of a number?
