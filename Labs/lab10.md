---
title: Lab 10
---

# Lab 10 - More on Classes

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

[Download the starter code provided here.](../assets/downloads/lab10.zip)

The header for the Table class has the following private elements:

```c++
private:
    vector<vector<long>> t_;    // 2D vector of long
    long width_;                // how wide is t_ (how many columns)
    long height_;               // how high is t_ (how many rows)
```

You are to implement the following methods:

&nbsp;

```c++
Table(long width, long height, long val=0)
```

Constructs a `Table` instance that is of shape `width` by `height`, where each element is filled by `val` (which is defaulted to 0). 

Remember that `t_` is a `vector<vector<long>>`. You can only `push_back()` instances of `vector<long>` onto `t_`, and only instances of `long` onto `vector<long>`.

&nbsp;

```c++
void fill_random(long lo, long hi, unsigned int seed=0)
```

Sets every element of `t_` to a random number of type `long` bounded between `lo` and `hi` inclusively. `seed` sets the random number seed, which defaults to 0. [Use the technique described here](https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c) with a uniform distribution drawn from the MT19937 random number generator.

⭐ Show the TA when your `Table` class can execute the `fill_random()` method.

&nbsp;

```c++
bool set_value(unsigned int row_num, unsigned int col_num, long val)
```

Sets a particular element at location (`row_num`, `col_num`) to `val`. If `row_num` or `col_num` are out-of-range of the available `t_` indices, `set_value()` should return `false`. Otherwise, return `true` to signify a successful value set.

&nbsp;

```c++
long get_value(unsigned int row_num, unsigned int col_num) const
```

Returns the value at location (`row_num`, `col_num`) of `t_` if those two indices exist. If the indices are out-of-range of the available `t_` indices, throw an `out_of_range` error.

&nbsp;

```c++
void print_table(ostream &out)
```

Prints the contents of `t_` in a "nice way" (as a square with rows and columns) to the `ostream` reference provided.

&nbsp;

The output of the main file should ultimately look like:

```
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,

2,10,1,6,6,
1,7,5,9,10,
5,7,10,4,3,
5,8,7,6,3,
2,6,6,2,2,

Result:false

6
Correct!

100,10,1,6,6,
1,100,5,9,10,
5,7,100,4,3,
5,8,7,100,3,
2,6,6,2,100,
```

⭐ Show the TA your completed `Table` class.
