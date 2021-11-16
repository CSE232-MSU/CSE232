---
title: Lab - More on Classes
---

# Lab - More on Classes

## Compiler Options

`g++` is a very complicated (but powerful) program. Technically, it is just an alias (alternate name) for `gcc`, which is the GNU C Compiler. `g++` (and `gcc`) have many options for determining how it should compile your program.

[The full list of options can be found here](https://gcc.gnu.org/onlinedocs/gcc-7.1.0/gcc/Invoking-GCC.html#Invoking-GCC), but I'll be pointing out the most important ones.

Here are the flags you should already be comfortable with:

*   `-c` - This flag instructs the compiler to compile all your .cpp files, but not link them together (see Week 01).
*   `-o filename` - This flag instructs the compiler to make a file named `filename` with the executable compiled program (instead of the default `a.out`).
*   `-Wall` - This flag instructs the compiler to warn about as many potential erroneous code elements as possible (useful for beginners).
*   `-std=c++17` - This instructs the compiler to use a particular version of the C++ language (you can use 11, 14, etc. in the place of 17).
*   `-g` - This flag instructs your compiler to include debugging information in the compiled program for use by `gdb`.

And here are some new ones:

*   `-O1` - This flag enables various code optimizations that allow your program to run faster, without a large increase in time to compile.
*   `-O2` - This flag enables various code optimizations that allow your program to run faster, but may increase the time needed to compile.
*   `-O3` - This flag is similar to `-O2`, but with even more extreme optimizations and possibly very long compilations.
*   `-Ofast` - This flag is allows optimizations that aren't necessarily allowed by the standards set forth by the C++ language committee. This is where experimental optimizations are used by those who want speed at all costs.
*   `-Os` - This flag instructs the compiler to optimize for size instead of speed. It is often useful if you need to run your program on embedded computers with limited memory.
*   `-Wextra` - This flag instructs the compiler to add additional warnings for bad code (even more than `-Wall`).
*   `-Wpedantic` - This flag instructs the compiler to add additional warnings for code that doesn't comply with the strict C++ language definition (useful if you want your code to be compiled by other compilers).

⭐ Copy-and-paste the following code into a file, and show your TA the output when you compile it with more warnings than what `-Wall` checks for.

```c++
#include <iostream>
using std::cout; using std::endl;

int add(int a, int b, int c) {
    return a + b;
}

int main() {
    cout << add(1, 2, 4) << endl;
}
```

## Coding Assignment

Today, we're going to work on making our own classes with private data members and accessors. More specifically, we'll be building a `Table` class, which will act as an abstraction of two-dimensional vectors (i.e., matrices).

### Program Specifications

[Download the starter code provided here.](../assets/downloads/lab_more_classes.zip)

The header for the Table class has the following private elements:

```c++
 private:
  std::vector<std::vector<int>> t_;  // 2D vector of long
  int width_;                        // how wide is t_ (how many columns)
  int height_;                       // how high is t_ (how many rows)
```

You are to implement the following methods:

&nbsp;

```c++
Table(int width, int height, int val = 0);
```

Constructs a `Table` instance that is of shape `width` by `height`, where each element is filled by `val` (which is defaulted to 0). 

Remember that `t_` is a `vector<vector<int>>`. You can only `push_back()` instances of `vector<int>` onto `t_`, and only instances of `int` onto `vector<int>`.

&nbsp;

```c++
void PrintTable(std::ostream&) const;
```

Prints the contents of `t_` in a "nice way" (as a square with rows and columns) to the `ostream` reference provided.

&nbsp;

```c++
void FillRandom(int low, int high, int seed = 0);
```

Sets every element of `t_` to a random number of type `int` bounded between `low` and `high` inclusively. `seed` sets the random number seed, which defaults to 0. [Use the technique described here](https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c) with a uniform distribution drawn from the MT19937 random number generator.

Be sure to fill the vector in the same order that you print it.

⭐ Show the TA when your `Table` class can execute the `FillRandom()` method.

&nbsp;

```c++
bool SetValue(int x, int y, int val);
```

Sets a particular element at location (`x`, `y`) to `val`. If `x` or `y` are out-of-range of the available `t_` indices, `SetValue` should return `false`. Otherwise, return `true` to signify a successful value set. (0,0) should be printed in the top left. (0,1) is the first element on the second row/line.

&nbsp;

```c++
int GetValue(int x, int y) const;
```

Returns the value at location (`x`, `y`) of `t_` if those two indices exist. If the indices are out-of-range of the available `t_` indices, throw an `out_of_range` error.

&nbsp;

The output of the main file should ultimately look like:

```
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,

6,6,8,9,7,
9,6,9,5,7,
7,4,5,3,9,
1,10,3,4,5,
8,9,6,5,6,

Result:false

3
Correct!

6,6,8,9,7,
0,6,9,5,7,
7,1,5,3,9,
1,10,4,4,5,
8,9,6,9,6,

```

Although, your random values may be different, if you are compiling locally.

⭐ Show the TA your completed `Table` class.
