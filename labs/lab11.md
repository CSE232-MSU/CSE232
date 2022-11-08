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
*   `-std=c++17` - This instructs the compiler to use a particular version of the C++ language (you can use 11, 14, 20, etc. in the place of 17).
*   `-g` - This flag instructs your compiler to include debugging information in the compiled program for use by `gdb`.  This will slow your program down, but is critical for effective debugging of code.

And here are some new ones:

*   `-O1` - This flag enables various code optimizations that allow your program to run faster, without a notable increase in time to compile.  (Note, this is the same as using just -O without a number)
*   `-O2` - This flag enables more code optimizations that allow your program to run faster.  It may increase the time needed to compile you code, but will not notably increase the amount of memory required to run.
*   `-O3` - This flag is similar to `-O2`, but with even more extreme optimizations and possibly long compilations and a larger memory footprint.
*   `-Ofast` - This flag is allows optimizations that aren't necessarily allowed by the standards set forth by the C++ language committee. This is where experimental optimizations are used by those who want speed at all costs.
*   `-Os` - This flag instructs the compiler to prioritize size over speed in optimizations. It is often useful if you need to run your program on embedded computers with limited memory.
*   `-Wextra` - This flag instructs the compiler to add additional warnings for bad code (even more than `-Wall`).
*   `-Wpedantic` - This flag instructs the compiler to add additional warnings for code that doesn't comply with the strict C++ language definition, even if g++ knows how to compile it (useful if you want your code to be compiled by other compilers).

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
  std::vector<std::vector<int>> t_;  // 2D vector of int
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

Returns the value at location (`x`, `y`) of `t_` if those two indices exist. If the indices are out-of-range of the available `t_` indices, throw an `out_of_range` exception.

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

## Honors Material - Measuring Code Performance (and Sorting!)

This week's lab you will learn how to compare the run speed for different possible implementations of code, and learn how to conduct these experiments.  In our examples we will use sorting algorithms, so let's start by talking a bit about sorting.


### Background: Sorting

When talking about code efficiency, the most common type of algorithmic problem to talk about (as you'll learn in CSE 331) is sorting.  The idea behind the sorting problem is simple and intuitive: If you have a container of elements (lets say a vector of ints for our example), how do you put those elements in order?  Typically we want the order to be from the smallest element to the largest.

One of the simplest sorting algorithms is called "Selection Sort".  This repeatedly finds the smallest unsorted value remaining and puts it next in sorted order; when there are no values remaining, selection sort is done.  Here is an example of what selection sort looks like on a vector of int in C++:

```c++
void SelectionSort(std::vector<int> & vals) {
  // Fill in positions one at a time.
  for (auto next_it = vals.begin(); next_it < vals.end(); ++next_it) {
    // Scan of the minimal value remaining and put it in place.
    auto min_it = std::min_element(next_it, vals.end());
    std::swap(*next_it, *min_it);
  }
}
```

Much more complex algorithms are also possible.  For example, a popular algorithm is called "Merge Sort".  It works off of the idea that sorting long lists of numbers takes MUCH longer than shorter lists, so it would be faster to just sort short lists and merge them together.  In fact, `<algorithm>` already gives us `std::inplace_merge()` which we can use to do the job.

```c++
void MergeSort_Range(std::vector<int> & vals, int start, int end) {
  int sort_size = end - start;
  if (sort_size <= 1) return;          // 0 or 1 element is already sorted!
  int midpoint = (start + end) / 2;
  MergeSort_Range(vals, start, midpoint);    // Sort first half
  MergeSort_Range(vals, midpoint, end);      // Sort second half
  std::inplace_merge(vals.begin()+start, vals.begin()+midpoint, vals.begin()+end);
}

// Full merge sort starts with the entire vector as the range.
void MergeSort(std::vector<int> & vals) {
  MergeSort_Range(vals, 0, vals.size());
}
```

You should try both of these algorithms out and make sure you can sort some data.

Great -- now we have two different sorting algorithms that work, how do we tell which one is faster?


### Background: Measuring time in C++

The C++ Standard Library provides a variety of techniques for examining the current time.  A simple way to measure how long a function takes to run is to record the time, run the function, and then record the time again.

For example, if we have a function called `Octazooka()` and we want to time it, we can include `<chrono>` and then run:

```c++
    auto start_time = std::chrono::steady_clock::now();
    Octazooka();
    auto end_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time-start_time;
    std::cout << "Run time: " << elapsed_seconds.count() << "s" << std::endl;
```

The code above shows you how to measure time in C++, but you still need to make sure to do the proper measurements.  For example, if a function takes a vector as an argument, how large should that vector be?  What data should it contain?  If you are sorting, what would happen if the input data is already sorted, versus randomized?


### Assignment

For this assignment you will write code to conduct measurements.  NOTE: Substantial starter code is available on Coding Rooms; in addition to the functions shown here, there are also the helper functions `PrintVector()` to print a vector (limiting it to the first *N* entries, since some of these vectors will be large) and `MakeRandomVector()` which will generate a `vector<int>` of a desired size, filled with random values between 0 and two billion.

__Step 1__: Write a function called `TimeSortFunction()` that takes two arguments: a sort function and a int _N_ that indicates how many values it should be tested on.  It should then return the time (in seconds) that the function took to run.  It's signature should be:

```c++
using sort_fun_t = std::function< void(std::vector<int> &) >;
double TimeSortFunction(sort_fun_t fun, int N);
```

Make sure that you time how long it takes for the sort to run, but do not include the time to generate the random vector.  Also, remember that you need to include `<functional>` to have access to `std::function`.

__Step 2__: Compare the SelectionSort() and MergeSort() functions above using your new timing function.  Which one is faster?  Make sure to test it on a range of values, including 10 values, 1000 values, and 100,000.

__Step 3__:  Write a second function called `AnalyzeSortFunction()`.  This one should take as an argument a single sort function.  It should test that sort function first with one value, then 10, then 100, each time multiplying _N_ by 10 and recording the run time in a vector.  Stop as soon as sort takes more than 0.1 seconds and return the vector or run times.

Use your new function to analyze SelectionSort() and print the results.  How far does it get?  Is each timing approximately 10x the previous, or is it much slower than that?  Now do the same analysis for MergeSort()?


⭐ Show the TA your comparison times (or answer the associated questions in the Honors lab).


### Trivia

While selection sort and merge sort are two very popular sorting techniques, the two most common are insertion sort and quick sort.

In the "Insertion Sort" algorithm, items in a container are considered one at a time and are sequentially placed into sorted order.

```c++
void InsertionSort(std::vector<int> & vals) {
  // Make each value as 'key' and put it into sorted position.
  for (int key_id = 1; key_id < vals.size(); ++key_id) {
    const int key = vals[key_id];  // Grab current key value

    // Shuffle elements down making room for the key.
    int test_id = key_id - 1;      // Scan from element before key
    while (key < vals[test_id] && test_id >= 0) {
      vals[test_id + 1] = vals[test_id];
      --test_id;
    }
    vals[test_id + 1] = key;       // Put the key in place.
  }
}
```

This algorithm is relatively quick to implement and a similar speed to selection sort on random inputs.  It's real advantage comes when inputs are almost sorted already -- it is one of the fastest algorithms for minor adjustments like that.  Try it out!

The fastest of the standard algorithms is called "Quick Sort".  It works by picking an element to use as a pivot point for a partition.  All of other values less than the pivot are placed before it and all other values are placed after it, leaving the pivot in it's correct sorted position.  The Quicksort Algorithm is then run recursively on the values before the pivot and on the values after the pivot.

To begin with, we need a partition algorithm that takes a vector of values, the start position, the end position, and the pivot value.  Everything less than the pivot is moved to the beginning of the partition, leaving everything else at the end.  The new pivot position is then returned.

```c++
size_t Partition(std::vector<int> & vals, size_t start, size_t end, int pivot) {
  size_t divide_pos = start;
  for (size_t id = start; id < end; ++id) {
    if (vals[id] < pivot) {
      std::swap(vals[divide_pos], vals[id]);
      divide_pos++;
    }
  }
  return divide_pos;
}
```

We can then use Partition() as a key element of QuickSort:

```c++
void QuickSort(std::vector<int> & vals, size_t start, size_t end) {
  size_t sort_size = end - start;
  if (sort_size <= 1) return; // 0 or 1 elements means already sorted.
  int pivot = vals.at(start);
  size_t middle = Partition(vals, start, end, pivot);
  QuickSort(vals, start, middle);
  QuickSort(vals, middle+1, end);
}
```

And, of course, we want to overload Quicksort() so that we can call it with just the vector that we want to sort.

```c++
void QuickSort(std::vector<int> & vals) { QuickSort(vals, 0, vals.size()); }
```

If you want to try out this one too, you may be impressed at how fast it is.
