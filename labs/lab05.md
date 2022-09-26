---
title: Lab - Strings
---

# Lab - Strings

## Standard Input, Output and Pipes

### I/O Redirection

Please read through this page: [http://linuxcommand.org/lc3_lts0070.php](http://linuxcommand.org/lc3_lts0070.php)

⭐ Please show the TA your sorted filenames (using `ls`, `sort` and I/O redirection).

## Coding Assignment

### Background

John Napier was a Scottish mathematician who lived in the late 16th and early 17th centuries. He is known for a number of mathematical inventions, one of which is termed _location arithmetic_.

Location arithmetic is a way to represent numbers as binary values, using a notation that is not positional, but representational. [You can read a detailed description here](http://en.wikipedia.org/wiki/Location_arithmetic), but these are the basics:

Napier used letters to represent powers of two. The position of these letters is unimportant, allowing for multiple representations of the same number. For example, in location arithmetic:

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+a+%3D+1%2C+b+%3D+2%2C+c+%3D+4%2C+d+%3D+8%2C+e+%3D+16%2C+f+%3D+32%2C+..." 
alt="a = 1, b = 2, c = 4, d = 8, e = 16, f = 32, ...">
</div>

And thus:

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+acf+%3D+1+%2B+4+%2B+32+%3D+37" 
alt="acf = 1 + 4 + 32 = 37">
</div>

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+caf+%3D+4+%2B+1+%2B+32+%3D+37" 
alt="caf = 4 + 1 + 32 = 37">
</div>

&nbsp;

For easier reading, the letters are typically sorted. Napier allowed for redundant occurrences of letters, though he acknowledged that there is a normal form that has no repeats. He described this as the _extended_ (repeated) vs. _abbreviated_ (no repeats and sorted) form. To create the abbreviated form, any pair of letters can be reduced to a single occurrence of the next "higher letter". For example:

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+abbccd+%5Crightarrow+acccd+%5Crightarrow+acdd+%5Crightarrow+ace+%3D+1+%2B+4+%2B+16+%3D+21" 
alt="abbccd \rightarrow acccd \rightarrow acdd \rightarrow ace = 1 + 4 + 16 = 21">
</div>

&nbsp;

(extended form) → (reduce 2b's to c) → (reduce 2d's to e) → (abbreviated form) → 1 + 4 + 16 = 21

### Program Specifications

Your job is to write functions that can convert back and forth between location and decimal representations, as well as some support functions for the process.

&nbsp;

```c++
std::int64_t LocToDec(std::string const & loc)
```

Converts a location arithmetic string to an integer.

&nbsp;

```c++
std::string Abbreviate(std::string const & loc)
```

Takes a location string and reduces it to its abbreviated form. We want you to experiment with string manipulation so _you may not convert it to an integer first_. You must do the abbreviation directly.

⭐ Please show the TA your working `Abbreviate()` function before moving on.

&nbsp;

```c++
std::string DecToLoc(std::int64_t dec)
```

Converts an integer to an _abbreviated_ location string.

&nbsp;

```c++
std::int64_t AddLoc(std::string const & loc1, std::string const & loc2)
```

Takes two location strings, adds them, and provides the integer result. For this function, think about following these steps:
1.  Concatenate the strings
2.  Reduce the combination string using your `Abbreviate()` function
3.  Convert the result using your `LocToDec()` function

&nbsp;

Write a `main()` function that shows off your work.
1.  Prompt for two elements: a location string, and an integer.
2.  Using `LocToDec()`, print the location string and the resulting integer.
3.  Using `Abbreviate()`, print the location string and its reduced form.
4.  Using `DecToLoc()`, print the integer and its location string.
5.  Prompt for two more location strings.
6.  Using `AddLoc()`, add the two location strings and print the result.

Example interaction with the final program:

```
Give me a location string:
abbccd
Give me an integer:
37
abbccd to dec: 21
abbccd abbreviated: ace
37 to loc: acf
Give me two more location strings:
abc
bcd
Sum of abc and bcd is: 21
```

⭐ Please show the TA your completed program.

&nbsp;

### Assignment Notes

We haven't covered sorting just yet, but C++ makes it pretty easy. Here is an example:

```c++
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <algorithm>
using std::sort;

// make sure to include <algorithm>!

int main() {
    string my_str = "aebcd";

    cout << "my_str before sorting: " << my_str << endl;

    sort(my_str.begin(), my_str.end());

    cout << "my_str after sorting: " << my_str << endl;
}
```

Output:

```
my_str before sorting: aebcd
my_str after sorting: abcde
```

`std::sort()` sorts the individual elements (instances of type `char`, in this case) of a collection given two points, `my_str.begin()`, and `my_str.end()`. We'll be talking more about what these methods do later on in the course. **Note that `std::sort()` changes the string in-place!**

Hints on approaching these functions:

1.  You could define a constant for each letter of the alphabet, but that would be a pain. The smallest character of a location string is `'a'`, which represents 2^0 power (i.e., 1). The difference between any letter and `'a'` is the power of 2 that letter represents. For example:
    - `'a'-'a'` = 0, which in location arithmetic is 2^0 = 1
    - `'c'-'a'` = 2, which in location arithmetic is 2^2 = 4
    - `'h'-'a'` = 7, which in location arithmetic is 2^7 = 128
2.  The function, `DecToLoc()`, is really nothing more than creating a "long string" and using `Abbreviate()` to clean it up.
3.  The function, `AddLoc()`, is nothing more than a concatenation of the two strings, a call to `Abbreviate()`, followed by a call to `LocToDec()`.
4.  Your functions might make use of:
    - `.substr()` - The `.substr()` method takes two parameters: a position, and a length. It returns the substring specified within that range. The length defaults to the end of the string (or, if the value is beyond the length of the string, it defaults to the end).
    - `.erase()` - The `.erase()` method takes two parameters: a position, and a length (just like `.substr()`). It removes all characters within the specified range.
    - `.push_back()` - The `.push_back()` method appends a given `char` to the end of the string.
    - `static_cast<char>` - If you do addition/subtraction on a character, you need to cast it to a `char` for the "printable" version.
    - Indexing via the `[]` operator.

## Honors Material - Custom Command Line Tools

Now that we know how to manipulate strings and read in command line arguments, we can start putting these together to build our own command line tools.

### Background

The file type .csv stands for "[Comma-Separated Values](https://en.wikipedia.org/wiki/Comma-separated_values)" and is commonly used and fairly simple way to store data.  The top line of a CSV file typically names each column, and the rest of the file has associated data.  For example, a data file containing the periodic table might start with:

```csv
Atomic Number,Symbol,Name,Mass
1,H,Hydrogen,1.008
2,He,Helium,4.002
3,Li,Lithium,6.941
4,Be,Beryllium,9.012
5,B,Boron,10.811
```
...and so on.

This files would be rendered by most software that uses it to look like:

| Atomic Number | Symbol | Name      | Mass   |
| ------------- | ------ | --------- | ------ |
| 1             | H      | Hydrogen  | 1.008  |
| 2             | He     | Helium    | 4.002  |
| 3             | Li     | Lithium   | 6.941  |
| 4             | Be     | Beryllium | 9.012  |
| 5             | B      | Boron     | 10.811 |

It is often useful to be able to extract a single column from a CSV file in order to manipulate it directly.  For this lab you will do so, but we have several steps to get there.

If you want some real-world CSV files to play with that are fun, but relatively small, check [here](https://www.kaggle.com/code/rtatman/fun-beginner-friendly-datasets/notebook).

### Assignment

You will write three helper functions and then a main() program to read in CSV data and output a single column of data.

To start with, write a `FindQuoteEnd()` function that will take as parameters a constant reference to a string and an index position of a quote.  The function will scan ahead to find the corresponding close-quote and return the position where it is found.

```c++
size_t FindQuoteEnd(const std::string & line_str, size_t open_pos);
```

Next, a `FindEntryEnd()` function that will take as parameters a constant reference to a string and an index position of the start of an entry.  The function will scan ahead to find the comma at the end of the entry and return the position where it is found.  If there is no comma, it should return the size of the input string.  You should make use of your `FindQuoteEnd()` as a helper function to ensure that quoted regions are treated as part of the same entry.

```c++
size_t FindEntryEnd(const std::string & line_str, size_t open_pos);
```

Third, write a `GetEntry()` function that will take as parameters a constant reference to a string and a column number and return a string for the entry in that column.

```c++
std::string GetEntry(const std::string & line_str, size_t id);
```

Finally, write the `main()` function a program that takes a single command-line argument (remember command-line arguments from [Honors Lab 03](https://cse232-msu.github.io/CSE232/labs/lab03.html)?) indicating the column number to print; it should then load a CSV-formatted input through `std::cin` and output just the column that was indicated on the command line.

For example, if your executable is called `extract_col` and the CSV above were in the file `elements.csv`, we could type

```bash
cat elements.csv | extract_col 2
```

to print the list of element names:

```csv
Name
Hydrogen
Helium
Lithium
Beryllium
Boron
```

One extra tip: To read in an entire line at a time from `std::cin`, you can create an `std::string` to store it in (called `cur_line` here) and the use `std::getline(std::cin, cur_line)` to get the line.  This command will return `true` for as long as there is more input to receive, so it can be put inside of a while loop.

You should write this code for Honors Lab 05 on Coding Rooms.  Starter code is provided for each of the required functions.

### Trivia

In the program above, we made good use of `const std::string &`.  This type is one of the more common types you will see used in C++ programs, especially until C++20.  Strings can be very long and involve memory allocation (whenever we don't know how big an object will be at compile time, we need to wait until runtime and then ask for enough memory to fit it, which can be a slower process).  Passing strings by reference into a function will ensure that we don't have to copy the string, which would involve allocating memory for the copy.  But if you see a function that just takes a `std::string &` type, it may mean that that function will change the string; adding a `const` to the beginning of the parameter assures the user that no changes will occur.  In general it is good coding practice to always put `const` in front of any references that you don't change to let the function user know.  The `const` keyword also lets the compiler know that a variable won't be changed and can help it do better optimizations.

What's changed in C++20 that may change the prevalence of `const std::string &`?  It turns out that there are two features that can do the same or better job in some cases.  First, `std::string` has been setup so that it can be made `constexpr`, and as such any strings that can be used exclusively at compile time will not need to expend any run-time memory (though there are some [details and caveats to read about](https://www.cppstories.com/2021/constexpr-vecstr-cpp20/) if you want to try it).  Second, a new two that was added in C++17 has become much more useful in C++20: [`std::string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view).  A string_view looks at the existing memory of a string without duplicating it, but with the added feature that you can use sub-sets of the string.  In fact, we could have designed our program above such that `GetEntry()` actually returned a string_view that was just the relevant sub-section of the original string.  That, however, would have required us to preserve the original string which we are not currently doing.

As long as we're talking about variations on `std::string`, another one to know about is [`std::stringstream`](https://en.cppreference.com/w/cpp/io/basic_stringstream), which allows us to send information into it just like `std::cout` using the `<<` operator.  And once we have the information we need, we can pull it out again using the `>>` operator (just like `std::cin`).  For example

```c++
  int i = 4;
  std::string out_name

  std::stringstream ss;
  ss << "Fantastic" << i;
  ss >> out_name;
```

Would set the string `out_name` to "Fantastic4".