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
using Matrix = vector<MatrixRow<T>>;
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

## Honors Material - "Moving" memory in C++.

Quite often in C++ we will be working with temporary values.  For example, we might create an object as part of an expression, but then immediately copy its contents into another object and stop using it.  When those objects are large, this can be a slow process.  Fortunately C++ has given us *move constructors* and *move operators* to speed this process along.

### Background: A Memory Management Example

Consider the `std::string` class.  One possible way of implementing this class is to store three values:
1. `_mem_ptr` which is a `char *` that points to an array containing the series of characters in the string
2. `_size` which is a `size_t` that tells us the actual length of the string that we are working with.
3. `_capacity` which is a `size_t` that indicates the number of bytes in the array (so it knows how much space it has to grow) 

Why are `_size` and `_capacity` stored separately?  This choice may seem like a waste of variables since we could simply require that `_size` and `_capacity` are always the same.  Any time the length of the string changes we would simply need to allocate new memory to hold the string (and free up the old memory).

As it turns out, memory allocation is one of the slowest common operations in C++.  Every time you request memory from the system, it has to find a chunk that is just the right size.  Too small is not allowed (your data won't fit!), but too big becomes a waste of space, so the system takes its time to pick the right piece.  But this means that every time you allocate memory, you are going to slow down your program.

What the `std::string` class does is try to use its memory for as long as it can.  If a string shrinks, it almost never reallocates, it simply adjusts `_size` down.  then if the string grows again it can check against `_capacity`.  If the longer string will fit in the current memory, we can use it again without having to do a new allocation.  Indeed, the implementation of `std::string` may even allocate more space than needed from the beginning to limit the need for future allocations.

You can even directly influence how a string allocates space.  If you call the `.capacity()` member function on a string, it will tell you the maximum length you can make that string before you need to reallocate.  And if you know ahead of time how many characters you will need, you can use `.reserve(size_t new_capacity)` to adjust that maximum size (this trick is common if you want to fill in a string with push_back, but don't want a series of reallocations to occur.)

How else can we limit the amount of memory management?

### Background: Temporary Variables and Move Operators

Imagine that you have a huge string called `my_book_draft` and you write the code:

```c++
std::string final_book( my_book_draft + "The End." );
```

What happens in this line of code?  Well, if no move constructors are implemented, this code would:
1. Run the plus (`operator+`) function to concatenate the string contained in `my_book_draft` with the string `"The End.`.  This will create a new, temporary string inside the parentheses that must allocate memory for both of the original strings to be copied into.
2. Run the constructor to create the `final_book` object.  The constructor will again allocate memory that the temporary string must be copied into.
3. The temporary object is no longer needed, so its destructor is run and its memory is freed.

Note how 1 and 2 allocate large chunks of memory and then 3 frees a large chunk of memory, making a total of three demanding calls on the memory manager.  Additionally, the whole string is copied twice, which can be expensive for large strings.

Enter: the move constructor.  Move constructors are called whenever the argument being passed into the constructor is a temporary version of the object you are constructing (see Trivia for more on how the compiler defines this).

For `std::string`, the declaration of a move constructor would look like:
```c++
string(string && in);
```

Note that this looks similar to the copy constructor; the only differences are that the input string is NOT const and we have `&&` instead of just a single `&`.  What do these changes mean?  Well, a move constructor should only be called if you can scavenge the insides of the incoming object in order to build the new object.  The `&&` can only be matched by a temporary object that was about to go away anyway, so it ensures that we are not damaging an object we might use again in the future.  And since we are going to tear that object apart, it also makes sense that it can't be made const.

Here is how the move constructor for string might be defined:

```c++
string::string(string && in)
  : _mem_ptr(in._mem_ptr), _size(in._size), _capacity(in._capacity)
{
  in._mem_ptr = nullptr;
}
```

So rather than allocating new memory, the move constructor steals the memory from the temporary object.  Then, in the body of the move constructor, it changes the temporary object to have a null pointer to make sure it knows not to delete its memory in its destructor since it is still in use -- thus also saving a deallocation.

A move operator often looks like a cross between a move constructor and an assignment operator.
```c++
string & string::operator=(string && in) {
  delete _mem_ptr;          // If there was already memory allocated, release it!
  _mem_ptr = in._mem_ptr;   // Copy over the internal state from in.
  _size = in._size;
  _capacity = in._capacity;
  in._mem_ptr = nullptr;    // Release 'in' from owning this memory.
  return *this;
}
```

Note that we can also implement a shorter version:
```c++
string & string::operator=(string && in) {
  std::swap(_mem_ptr, in._mem_ptr);
  _size = in._size;
  _capacity = in._capacity;
  return *this;
}
```

In this case the extra trick is the `std::swap` function.  This function puts the memory we want to keep in the current class, and hands its old memory to the temporary class.  Rather than releasing the memory here, it will simply be released when the temporary memory is destructed. 

### Assignment

You are given a `WordList` class that you are NOT allowed to change and must use it as part of a fancier `Lexicon` class.

Here is the class you can't change:

```c++
class WordList {
private:
  std::vector<std::string> words;
  int version;
public:
  WordList() : version(1) { }
  WordList(WordList & in) : words(in.words), version(in.version+1) { }
  ~WordList() { version = -1; }
  void AddWord(const std::string word) { words.push_back(word); }
  const std::vector<std::string> & GetWords() const { return words; }
  int GetVersion() const { return version; }
  size_t size() const { return words.size(); }
};
```

You need to finish a `Lexicon` class.  Here's a starting point:

```c++
class Lexicon {
private:
  WordList * words_ptr;   // A pointer to the word list being used.
public:
  // Default Constructor.
  Lexicon() : words_ptr(new WordList) { }

  // Copy Constructor.
  Lexicon(const Lexicon & in) : words_ptr(new WordList(*in.words_ptr)) { }

  // Destructor.
  ~Lexicon() { delete words_ptr; }

  // Assignment operator.
  Lexicon & operator=(const Lexicon & in) {
    delete words_ptr;                         // Get rid of old WordList
    words_ptr = new WordList(*in.words_ptr);  // And build a new copy.
    return *this;
  }

  const WordList & GetWordList() const { return *words_ptr; }
  WordList * GetWordsPtr() { return words_ptr; }

  // Operator += can be used to add a word to the WordList
  Lexicon & operator+=(const std::string & word) {
    words_ptr->AddWord(word); return *this;
  }

  // ... lots of other cool features ...
};
```

You must add the following functionality to the `Lexicon` class:
* A member function **`Lexicon operator+(std::string)`** that builds a new word list with the new string added.
* A **move constructor** that steals the WordList from the version being sent in, as per above.
* A **move operator** that steals the old WordList.


### Trivia

Values in C++ can be categorized as either *Lvalues* or *Rvalues*.  These names come from assignment statements.  In general, anything that can be put on the left side of an assignment are Lvalues; if a value can only go on the right side of an assignment then it is an Rvalue.  Rvalues are typically the result of an expression that isn't attached to a variable name so either it gets used immediately or goes away. For example, the sum `var1 + var2` will be lost if not assigned to a variable.  When the compiler needs to decide between a copy constructor or a move constructor, it looks at the value being passed in.  And lvalue argument gets sent to the copy constructor (since it needs to be preserved), while an rvalue argument will go to the move constructor.  (The equivalent is true for deciding between the assignment operator and the move operator).  If no move constructor is available, the copy constructor will always be called.

But what if you know for sure that you will never use an lvalue again and you want it to be scavenged?  In that case, you can use the `std::move()` function to convert a value from lvalue to rvalue.  For example

```c++
std::string new_string( std::move(old_string) );
```

will move the contents of `old_string` into `new_string`, but you really need to be careful; if you try to use `new_string` again, you would be triggering undefined behavior.  None-the-less, for sizable classes these techniques can result in a substantial speed up.
