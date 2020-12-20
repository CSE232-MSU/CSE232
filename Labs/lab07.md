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

This matrix, A, has three rows and three columns -- making it a square matrix.

#### Matrix Operations

We will perform two operations on our matrices, yielding a new matrix as a result.

The first is _scalar multiplication_. Regardless of the size or shape, if the matrix is not empty, we multiply the scalar value by every entry in the matrix, yielding a new matrix.

<div align="center">
<img src="../.assets/images/matrix_mul.svg">
</div>

Where λ is some scalar (any number).

The second is _matrix addition_. The shape of two matrices _must be the same_ for addition to go forward. If the shapes are the same, and they are both not empty, we add each row/column value of one matrix to each row/column value of the second matrix in each respective location, yielding a new matrix. We do this for every value between the two matrices.

<div align="center">
<img src="../.assets/images/matrix_add.svg">
</div>

### Requirements

We provide a skeleton file ([lab07.cpp](lab07/lab07.cpp)) that you can modify for the requirements of this lab. You can insert the required functions into this file for the lab. We will use a `vector<vector<T>>` as the underlying representation of our matrix meaning that the type of the elements of the matrix will be templated. Thus all of our functions must be templated.

In the file provided, we provide two using definitions to make things a little easier, to wit:

<pre>template<typename T>
using matrix_row = vector<T>;

template<typename T>
using matrix = vector<matrix_row<T>>;</pre>

Thus you can declare a new matrix with the `matrix` type, and if you need to you can declare an individual row as a `matrix_row` type. These types are used in the main program.

### Function Declarations

The functions are clearly described in the skeleton file provided, read them there.

![](Red_star.svg) Show your TA when you can successfully handle `Case 1`.

![](Red_star.svg) Show your TA when you can successfully handle all the cases.

### Hints

1.  Start out by solving `Case 1` and commenting out the rest of the main code. When you've solved that then include back `Case 2` (so now working on `Case 1` and `Case 2`) and so on.
2.  You can make a temporary row (of type `matrix_row`) and `push_back` values on to that. You can then `push_back` the row onto a matrix (of type `matrix`). You can reuse the row in the your loop, but remember to `.clear()` it first.
3.  Make sure the printing of the matrix is nicely aligned (column and row) as shown in the output below:

    <pre>Case 1
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
    </pre>
