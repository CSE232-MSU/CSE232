# Lab 04 - Strings

## Standard Input, Output and Pipes

### Redirection

Please read this page ([http://linuxcommand.org/lc3_lts0070.php](http://linuxcommand.org/lc3_lts0070.php)).

![](Red_star.svg) Please show the TA the sorted filenames of your desktop (using `ls`, `sort` and redirection).

## Lab Assignment

### The Problem

John Napier was a Scottish mathematician who lived in the late 16th and early 17th centuries. He is known for a number of mathematical inventions, one of which is termed _location arithmetic_.

You job is to write functions that can convert back and forth between location and decimal representations, as well as some support functions for the process.

### Overview

Location arithmetic is a way to represent numbers as binary values, using a notation that is not positional, but representational. You can see a detailed description in [http://en.wikipedia.org/wiki/Location_arithmetic](http://en.wikipedia.org/wiki/Location_arithmetic) but here are the basics.

#### The representation

Napier used letters to represent powers of two. In using letters, the position of the letter is not important, allowing for multiple representations of the same number. For example, in location arithmetic:

a=1, b=2, c=4, d=8, e=16, f=32 ... and thus: acf → 1 + 4 + 32 ← caf or 37

For convenience, the letters are typically sorted but only make reading easier. Napier allowed for redundant occurrences of letters, though he acknowledged that there is a normal form that had no repeats. He described this as the _extended_ (repeated) vs. _abbreviated_ (no repeats). To create the abbreviated form, any pair of letters can be reduced to a single occurrence of the next "higher letter". For example:

abbccd (extended) → a**c**ccd (2b's to c) → acdd (2d's to e) → ace → 1 + 4 + 16 → 21

#### Addition

Addition is particularly easy. Take all the letters from the two values, put them into a single string, sort, reduce, convert!

abc + bcd → abbccd (mix) → acccd (reduce) → acdd (reduce) → ace → 1 + 4 + 16 → 21

### Your Task

Write the following four functions and main program to do location arithmetic:

1.  `long loc_to_dec(string loc)` : convert location arithmetic string to an integer
2.  `string abbreviate(string loc)` : take a location string and reduce it to its abbreviated form. We want you to experiment with string manipulation so **you cannot convert it to integer first**. You must do the abbreviation directly

    ![](Red_star.svg) Please show your TA a demonstration of a working `abbreviate` function.

3.  `string dec_to_loc(long dec)` : convert an integer to an _abbreviated_ location string
4.  `long add_loc (string loc1, string loc2)` : take two location strings, add them, provided the integer result. For this function, _do it the way described above!!_, that is:
    1.  mix the strings
    2.  reduce the string (using your) `abbreviate` function
    3.  convert the result (using your `loc_to_dec` function)
5.  Write a main function that shows off your work:
    1.  Prompt for two elements: a location string and an integer.
    2.  Using `loc_to_dec` print the location string and the resulting integer.
    3.  Using `abbreviate`, print the location string and its reduced form.
    4.  Using `dec_to_loc`, print the integer and its location string.
    5.  Prompt for two more location strings.
    6.  Using `add_loc`, add the two location strings and print the result.

    Example interation with final program:

    <pre>Give me a location string:
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
    </pre>

![](Red_star.svg) Please show your TA a your working complete program.

#### Sorting

We haven't done soring yet, but C++ makes it pretty easy. [Here is an example](lab04/sort.cpp), but this is the gist. Sorting sorts the individual elements of a collection in sorted order from two points in the collection. Elements in strings are chars, so sorting from the beginning to the end of the string, character by character, is shown below. **Note that sorting changes the string in place!**

<pre>#include<algorithm>
using std::sort;
...
string my_str = "adbche";
//sort string, char by char, in place, from begin() to end(). Note the parentheses!
sort(my_str.begin(), my_str.end());
cout << my_str; // prints abcdeh </pre>

#### Hints

1.  You could define a constant for each letter of the alphabet, but what a pain. Better to note the following. The smallest character of a location string is 'a', which represents 2^0 power (i.e. 1). The difference between any letter and 'a' is the power of 2 the letter represents. For example:
    1.  'a'-'a' = 0 → which in location arithmetic is 2^0 → 1
    2.  'c'-'a' = 2 → which in location arithmetic is 2^2 → 4
    3.  'h'-'a' = 7 → which in location arithmetic is 2^7 → 128
2.  The function `dec_to_loc` is really nothing more than creating a "long string" and using `abbreviate` to clean it up. The `abbreviate` function is the key.
3.  The function `add_loc` is nothing more than a concatenation of the two strings, a call to `abbreviate`, followed by a call to `loc_to_dec`.
4.  Your functions might make use of:
    1.  `substr` method : substring takes two parameters: a position and a length. Length defaults to the end of the string (or if the value is beyond the length of the string, it defaults to the end.)
    2.  `static_cast<char>` : if you do addition/subtraction on a character, you need to cast it to a character for the "printable" version.
    3.  `string.erase(...)` : The erase method of the string class lets you remove characters from it.
    4.  `push_back` method : you can push a character onto the end of the string using this method.
    5.  indexing via the `[]` operator