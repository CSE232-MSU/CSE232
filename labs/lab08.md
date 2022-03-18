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

Write definitions for the four functions described below. You are to not use any loops (for-loops or while-loops). Instead, you must use generic algorithms from the `<algorithm>` and `<numeric>` headers.

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
    {"josh", 851},
    {"mark", 600},
    {"charles", 412},
    {"sebnem", 1000},
    {"abdol", 905},
    {"imen", 300}
};
std::vector<std::pair<std::string, int>> w2 { 
    {"abdol", 905}, 
    {"josh", 851}, 
    {"mark", 600}, 
    {"sebnem", 1000},  // Everyone after this point failed
    {"charles", 412}, 
    {"imen", 300}
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
// given (a vector of ints, and ints "left", and "right"), sort the vector, rotate all numbers in the range
// [left,right] to end of vector
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
