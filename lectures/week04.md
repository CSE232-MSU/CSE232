---
title: Week 04
---

<span style="color:red">This document is currently being updated!</span>.

# Week 04

[Lecture slides (Type Modifiers Part 2)](https://drive.google.com/open?id=1tzVVgcN35-OSPjuDmzsBnJfjwJ3YCQoXcfBMHWCiAXY)

[Lecture slides (Strings)](https://drive.google.com/open?id=1pkwRkG6oExzp5BukjuinIbcVaBKubT75TTpJvUC7x5U)

### Pointers Visualized

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/js8u2WZJvn8" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### Const

[05.3-const.cpp](week04/05.3-const.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/myQqQUxeDtI" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### Type Inference

[05.4-auto.cpp](week04/05.4-auto.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/hmSRTjcfI-I" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### The Unsigned Type

[05.5-unsigned.cpp](week04/05.5-unsigned.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/pAVDso7_Das" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

The most common situation that you will encounter unsigned types is returned from the `.size()` member functions of containers in the STL. Any time you encounter such an unsigned type, you should immediately cast it to a signed type.

```c++
int string_size = static_cast<int>(s.size());
```

### Chars

[06.1-chars.cpp](week04/06.1-chars.cpp)

[06.2-charOps.cpp](week04/06.2-charOps.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/39FBf3QzyJ8" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### Strings

[06.3-basic_strings.cpp](week04/06.3-basic_strings.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/-0t93juV_f4" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### More String Methods

[06.4-input.cpp](week04/06.4-input.cpp)

[06.5-range.cpp](week04/06.5-range.cpp)

[06.6-more_strings.cpp](week04/06.6-more_strings.cpp)

[06.7-finds.cpp](week04/06.7-finds.cpp)

[06.8-lychrel.cpp](week04/06.8-lychrel.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/sLFF8gZy3d8" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>
