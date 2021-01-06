# Lab 08 - Structs

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

## Coding Assignment

This lab will have you apply generic algorithms to various programming problems.

### Program Specifications

[Download the starter code provided here](../.assets/downloads/lab08.zip).

Write definitions for the four functions described below. You are to not use any loops (for-loops or while-loops). Instead, you must use generic algorithms from the `<algorithm>` and `<numeric>` headers.

&nbsp;

```c++
void ShiftRange(vector<int> &v, int left, int right)
```

Given a vector of ints, `v`, sorts the vector and moves all elements within the range [`left`, `right`] to the end of the vector.

&nbsp;

```c++
void PassOrFail(vector<pair<string, int>> &v)
```

Given a vector, `v`, where each element of the vector is a (name, grade) pair, sorts the vector by name and partitions the first half of the vector as pairs who passed, and the second half of the vector as pairs who failed.

A pair "passes" if the grade is greater than or equal to 600 points.

&nbsp;

```c++
vector<int> Fibonacci(int n)
```

Generates the first `n` Fibonacci numbers.

&nbsp;

```c++
int BinaryToInt(const string &binary_str)
```

Converts a binary string (base 2) to an `int` (base 10).

&nbsp;

⭐ Show the TA your completed set of functions. 
