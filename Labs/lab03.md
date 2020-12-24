# Lab 03 - Functions

**Warning**: Parts of this lab cannot be seen with GitHub dark mode or a dark mode browser extension enabled.

## Pagers and Help

Often, you want to be able to view files in the terminal (instead of opening them in a text editor like Atom or gedit). There are a few ways to view files from the terminal -- these commands are referred to as _pagers_.

### `cat`

The command, `cat`, is short for "concatenate", which means to link things together. The `cat` program is often used to link the output from one program to the input of another. But, another useful trait of `cat` is to output the contents of a file to the terminal. Invoking the `cat` program is quite simple:

```bash
cat some_file_name.txt
```

The above command will print the contents of the file to the terminal. However, for large files, `cat` is not very user-friendly. You should use a pager instead...

### `less`

Pagers are programs that show you content one _page_ at a time. They are useful for viewing large files. The most popular pager is called `less` because it was derived from a program called `more`, computer science history is a little silly. You can invoke the `less` program like so:

```bash
less some_file_name.txt
```

To go the the next page, push the F key (forward) on your keyboard. To go back a page, push the B key (backwards). To quit the pager and return to the command line, push Q (use your imagination for why it is the Q key).

There are a few programs intended to provide documentation. However, they are often difficult to understand for a beginner. You invoke them by typing the `help` command, and the name of the program you want information about. They can open up a pager if the entry is long.

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

Many programs will give you a bit of documentation about themselves (like what arguments they accept) if you invoke the program with the `-h` flag. Example:

```bash
python -h
```

⭐ Please show your TA the `man` entry for the program, `git`, then demonstrate paging forward and backward in the entry.

## Coding Assignment

### Background

You remember calculus, don't you? The basic concept of an integral is the area under a curve, with the curve represented by some function. If you can integrate a function, you can calculate that area directly. But, for some functions, it is easier to approximate that area using discrete, iterative methods. We are going to investigate one of those methods, the [Trapezoidal Rule](http://en.wikipedia.org/wiki/Trapezoidal_rule).

The basic idea is to draw a series of trapezoids that approximate the area under a curve, where the more trapezoids we draw, the better the approximation.

First, remember how to calculate the area of a trapezoid?

<div align="center">
    <img src="../.assets/images/trapezoid.svg" width="40%">
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
    <img src="../.assets/images/trapezoidal_rule_init.png">
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
    <img src="../.assets/images/trapezoidal_rule.gif">
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
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%3D+%5Cfrac%7B%5CDelta+x%7D%7B2%7D%5B%28f%28x_1%29+%2B+f%28x_2%29%29+%2B+%28f%28x_2%29+%2B+f%28x_3%29%29+%2B+...+%2B+%28f%28x_%7Bn-1%7D%29+%2B+f%28x_%7Bn%7D%29%29%5D" 
alt="= \frac{\Delta x}{2}[(f(x_1) + f(x_2)) + (f(x_2) + f(x_3)) + ... + (f(x_{n-1}) + f(x_{n}))]">
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

The formula here is an equivalence to the one shown in the animation -- put into terms that make it easier to program. Can you see how it's equivalent to the one in the animation? 🤔

### Program Specifications

There is a Mimir assignment associated with this lab for testing purposes.

You are to write three functions:
    
&nbsp;

```c++
double fn(double x)
```

Takes an input, `x`, and returns the substitution into the equation <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+-6x%5E2+%2B+5x+%2B+3" 
alt="-6x^2 + 5x + 3">. We'll be using this as our function to integrate over.

&nbsp;

```c++
double integral(double x)
```

Takes an input, `x`, and returns the substitution into the equation <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+-2x%5E3+%2B+%5Cfrac%7B5%7D%7B2%7D+x%5E2+%2B+3x" 
alt="-2x^3 + \frac{5}{2} x^2 + 3x">. This is the symbolically-manipulated, "actual" integral function of `fn()`. We'll be using the returns of this function to compare with our approximations.

⭐ Please show the TA your `fn()` and `integral()` functions before moving on.

&nbsp;

```c++
double trapezoid(double a, double b, long n)
```

Takes three parameters: the two definite points of the integral, `a` and `b`, and the number of trapezoids, `n`. This function calculates the area under the curve (represented by `fn()`) given the provided number of trapezoids over the interval from `a` to `b`. It then returns the sum of the area of trapezoids, i.e., our integral approximation.

&nbsp;

The `main()` function should take four values from the user of the program in this exact order (using `std::cin`):
1.  The lower boundary of the definite integral, `a`
2.  The upper boundary of the definite integral, `b`
3.  A floating point `tolerance` value
4.  The number of trapezoids to initially use in the approximation, `n`

You'll want to run a loop that measures the difference between the actual value of the integration (using `integral()`) and the estimated value (from `trapezoid()`).

If the difference is within `tolerance`, report to the user:
1.  `n`
2.  The estimate value
3.  The exact value
4.  The `tolerance`

If the difference is _not_ within `tolerance`, _double_ the value of `n` and re-run. Continue the doubling and re-running until the estimate of the `trapezoid()` function is within `tolerance` of the actual value from `integral()`.

All floating point values should have 4 decimal places of precision when displayed.

**Hint**: You might want to consider a do-while statement and the `std::abs()` function (from the `<cmath>` header) in your `main()`.

Example output from the `main()`:

```
Lower Range: 0
Upper Range: 1
Tolerance: 0.01
Initial trapezoid count: 1
Intermediate Result:2.5000, traps:1, diff:1.0000
Intermediate Result:3.2500, traps:2, diff:0.2500
Intermediate Result:3.4375, traps:4, diff:0.0625
Intermediate Result:3.4844, traps:8, diff:0.0156
Trap count:16, estimate:3.4961, exact:3.5000, tolerance:0.0100
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
