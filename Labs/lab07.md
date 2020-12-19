# Lab 07 - Templates and 2D Vectors

## Lab Assignment

### The Problem

We are going to work on two things:

1.  Writing templated code
2.  2D vectors

### 2D vector as a matrix

You remember matrices don't you? We are going to do some simple manipulation of a matrix, namely: adding two matrices and multiplying a matrix by a scalar.

#### Matrix

A **matrix** is a 2 dimensional (rows and columns) data structure. It has a shape indicated by the number of rows and the number of columns. Though I suppose a matrix could have uneven sized rows, this doesn't usually happen in practice so a matrix is always rectangular, potentially square (based on its shape).

![](lab07/matrix.png)

#### Matrix operations

We will perform two operations on our matrices, yielding a new matrix as a result.

The first is **scalar multiplication**. Regardless of the size or shape, if the matrix is not empty we multiply the scalar value by every entry in the matrix, yielding a new matrix. We do this for every entry in the matrix.

![](lab07/multiply.png)

The second is **addition**. The shape of the two matrices **_must be the same_** for addition to go forward. If the shapes are the same and they are both not empty, we add the same row/col element of each argument matrix into the same row/col element of a new matrix, yielding the new matrix. We do this for every element in the two matrices.

![](lab07/add.png)

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
