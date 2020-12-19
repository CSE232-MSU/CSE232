# Lab 04 - Strings

## Standard Input, Output and Pipes

### I/O Redirection

Please read through this page: [http://linuxcommand.org/lc3_lts0070.php](http://linuxcommand.org/lc3_lts0070.php)

⭐ Please show the TA your sorted filenames (using `ls`, `sort` and I/O redirection).

## Coding Assignment

### Background

John Napier was a Scottish mathematician who lived in the late 16th and early 17th centuries. He is known for a number of mathematical inventions, one of which is termed _location arithmetic_.

Your job is to write functions that can convert back and forth between location and decimal representations, as well as some support functions for the process.

Location arithmetic is a way to represent numbers as binary values, using a notation that is not positional, but representational. [You can read a detailed description here](http://en.wikipedia.org/wiki/Location_arithmetic), but these are the basics:

#### The Representation

Napier used letters to represent powers of two. The position of these letters is unimportant, allowing for multiple representations of the same number. For example, in location arithmetic:

___

<img src="https://render.githubusercontent.com/render/math?math=a = 1, b = 2, c = 4, d = 8, e = 16, f = 32, ..., z=335554432">

&nbsp;

<img src="https://render.githubusercontent.com/render/math?math=acf \rightarrow 1 %2B 4 %2B 32 = 37">

&nbsp;

<img src="https://render.githubusercontent.com/render/math?math=caf \rightarrow 4 %2B 1 %2B 32 = 37">

___

For easier reading, the letters are typically sorted. Napier allowed for redundant occurrences of letters, though he acknowledged that there is a normal form that has no repeats. He described this as the _extended_ (repeated) vs. _abbreviated_ (no repeats) form. To create the abbreviated form, any pair of letters can be reduced to a single occurrence of the next "higher letter". For example:

___

<img src="https://render.githubusercontent.com/render/math?math=abbccd \rightarrow acccd \rightarrow acdd \rightarrow ace \rightarrow 1 %2B 4 %2B 16 = 21">

___

(extended form) → (reduce 2b's to c) → (reduce 2d's to e) → (abbreviated form) → 1 + 4 + 16 = 21

### Program Specifications

Write the following functions to do location arithmetic:

1.  `long loc_to_dec(string loc)` : converts location arithmetic string to an integer
2.  `string abbreviate(string loc)` : takes a location string and reduces it to its abbreviated form. We want you to experiment with string manipulation so **you cannot convert it to integer first**. You must do the abbreviation directly.

⭐ Please show the TA your working `abbreviate()` function before moving on.

3.  `string dec_to_loc(long dec)` : converts an integer to an _abbreviated_ location string
4.  `long add_loc(string loc1, string loc2)` : takes two location strings, adds them, provides the integer result. For this function, think about following these steps:
    1.  Combine the strings
    2.  Reduce the combination string using your `abbreviate()` function
    3.  Convert the result (using your `loc_to_dec()` function)
5.  Write a main function that shows off your work.
    1.  Prompt for two elements: a location string, and an integer.
    2.  Using `loc_to_dec()`, print the location string and the resulting integer.
    3.  Using `abbreviate()`, print the location string and its reduced form.
    4.  Using `dec_to_loc()`, print the integer and its location string.
    5.  Prompt for two more location strings.
    6.  Using `add_loc()`, add the two location strings and print the result.

Example interation with final program:

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

### Assignment Notes

We haven't covered sorting just yet, but C++ makes it pretty easy. Here is an example:

```c++
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <algorithm>  // make sure to import <algorithm>!
using std::sort;

int main () {
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

In this example, `std::sort()` sorts the individual elements (instances of type `char`, in this case) of a collection given two points, `my_str.begin()`, and `my_str.end()`. We'll be talking more about what these methods do later on in the course. **Note that `std::sort()` changes the string in-place!**

Hints on approaching the lab functions:

1.  You could define a constant for each letter of the alphabet, but that'd be a pain. The smallest character of a location string is `'a'`, which represents 2^0 power (i.e., 1). The difference between any letter and `'a'` is the power of 2 that letter represents. For example:
    1.  `'a'-'a'` = 0 → which in location arithmetic is 2^0 = 1
    2.  `'c'-'a'` = 2 → which in location arithmetic is 2^2 = 4
    3.  `'h'-'a'` = 7 → which in location arithmetic is 2^7 = 128
2.  The function, `dec_to_loc()`, is really nothing more than creating a "long string" and using `abbreviate()` to clean it up.
3.  The function, `add_loc()`, is nothing more than a concatenation of the two strings, a call to `abbreviate()`, followed by a call to `loc_to_dec()`.
4.  Your functions might make use of:
    1.  `.substr()` : The `.substr()` method takes two parameters: a position, and a length. It returns the substring specified within that range. The length defaults to the end of the string (or, if the value is beyond the length of the string, it defaults to the end).
    2.  `.erase()` : The `.erase()` method takes two parameters: a position, and a length (just like `.substr()`). It removes all characters within the specified range.
    3.  `.push_back()` : The `.push_back()` method appends a given `char` to the end of the string.
    3.  `static_cast<char>` : If you do addition/subtraction on a character, you need to cast it to a `char` for the "printable" version.
    5.  Indexing via the `[]` operator.