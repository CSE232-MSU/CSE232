# Lab 03 - Functions

## Pagers and Help

### Pagers

Often, you want to be able to view files in the terminal (instead of opening them in a text editor like Atom or gedit). There are a few ways view files from the terminal.

#### `cat`

The command `cat` is short for concatenate, which means to link things together. The `cat` program is often used to link the output from one program to the input from another. But another useful trait of `cat` is to output the contents of a file to the terminal. Invoking the `cat` program is quite simple:

<pre>cat some_file_name.txt</pre>

The above command will print the contents of the file to the terminal. However, for large files, `cat` is not very user-friendly. Instead, you should use a pager.

#### `less`

Pagers are programs that show you content one **page** at a time. They are useful for viewing large files (files to big to fit in the terminal window). The most popular pager is called `less` because it was derived from a program called `more`, computer science history is a little silly. You can invoke the less program like so:

<pre>less some_file_name.txt</pre>

To go the the next page, push the `f` key (forward). To go back a page, push the `b` key (backwards). To quit the pager and return to the command line, push `q` (use your imagination for why it is the q key).

### Help

There are a few programs that are intended to provide documentation on the programs install on your computer. However, they are often difficult to understand, especially for a beginner. You invoke them by typing the help program and the name of the program you want information about. They may open up a pager if the entry is long.

#### `help`

This command is used to provide information about `bash`, which is the language the terminal is running.

#### `man`

This command (short for manual) is used to retrieve the documentation about the programs installed on the computer.

#### `info`

This command is an alternate to `man`, often used by unix distributions.

Examples:

<pre>help cd
info ls
man python3
</pre>

#### `-h`

Many programs will give you a bit of documentation about themselves (like what arguments they accept) if you invoke the program with the `-h` flag. Example:

<pre>python -h</pre>

![](Red_star.svg) Please show your TA the "man" entry for the program "git", then demonstrate paging forward and backward in the entry.

## Lab Assignment

### Background

You remember calculus don't you? The basic concept of an integral is the area under the curve, the curve represented by some function. If you can integrate a function, you can calculate that area directly, but for some functions it is easier to approximate that area using discrete, iterative methods. We are going to investigate one of those methods, the Trapezoid Rule ([http://en.wikipedia.org/wiki/Trapezoidal_rule](http://en.wikipedia.org/wiki/Trapezoidal_rule)) .

### Trapezoid Rule: the area of a Trapezoid

The basic idea is to draw a series of trapezoids that approximate the area under a curve, where the more trapezoids we draw, the better the approximation.

First, remember how to calculate the area of a trapezoid?

<figure>![](lab03/trap_image.jpg)

<figcaption>From [https://www.pinterest.com/pin/85286986663350250/](https://www.pinterest.com/pin/85286986663350250/)</figcaption>

</figure>

One measures the length of the parallel sides (b1 and b2), then the distance between the parallel sides (h). Add the parallel distances, multiply those values by h, divide by 2.

Let's rotate that trapezoid 90 degrees; and model it as below. Now the b1 length is the curve value f(a), the b2 length f(b) and the height h the difference between b - a.

<figure>![](lab03/area_curve.jpg)</figure>

Given the above, the area would be:

((b - a) * [f(a) + f(b)]) / 2

For two trapezoids next to each other with heights f(a), f(b) and f(c). With f(b) as common side used by the two trapezoids, we get the formula:

(((b - a) * [f(a) + f(b)]) / 2) + (((c - b) * [f(b) + f(c)]) / 2)

In general, for the definite integral:

1.  from a to b
2.  with n equally spaced trapezoids (n + 1 points on the x axis)
3.  grid spacing of h = (b-a / n)

<figure>![](lab03/formula_1.svg) ![](lab03/formula_2.svg)

<figcaption>From [http://en.wikipedia.org/wiki/Trapezoidal_rule](http://en.wikipedia.org/wiki/Trapezoidal_rule)</figcaption>

</figure>

### Program Specifications

There is a Mimir assignment associated with this lab for testing purposes.

1.  Write three functions:
    1.  a function named fn (`double fn(double x)`) to integrate over. Let's use fn → -6x^2 + 5x + 3
        1.  single double parameter, the value x
        2.  double return, the result of the function
    2.  a function named integral (`double integral(double x)`), the actual integral of `fn : integral` → -2x^3 + (5/2)x^2 + 3x
        1.  single double parameter, the value x
        2.  double return, the result of the function

        ![](Red_star.svg) Please show the TA your `integral` function.

    3.  a function name trapezoid (`double trapezoid (double a, double b, long n)`). The specification for trapezoid is:
        1.  take in three parameters:
            1.  the two definite points of the integral `a` and `b` as doubles
            2.  the number `n`, the number of trapezoids, a long
        2.  calculates the area under the curve represented by the function `fn` given the provided number of trapezoids over the interval `a` to `b`.
        3.  returns a double, the sum of the area of the trapezoids.
2.  A main function (`int main()`) that does the following:
    1.  takes in four values from the user (std::cin) (in order)
        1.  A lower range of x (for calculating the integral), `a`
        2.  A higher range of x, `b`
        3.  a float value (`tolerance`)
        4.  an initial guess at the number `n`, the number of trapezoids
    2.  you run a loop that measures the difference between the actual value of the integration (you have the `integral` function so you can calculate the exact value between `a` and `b`) and the estimated value from `trapezoid`
        1.  if the difference is within tolerance, report to the user
            1.  `n`
            2.  estimate value
            3.  exact value
            4.  tolerance
        2.  if the difference is not within tolerance, **double** the value of n and rerun. Continue the doubling and re-running until the estimate of the `trapezoid` function it is within tolerance of the actual value from `integral`.
    3.  Hint: You could use a do-while statement and the std::abs (from the library cmath) in your main function. And, all flointing point output should have 4 decimal places of precision.

### Example run

<pre>Lower Range: 0
Upper Range: 1
Tolerance: 0.01
Initial trapezoid count: 1
Intermediate Result:2.5000, traps:1, diff:1.0000
Intermediate Result:3.2500, traps:2, diff:0.2500
Intermediate Result:3.4375, traps:4, diff:0.0625
Intermediate Result:3.4844, traps:8, diff:0.0156
Trap count:16, estimate:3.4961, exact:3.5000, tolerance:0.0100</pre>

![](Red_star.svg) Please show your TA your working program.
