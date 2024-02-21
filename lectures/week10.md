---
title: Week 10
---

<span style="color:red">This document is currently being updated!</span>


# Week 10
Sample exam questions to be provided later.


## Vector Details
* Reading: Sections 12.1 and 12.2
* [Lecture slides (Vector Details)]()

<div align="center">

</div>

## Lists and Maps
* Reading: Sections 12.3, 12.4, 12.5, 12.6, and 12.8
* [Lecture slides (Lists and Maps)]()

<div align="center">

</div>


## Lambda Expressions
* Reading: Section 7.3.3 through 7.3.3.1
* [Lecture slides (Copy and Move)]()

<div align="center">

</div>



<span style="color:red">Old Content Below!</span>

# Week 10

[Lecture slides (Classes Part 2)](https://docs.google.com/presentation/d/1PfZqsP_MKAbGhYNzW_awN_9YSy7i7ZO-D_Za3e3FbNE/edit?usp=sharing)

### Constructors

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/SbW_2g6DH20" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

**Note**: correction; the default constructor does *not* initialize variables.

```c++
struct S {
    int i;
}

int main() {
    S s;
    cout << s.i << endl;  // this is undefined behaviour, 'i' has not been initialized
}
```

### Synthetic Default Constructor and Initializer Lists

[16.1-clock.cpp](week10/16.1-clock.cpp)

[16.1-clock.h](week10/16.1-clock.h)

[16.1-main.cpp](week10/16.1-main.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/4PFaSl2tLhY" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### Converting Constructor

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/sJ6u9XP9Y_4" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

**Note**: correction; constructors with default parameters work in the same way as functions with default parameters. `Clock("11:11:PM")` will invoke the string conversion constructor, not the three-argument constructor because the three-argument constructor requires that its first argument is an `int` (not a `string`).

### Code Walkthrough

[16.2-clock.cpp](week10/16.2-clock.cpp)

[16.2-clock.h](week10/16.2-clock.h)

[16.2-main.cpp](week10/16.2-main.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/lnT8fZXtdAQ" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>