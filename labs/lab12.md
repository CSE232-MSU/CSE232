---
title: Lab - Templates and 2D Vectors
---

# Lab - Templates and 2D Vectors

There is no Unix tutorial this week

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

&nbsp;

This matrix, <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5Ctextbf%7BA%7D" 
alt="\textbf{A}">, has three rows and three columns -- making it a square matrix.

#### Matrix Operations

We will perform two operations on our matrices, both of which yield a new matrix as a result.

The first is _scalar multiplication_. Regardless of the size or shape, if the matrix is not empty, we multiply the scalar value by every entry in the matrix, yielding a new matrix.

<div align="center">
<img src="../assets/images/labs/matrix_mul.svg">
</div>

&nbsp;

Where <img src=
"https://render.githubusercontent.com/render/math?math=%5Clarge+%5Ctextstyle+%5Ctextbf%7B%5Clambda%7D" 
alt="\textbf{\lambda}"> is some scalar (i.e., any number).

The second is _matrix addition_. The shape of two matrices _must be the same_ for addition to go forward. If the shapes are the same, and they are both not empty, we add each row/column value of one matrix to each row/column value of the second matrix in each respective location, yielding a new matrix. We do this for every value between the two matrices.

<div align="center">
<img src="../assets/images/labs/matrix_add.svg">
</div>

&nbsp;

In these depictions, you'll notice that they begin enumerating the row/column indices from 1. Remember that we, programmers, always start indices from 0.

### Program Specifications

[Download the starter code provided here.](../assets/downloads/matrices.cpp)

We will use a `vector<vector<T>>` type as the underlying representation of our matrix, meaning that the type of the elements of the matrix will be templated. Thus, all of our functions must be templated, as well.

In the starter code, we provide two definitions to make things a little easier:

```c++
template<typename T>
using MatrixRow = vector<T>;

template<typename T>
using Matrix = vector<matrix_row<T>>;
```

With these definitions, you can declare a new matrix with the `matrix` type, and declare matrix rows as the `MatrixRow` type.

Implement the following functions:

&nbsp;

```c++
template<typename T>
std::string MatrixToString(Matrix<T> const &m, int width = 3)
```

Converts the matrix, `m`, to a `string` representation. The `width` argument should be used to set the width between elements within the rows of the matrix (use `std::setw()`), defaulted to 3.

&nbsp;

```c++
template<typename T>
bool IsSameSize(Matrix<T> const &m1, Matrix<T> const &m2)
```

Tests if two matrices, `m1` and `m2`, are of the same size/shape.

&nbsp;

```c++
template<typename T>
Matrix<T> operator+(Matrix<T> const &m1, Matrix<T> const &m2) 
```

Adds matrices, `m1` and `m2`, to compose a new matrix. `m1` and `m2` must be identically shaped for addition to occur. If they are _not_ the same shape, return an empty matrix.

⭐ Show your TA when you can successfully handle case 2 (which tests the three functions above).

&nbsp;

```c++
template<typename T>
Matrix<T> operator*(Matrix<T> const &m, T const &scalar_value)
```

Multiplies a matrix, `m`, by the scalar value, `scalar_value`, to return a new matrix. If `m` is an empty matrix, return an empty matrix.

⭐ Show your TA when you can successfully handle all of the cases.

&nbsp;

### Assignment Notes

1.  Start out by solving case 1 and commenting out the rest of the `main()` code. When you've solved it, bring back case 2, solve case 2, and so on.
2.  You can make a temporary row (of type `MatrixRow`) and `push_back()` values on to that. You can then `push_back()` the row onto a matrix (of type `Matrix`). You can reuse the row in your loop, but remember to `clear()` it first.
3.  Make sure the printing of the matrix is nicely aligned, as shown in the output below:

```
Case 1
   0    1    2
   3    4    5
   6    7    8

Case 2
  0   2   4
  6   8  10
 12  14  16

Case 3
could not add
Case 4
    1.14     4.56
     7.6    12.92
    15.2      -19

Case 5
could not multiply
```
