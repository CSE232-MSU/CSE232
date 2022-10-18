---
title: Lab - Generic Algorithms
---

# Lab - Generic Algorithms

## Wildcards

When compiling multiple C++ files, it's pretty annoying to have to specify each .cpp file to the compiler.

```bash
g++ -std=c++17 -Wall -g main.cpp stack.cpp disk.cpp io.cpp
```

Recall our discussion in Lab 06 -- bash gives an alternative method to select files that match a particular pattern. Notice that the above files were all the files in the folder that ended with '.cpp'. You can use a _wildcard_ (the asterisk, `*`) to denote all of those files at once. Example:

```bash
g++ -std=c++17 -Wall -g *.cpp
```

The `*` symbol roughly translates to "all", where, when combined with the '.cpp' extension, it becomes "all files that end in '.cpp'".

This can be used in other contexts beyond compilation. Let's say you have a folder named "headers", where you want to move all of your '.h' files to. You can do so with:

```bash
mv *.h headers/
```

Another wildcard is `?`, which you can use to represent exactly one character.  For example, in the directory above you could type

```bash
ls ????.cpp
```

And it would list any file with exactly four characters before the '.cpp'.  In this case, it would show you "main.cpp" and "disk.cpp", but leave out both "io.cpp" (because it is too short) and "stack.cpp" (because it is too long.)

⭐ Show your TA what happens when you use wildcards to open multiple '.cpp' files with the `gedit` command.

## Debugging with Visual Studio Code

There used to be a tutorial associated with this lab that demonstrated use of an IDE debugger. This tutorial was moved to be at the start of the course. The necessary setup is at the bottom of the [setup tutorials](https://cse232-msu.github.io/CSE232/vscode_setup.html) you (hopefully) went through during the first week.

A similar IDE debugging tutorial [can be found here](https://cse232-msu.github.io/CSE232/debugging_guide.html) if you're unfamiliar with one. This used to be a Visual Studio tutorial, but it was recently changed to be a Visual Studio Code tutorial (yes, [Visual Studio](https://visualstudio.microsoft.com/) and [Visual Studio Code](https://code.visualstudio.com/) are two different IDEs) since this course now recommends VSCode as opposed to letting students choose any IDE. 

(You can still choose your own IDE, but you'll be on your own if you need help with it)

If you have come this far without VSCode and its debugger, we _highly_ recommend that you become acquainted with these tools, now, before the proceeding weeks. 

Please feel free to ask questions about debugging if you don't fully understand it.

## Coding Assignment

This lab will have you apply generic algorithms to various programming problems.

### Program Specifications

Write definitions for the four functions described below. You are to not use any loops (for-loops or while-loops). Instead, you must use generic algorithms from the `<algorithm>` and `<numeric>` headers.  We will automatically reject code with "for" or "while" in it, so make sure not to include these words even in comments. (You can just add a space or some other character, so "// Search f_or multiples of two" would be fine.)

&nbsp;

```c++
void PassOrFail(vector<pair<string, int>> &v)
```

Given a vector, `v`, where each element of the vector is a (name, grade) pair, sorts the vector by name and partitions the first half of the vector as pairs who passed, and the second half of the vector as pairs who failed.

A pair "passes" if the grade is greater than or equal to 600 points.

```c++
// given a vector, where each element in the vector is a [name,grade] pair
// sort range by name, partition range into pass and fail, preserving
// alphabetic order within partition
// Note: the grades are the number of points earned (600 points earns a passing grade)
std::vector<std::pair<std::string, int>> v2 {
    {"imen", 851},
    {"mark", 600},
    {"charles", 412},
    {"sebnem", 1000},
    {"abdol", 905},
    {"josh", 300}
};
std::vector<std::pair<std::string, int>> w2 { 
    {"abdol", 905}, 
    {"imen", 851}, 
    {"mark", 600}, 
    {"sebnem", 1000},  // Everyone after this point failed
    {"charles", 412}, 
    {"josh", 300}
};

PassOrFail(v2);
assert(v2 == w2);
```


&nbsp;

```c++
void ShiftRange(vector<int> &v, int left, int right)
```

Given a vector of ints, `v`, sorts the vector and moves all elements within the range [`left`, `right`] to the end of the vector.

```c++
// given (a vector of ints, and int values "left", and "right"), sort the vector, rotate all numbers in the
// range [left,right] to end of vector
std::vector<int> v1 = {13, 22, 4, 5, 3, 11, 16, 25, 7};
std::vector<int> w1 = {3, 4, 5, 7, 22, 25, 11, 13, 16};
// Notice that 11, 13, 15 (the values between 10 and 20 are moved to the end)

ShiftRange(v1, 10, 20);
assert(v1 == w1);
```

&nbsp;

```c++
vector<int> Fibonacci(int n)
```

Generates the first `n` Fibonacci numbers. Recommend looking into the `iota` algorithm.

```c++
// generate 1st n fibonacci numbers
// See: https://en.wikipedia.org/wiki/Fibonacci_number
std::vector<int> v3 = Fibonacci(8);
std::vector<int> w3 = {1, 1, 2, 3, 5, 8, 13, 21};
assert(v3 == w3);
```

&nbsp;

```c++
int BinaryToInt(const string &binary_str)
```

Converts a binary string (base 2) to an `int` (base 10).

```c++
// convert at string representing a binary number 
// to an int
const std::string binary_str = "10110";
int result = BinaryToInt("10110");
assert(result == 22);
```

&nbsp;

⭐ Show the TA your completed set of functions. 

## Honors Material - Build your own Generic Algorithm

The functions that you have written so far this semester have parameter types that involve inputting regular data, be it numbers, strings, vectors, or the like.  As it turns out, you can also pass one function as an argument into another.  You've explored calling such generic functions in the non-honors portion of this lab.  Here you will write such a function.

### Background

If you `#include <functional>` in your code, you will have access to `std::function` which allows you to save functions as variables (along with a host of other cool function helpers).  For consider the following program:

```c++
#include <functional>
#include <iostream>

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }

int main() {
  // Create a function variable and set it to the function Add()
  std::function<int(int,int)> my_fun = Add;

  // Run our function variable an output the result
  std::cout << my_fun(10,7) << std::endl;

  // Change our function variable to the Sub() function.
  my_fun = Sub;

  // Exact same line of code as a above, but outputs new result!
  std::cout << my_fun(10,7) << std::endl;
}
```

The `std::function` template takes the function signature as a return type.  In the example above, we were looking for a function that had two ints as parameters and returned an int, so its type is `int(int,int)`.  You can setup a function signature however you like, but it must be specified in the template parameter for any function variable.

Notice that the first output line above runs Add() on 10 and 7, thus it outputs the sum of those numbers, a `17`.
However, once we changed the `my_fun` variable to be equal to Sub(), running it again output `3` (10 minus 7 instead of 10 plus 7).

Just like other variable types, you can use std::function as a parameter on another function.  Let's imagine you have a program where you are working with collections of words that you store as `std::vector<std::string>`.  You might want to have a function that applied a function to every character in a string.  It might look like:

```c++
std::string Convert(const std::string & str, std::function<char(char)> fun) {
  std::string out_str;
  for (char x : str) out_str.push_back(fun(x));
  return out_str;
}
```

We can then easily use Convert() to write our own functions that transform every letter in a string.  For example:

```c++
std::string ToLower(const std::string & str) {
  return Convert(str, [](char x){ return std::tolower(x); });
}
```


### Assignment

You will write a `PlayNim` function that will determine which of two players wins the Subtraction version of the game [https://en.wikipedia.org/wiki/Nim#The_subtraction_game](Nim).  The way this game works is that two players start with a pile of N coins.  On a player's turn, they must take at least 1 coin from the pile and may take up to K coins.  The player who is forced to take the last coin loses.

Your function should have four parameters.

1. The function to control player 0
2. The function to control player 1
3. An `int` indicating N, the number of coins in the starting pile
4. An `int` indicating K, the maximum number of coins a player can take on their turn.

The player control functions should each have type `int(int,int)`.  The two parameters indicate the number of coins remaining in the pile and the largest move allowed.  The returned int should indicate the number of coins remaining after their move.

Your `PlayNim` function should play out the game and return either a 0 or a 1 to indicate the winning player.  A player wins if they force their opponent to take the last coin OR if their opponent makes an illegal move (for example, taking too many coins).  Player 0 should always go first.

Note that you are allowed to produce any output you want, as long as your function returns the correct answer.  All output will be printed with the result, so printing can be helpful for debugging.

### Trivia

Templates interact well with generic functions, especially if you don't know all of the types ahead of time.  For example, the `std::for_each()` algorithm steps through a container applying a function to it.  If we had a string called `in_str` and we wanted to transform every character in that string to lowercase, we could use the existing C++ Standard Library algorithm:

```c++
  std::for_each(
    in_str.begin(),
    in_str.end(),
    [](char & x){ return x = std::tolower(x); }
  );
```

The one thing that some people don't like about `std::for_each` (or various other standard algorithms, for that matter) is that you always need to provide begin and end iterators -- you can't just pass in the entire container that you want to work with.

What if we wanted to have our own version -- let's call it `ForEach()` -- and we wanted it to take a container for the first argument, not iterators.  We could write it like this as:

```c++
template <typename CONTAINER_T, typename FUNCTION_T>
auto ForEach(CONTAINER_T & c, FUNCTION_T fun) {
  for (auto & x : c) fun(x);
}
```

We don't need to know the container type or anything about the function type -- we let the template figure those out.  We let the for-loop step through the container and trust that the function that was passed in can take the container elements as arguments.
