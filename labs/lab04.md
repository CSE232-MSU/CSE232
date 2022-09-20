---
title: Lab - Functions
---

# Lab - Functions

## Pagers and Help

Often, you want to be able to view files in the terminal (instead of opening them in a text editor like Atom or gedit). There are a few ways to view files from the terminal -- these commands are referred to as _pagers_.

### `cat`

The command, `cat`, is short for "concatenate", which means to link things together. The `cat` command can be followed by any number of filenames and it will output the contents of all of those files concatenated together.  In practice, however, the fact that `cat` will output a files' contents to the terminal is often used to link the output from one program to the input of another or simply to view a file's contents. Invoking the `cat` program is simple:

```bash
cat some_file_name.txt
```

The above command will print the contents of the file to the terminal. However, for large files, `cat` is not user-friendly since the contents will scroll by far faster than you can read them. In practice, if you want to view the contents of a file in the terminal you should use a "pager" instead.

### `less`

Pagers are programs that show you content one _page_ at a time. They are useful for viewing large files. The most popular pager is called `less` because it was derived from an earlier program called `more` (computer science naming can be a little silly). You can invoke the `less` program like so:

```bash
less some_file_name.txt
```

To go to the next page, push the 'f' key (forward) or the space bar on your keyboard. To go back a page, push the 'b' key (backwards). To quit the pager and return to the command line, push 'q'.  You can also use the up and down arrow keys to move one line at a time through a file, or '<' and '>' to jump to the beginning or end of the file, respectively.  These key combinations barely scratch the surface of the capabilities of `less`; if you want way too much information about the command, press 'h' inside `less`.

There are a few programs intended to provide documentation. However, they are often difficult to understand for a beginner. On Ubuntu you invoke them by typing the `help` command, and the name of the program you want information about. They can open up a pager if the entry is long.

### `help`

This command is used to provide information about `bash`, which is the language the terminal is running. Example:

```bash
help cd
```

### `man`

This command (short for "manual") is used to retrieve the documentation about the programs installed on the computer. Example:

```bash
man python
```

### `info`

This command is an alternative to `man`, often used by Unix distributions. Example:

```bash
info ls
```

### `-h`

Most command-line programs will give you a bit of documentation about themselves (like what arguments they accept) if you invoke the program with the `-h` flag. Example:

```bash
python -h
```

⭐ Please show your TA the `man` entry for the program, `git`, then demonstrate paging forward and backward in the entry.

## Coding Assignment

### Background

You remember calculus, right? The basic concept of an integral is the area under a curve, with the curve represented by some function. If you can integrate a function, you can calculate that area directly. But, for some functions, it is easier to approximate that area using discrete, iterative methods. We are going to investigate one of those methods, the [Trapezoidal Rule](http://en.wikipedia.org/wiki/Trapezoidal_rule).

The basic idea is to draw a series of trapezoids that approximate the area under a curve, where the more trapezoids we draw, the better the approximation.

First, remember how to calculate the area of a trapezoid?

<div align="center">
    <img src="../assets/images/labs/trapezoid.svg" width="40%">
</div>

<div align="center">
    <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+A_%7B%5Ctext%7Btrapezoid%7D%7D%3D+%5Cfrac%7Ba+%2B+b%7D%7B2%7Dh" 
alt="A_{\text{trapezoid}}= \frac{a + b}{2}h">
</div>

&nbsp;

We measure the length of the parallel sides, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+a" 
alt="a"> and <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+b" 
alt="b">, then the distance between those parallel sides, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+h" 
alt="h">, add the parallel distances, divide by 2, and multiply everything by <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+h" 
alt="h">.

Now, if we were to place some trapezoid underneath a given curve by rotating it 90 degrees, such that the parallel sides are now bounded between the x-axis and the curve...

<div align="center">
    <img src="../assets/images/labs/trapezoidal_rule_init.png">
</div>

We find that the parallel sides now become the distance from the x-axis to the curve (those black points at the top of the trapezoid, which we'll call <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+y_1" 
alt="y_1"> and <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+y_2" 
alt="y_2">), and the height now becomes the distance between the two parallel sides (which we'll rename to <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5CDelta+x+%3D+h" 
alt="\Delta x = h">).

<div align="center">
    <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+A_%7B%5Ctext%7Btrapezoid%7D%7D+%3D+%5Cfrac%7By_1+%2B+y_2%7D%7B2%7D+%5CDelta+x" 
alt="A_{\text{trapezoid}} = \frac{y_1 + y_2}{2} \Delta x">
</div>

&nbsp;

If we keep adding trapezoids, we can eventually get an approximation for the entire region beneath the curve by summing the areas. And, if we _minimize_ the distance between the two parallel sides, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5CDelta+x" 
alt="\Delta x">, for each trapezoid, we can end up with a pretty accurate approximation for the _integral_ of the function this curve is modeling.

<div align="center">
    <img src="../assets/images/labs/trapezoidal_rule.gif">
</div>

Thus, for a definite integral of a function, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+f" 
alt="f">, bounded between two points on the x-axis, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+a" 
alt="a"> and <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+b" 
alt="b">:

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%5Cint_%7Ba%7D%5E%7Bb%7D+f%28x%29+%5Capprox+%5Csum_%7Bi%3D1%7D%5E%7Bn%7D+%28%5Cfrac%7By_i+%2B+y_%7Bi+%2B+1%7D%7D%7B2%7D+%5CDelta+x%29" 
alt="\int_{a}^{b} f(x) \approx \sum_{i=1}^{n} (\frac{y_i + y_{i + 1}}{2} \Delta x)">
</div>

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%3D+%5Cfrac%7B%5CDelta+x%7D%7B2%7D+%5Csum_%7Bi%3D1%7D%5E%7Bn%7D+%28f%28x_i%29+%2B+f%28x_%7Bi+%2B+1%7D%29%29" 
alt="= \frac{\Delta x}{2} \sum_{i=1}^{n} (f(x_i) + f(x_{i + 1}))">
</div>

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%3D%5Cfrac%7B%5CDelta+x%7D%7B2%7D%5B%28f%28x_1%29+%2B+f%28x_2%29%29+%2B+%28f%28x_2%29+%2B+f%28x_3%29%29+%2B+...+%2B+%28f%28x_n%29+%2B+f%28x_%7Bn%2B1%7D%29%5D" 
alt="=\frac{\Delta x}{2}[(f(x_1) + f(x_2)) + (f(x_2) + f(x_3)) + ... + (f(x_n) + f(x_{n+1})]">
</div>

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%3D%5Cfrac%7B%5CDelta+x%7D%7B2%7D%5Bf%28x_1%29+%2B+2f%28x_2%29+%2B+2f%28x_3%29+%2B+...+%2B+2f%28x_%7Bn%7D%29+%2B+f%28x_%7Bn%2B1%7D%29%5D" 
alt="=\frac{\Delta x}{2}[f(x_1) + 2f(x_2) + 2f(x_3) + ... + 2f(x_{n}) + f(x_{n+1})]">
</div>

&nbsp;

Where <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+n" 
alt="n"> is the number of trapezoids, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5CDelta+x+%3D+%5Cfrac%7Bb+-+a%7D%7Bn%7D" 
alt="\Delta x = \frac{b - a}{n}">, and <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+x_1+%3D+a" 
alt="x_1 = a">, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+x_2+%3D+a+%2B+%5CDelta+x" 
alt="x_2 = a + \Delta x">, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+x_3+%3D+a+%2B+2%5CDelta+x" 
alt="x_3 = a + 2\Delta x">, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+x_4+%3D+a+%2B+3%5CDelta+x" 
alt="x_4 = a + 3\Delta x">, ...

### Program Specifications

You are to write three functions:
    
&nbsp;

```c++
double Fn(double x)
```

Takes an input, `x`, and returns the substitution into the equation <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+-6x%5E2+%2B+5x+%2B+3" 
alt="-6x^2 + 5x + 3">. We'll be using this as our function to integrate over.

&nbsp;

```c++
double Integral(double x)
```

Takes an input, `x`, and returns the substitution into the equation <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+-2x%5E3+%2B+%5Cfrac%7B5%7D%7B2%7D+x%5E2+%2B+3x" 
alt="-2x^3 + \frac{5}{2} x^2 + 3x">. This is the symbolically-manipulated, "actual" integral function of `Fn()`. We'll be using the returns of this function to compare with our approximations.

⭐ Please show the TA your `Fn()` and `Integral()` functions before moving on.

&nbsp;

```c++
double EstimateWithTraps(double a, double b, int n)
```

Takes three parameters: the two definite points of the integral, `a` and `b`, and the number of trapezoids, `n`. This function calculates the area under the curve (represented by `Fn()`) given the provided number of trapezoids over the interval from `a` to `b`. It then returns the sum of the area of trapezoids, i.e., our integral approximation.

&nbsp;

The `main()` function should take four values from the user of the program in this exact order (using `std::cin`):
1.  The lower boundary of the definite integral, `a`
2.  The upper boundary of the definite integral, `b`
3.  A floating point `tolerance` value
4.  The number of trapezoids to initially use in the approximation, `n`

You'll want to run a loop that measures the difference between the actual value of the integration (using `Integral()`) and the estimated value (from `EstimateWithTraps()`).

If the difference is within `tolerance`, report to the user:
1.  The estimate value
2.  `n` (the number of traps)
3.  The difference between the estimate and the actual area under the curve

If the difference is _not_ within `tolerance`, _double_ the value of `n` and re-run. Continue the doubling and re-running until the estimate of the `EstimateWithTraps()` function is within `tolerance` of the actual value from `Integral()`.

All floating point values should have 4 decimal places of precision when displayed.

**Hint**: You might want to consider a do-while statement and the `std::abs()` function (from the `<cmath>` header) in your `main()`.

Example input:
```
0
1
0.01
1
```


Example output from the `main()` (note that the first 4 lines are prompting input from the user):

```
Lower Range:
Upper Range:
Tolerance:
Initial trapezoid count:
Estimate:2.5000, Number of Traps:1, Diff:1.0000
Estimate:3.2500, Number of Traps:2, Diff:0.2500
Estimate:3.4375, Number of Traps:4, Diff:0.0625
Estimate:3.4844, Number of Traps:8, Diff:0.0156
Estimate:3.4961, Number of Traps:16, Diff:0.0039
```

⭐ Please show the TA your working program.

### Assignment Notes

1. Summations in mathematics are inclusively bounded, meaning that the formula we derived earlier is iterating from 1 to <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+n" 
alt="n"> with the 1 _and_ <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+n" 
alt="n"> being an eventual substitution for the subscript, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+i" 
alt="i">. Be careful with how you're modeling the summation -- make sure you're iterating *exactly* `n` times (it's really easy to accidentally iterate `n - 1` or `n + 1` times).

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%3D+%5Cfrac%7B%5CDelta+x%7D%7B2%7D+%5Csum_%7Bi%3D1%7D%5E%7Bn%7D+%28f%28x_i%29+%2B+f%28x_%7Bi+%2B+1%7D%29%29" 
alt="= \frac{\Delta x}{2} \sum_{i=1}^{n} (f(x_i) + f(x_{i + 1}))">
</div>

&nbsp;

2. Calculate <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5CDelta+x" 
alt="\Delta x"> at the beginning of `trapezoid()` to act as a constant. Then, sum together the series, and multiply that sum by <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5Cfrac%7B%5CDelta+x%7D%7B2%7D" 
alt="\frac{\Delta x}{2}"> afterwards. It'll be helpful to have <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5CDelta+x" 
alt="\Delta x"> sitting around to obtain each <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+x_i" 
alt="x_i">.
3. How do you obtain the exact area again? Remember that:

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%5Cint_%7Ba%7D%5E%7Bb%7D+f%28x%29+%3D+F%28b%29+-+F%28a%29" 
alt="\int_{a}^{b} f(x) = F(b) - F(a)">
</div>

## Honors Material - Shifting Computation to Compile Time

Thus far in this course we have focused on writing code that runs when the user executes that program.  If all of the values are known at compile time, however, a variety of techniques exist for a C++ programmer to indicate that they want a calculation to be pre-computed.

### Background

One of the major advantages of C++ over many other languages is the speed of the resulting programs.  For this reason, many computation-intensive programs tend to be written in C++ (or its precursor, C) such as operating systems, compilers, scientific software, web browsers, and even many video games.

Much of the speed of C++ comes from the fact that the compiler works closely with the computer hardware so that a number you're working with is stored in a CPU register, allowing it to be used directly when performing mathematical operations.  But what's faster than all of the values being calculated in the CPU?  Already having the answer because we performed the calculation at compile time!

### The `constexpr` keyword

Obviously, we frequently need to use fixed numbers in C++.  For example, we might want to calculate the area of a circle, so we write a function like:

```c++
double CalcCircleArea(double radius) {
  return 3.1415926535898 * radius * radius;
}
```

Of course, we might have various other functions where we also need to specify π, so it's odd to write it out each time.  One option we have is to create a value that the compiler treats identical to PI, for example.

```c++
constexpr double PI = 3.1415926535898;
```

The `constexpr` keyword before the variable definition ensures that `PI` is always treated as if the value were written in its place.  The right-hand side can even be an equation in a `constexpr` declaration.  For example:

```c++
constexpr PI_SQR = PI * PI;
```

In this case, PI squared is calculated at compile time and whenever `PI_SQR` is used, it's identical to writing the number in its place.  Note that we were able to use the variable `PI` in definining `PI_SQR`.  This usage was only allowed because `PI` was also defined as constexpr.

Such calculations get much more powerful when we use functions.  For example, the Fibonacci numbers start with 0 and 1, and then every subsequent number in the series is the sum of the previous two numbers.  The series starts with 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...

We can write a C++ function to calculate it as:

```c++
constexpr int CalcFibonacci(int id) {
  if (id <= 1) return id;
  return CalcFibonacci(id-1) + CalcFibonacci(id-2);
}
```

The fact that this function was marked as `constexpr` means that if the input is known at compile time, the output can also be produced at compile time.  So the following line would work:

```c++
constexpr int fib_10 = CalcFibonacci(10);
```

In this case fib_10 would be treated identical to the number 55, even though it required non-trivial calculation at compile time.

Note that if the function inputs are not known at compile time, the function can still be used, but the associated computations will only be done at run time.  If the results are needed at compile time (for example, if the function is used as the right-hand side of a constexpr assignment), this will, of course, result in an error.


### Compile-time Input

Often we have numbers directly in the code that we want to use at compile time, but we can also provide new compile inputs without directly changing the code files.  Let us consider the following program that has the user try to guess a `TARGET_VALUE` that must be set a compile time.

```c++
#include <iostream>

int main() {
  int guess = -1;
  while (guess != TARGET_VALUE) {
    std::cout << "What is your guess? ";
    std::cin >> guess;
    if (guess < TARGET_VALUE) std::cout << "Too low!" << std::endl;
    else if (guess > TARGET_VALUE) std::cout << "Too high!" << std::endl;
  }
  std::cout << "You did it!" << std::endl;
}
```

Save this program as `guess.cpp` on your computer.  Now try compiling it normally:

```bash
g++ -std=c++20 guess.cpp
```

(Remember to use `-std=c++2a` instead if your system requires it.)  You'll see that the compiler gives an error because it doesn't know what TARGET_VALUE is.  Now try specifying it at the command line:

```bash
g++ -std=c++20 -DTARGET_VALUE=100 guess.cpp
```

The `-D` flag indicates that you are defining a value for the compiler to use anywhere in the program.

Now run your program with `.a.out`.  If you used the compilation flags above you'll play a little high/low game to guess the number 100.  See the trivia section below if you are curious about the details of how -D works.

### Assignment

Go on to Coding Rooms and write a program to count how many [prime numbers](https://en.wikipedia.org/wiki/Prime_number) exist between the compile-time inputs of START_VALUE and END_VALUE (inclusive).  This calculation should be performed at compile time and not at run time.

How do you know if a number is prime?

The brute force way is to try dividing it by all values from 2 through value-1 and see if it divides evenly by any of them.  It turns out that we can do a good bit better however: we actually only need to test from 2 to the square-root of the value.  We can also use the modulus operator (`%`) rather than proper division since if `X % Y` is equal to zero, that means that Y must evenly divide X.

You should output a single value indicating the number of primes in the given range.

If we wanted your program to calculate the number of primes from 15 to 20 we would compile with:

```bash
g++ -Wall -Wextra -Werror -std=c++20 -DSTART_VALUE=15 -DEND_VALUE=20 main.cpp
```

And you would output `2` since there are two primes in the given range (17 and 20).

### Trivia: Other Compile-Time operations

The -D compiler flag used above is actually an interface to the [C++ Preprocessor](https://en.cppreference.com/w/cpp/preprocessor).  The preprocessor directives all begin with the `#` sign; the one you are already familiar with is `#include` which will take an entire other file and insert it into the beginning of this one.  One other population command is `#define` which will allow you to define a particular string in the rest of the code.  For example, instead of `-DTEST_VALUE=15` on the command line, we could have accomplished the same effect by putting `#define TEST_VALUE 15` in our code file itself.

The C++ preprocessor is both powerful and arcane; there's lots of black magic you can do in C++ if you learn how to use it, but you can also mess up your code in unexpected ways.  A defined value is dropped into place as is, and can be a number, a string, an expression, or almost any other series of characters.  You can even define macros.  For example:

```c++
#define SUM(X,Y) X+Y
```

This will create something that looks like a function, but is not; it just does a search-and-replace on the associated text before proper compilation begins.  There are many pitfalls; for example if you define this macro and then write `SUM(10,15)` in your code, it will replace that with `10+15`.  You might expect that to be treated the same as the number 25, but it is not.  For example, if you wrote `SUM(10,15)*2` what would you expect the result to be?  The answer isn't 50.  It becomes `10+15*2` which the C++ compile then translates to 40 (due to order of operations).

In short, if you want to really know the power of C++, it's worth learning about the preprocessor, but with the modern capabilities of C++, there are fairly few circumstance where you should actually use it.

The `constexpr` keyword can be used outside of the contexts above.  One of the most powerful is immediately after the `if` keyword.  Indeed, `if constexpr` is evaluate at compile time, and only appear in the executable if the resulting expression resolves to true.  As you will discover later in the course, you can have generic code that can work with many different types of variables.  You can use `if constexpr` to change exactly what the code does depending on the type of the variable passed in.

There are also a couple of other keywords similar to `constexpr` since C++ 20.  These include [`constinit`](https://en.cppreference.com/w/cpp/language/constinit) which requires that the value that a variable is initialized to is known at compile time, but does not require the variable to be unchanging.  There is also [`consteval`](https://en.cppreference.com/w/cpp/language/consteval) which requires a function to be fully evaluated at compile time and prevents it from being called at run time.

Finally, if you are interested in going into much more depth about compile time programming, there is a concept used in C++ called ["template metaprogramming"](https://en.wikipedia.org/wiki/Template_metaprogramming), wherein you can have your code adjust rather drastically depending on exactly what variables are used.  This topic, however, would only be explored in depth in a much more advanced C++ course.
