# Lab 07 - Templates and 2D Vectors

(There is no Unix tutorial this week)

## Coding Assignment

We are going to get practice with two concepts:
1.  Templated code
2.  Two-dimensional vectors

### Background

You remember matrices, don't you? We are going to do some simple manipulation of a matrix, namely: adding two matrices, and multiplying a matrix by a scalar.

#### Matrix

A _matrix_ is a two-dimensional data structure. It has a _shape_ indicated by the number of rows, and the number of columns. It's important to note that the number of columns *might not always equal* the number of rows. When the number of rows *does* match the number of columns, it's referred to as a _square matrix_.

<div align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Cdisplaystyle+%5Ctextbf%7BA%7D+%3D+%5Cbegin%7Bpmatrix%7D1+%26+2+%26+3%5C%5C4+%26+5+%26+6%5C%5C7+%26+8+%26+9%5Cend%7Bpmatrix%7D" 
alt="\textbf{A} = \begin{pmatrix}1 & 2 & 3\\4 & 5 & 6\\7 & 8 & 9\end{pmatrix}">
</div>

This matrix, <img src=
"https://render.githubusercontent.com/render/math?math=%5Ctextstyle+%5Cmathbf%7BA%7D" 
alt="\mathbf{A}">, has three rows and three columns -- making it a square matrix.

#### Matrix Operations

We will perform two operations on our matrices, both of which yield a new matrix as a result.

The first is _scalar multiplication_. Regardless of the size or shape, if the matrix is not empty, we multiply the scalar value by every entry in the matrix, yielding a new matrix.

<div align="center">
<img src="../.assets/images/matrix_mul.svg">
</div>

Where <img src=
"https://render.githubusercontent.com/render/math?math=%5Ctextstyle+%5Clambda" 
alt="\lambda"> is some scalar (i.e., any number).

The second is _matrix addition_. The shape of two matrices _must be the same_ for addition to go forward. If the shapes are the same, and they are both not empty, we add each row/column value of one matrix to each row/column value of the second matrix in each respective location, yielding a new matrix. We do this for every value between the two matrices.

<div align="center">
<img src="../.assets/images/matrix_add.svg">
</div>

(In these depictions, you'll notice that they begin enumerating the row/column indices from 1. Remember that we, programmers, always start indices from 0)

### Program Specifications

We provide some starter code ([in this .zip file](../.assets/extra/lab07.cpp)) that you can modify for the requirements of this lab. We will use a `vector<vector<T>>` type as the underlying representation of our matrix, meaning that the type of the elements of the matrix will be templated. Thus, all of our functions must be templated, as well.

In the starter code, we provide two definitions to make things a little easier:

```c++
template<typename T>
using matrix_row = vector<T>;

template<typename T>
using matrix = vector<matrix_row<T>>;
```

With these definitions, you can declare a new matrix with the `matrix` type, and declare matrix rows as the `matrix_row` type.

The functions are described in the starter code, you can read more about them there.

⭐ Show your TA when you can successfully handle case 1.

⭐ Show your TA when you can successfully handle all of the cases.

### Assignment Notes

1.  Start out by solving case 1 and commenting out the rest of the `main()` code. When you've solved it, bring back case 2, solve case 2, and so on.
2.  You can make a temporary row (of type `matrix_row`) and `push_back()` values on to that. You can then `push_back()` the row onto a matrix (of type `matrix`). You can reuse the row in your loop, but remember to `clear()` it first.
3.  Make sure the printing of the matrix is nicely aligned, as shown in the output below:

```
Case 1
 0  2  4
 6  8 10
12 14 16

Case 2
could not add

Case 3
1.14    4.56
 7.6   12.92
15.2     -19

Case 4
could not multiply
```