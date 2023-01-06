# Updates to the course in future semesters

## Materials

* Update to new edition of C++ Primer as soon as it is out.
* Provide better links to existing tutorials and videos for students who want to learn the material from a different perspective.
* https://www.codecademy.com/learn/learn-c-plus-plus/modules/learn-cpp-hello-world/cheatsheet

## TAs
* Have students review their TAs halfway through the semester?  This will allow us to identify any TA issues that we might be otherwise missing.  We would have specific questions like
    * Does the TA provide a helpful introduction at the beginning of each laboratory session.
    * Does the TA effectively answer questions during the laboratory?
* At least one instructor should sit in on each lab session at least once during the semester.
* We should provide the TAs with more written materials for how to run each lab.  Both material-based topics to talk about at the beginning and reminders/updates about the course itself.

## Labs

* For lab 2, emphasize . being the current directory, and the use of ./run_this_file
* For the honors portion of lab 4, we should require specific function names and use unit tests to ensure that the functions are correctly built as constexpr.
* Lab 9 should have the students do operator overloading -- it's not especially complicated.
* Talk about -i option for rm to limit accidental deletions?
* Lab 07, teach about shell aliases?

## Projects

* Manual grading
    * Encapsulate member variable to be private (unless they are constants)
    * Guidance on comments
    * Explicit guidance on const (member functions that don't change state, unmodified reference parameters, etc)


## C++ Contents

* Make material more consistent with the standard library.  For example, use size_t when natural for the STL things like std::string::npos to indicate when no position exists.
* Don't use `const &` in parameters for variables small enough to be copied in the same space.
* Move `constexpr` into regular course material?
* Use .hpp for header files, not .h

## Course Goals

1: Students should learn C++ effectively, including syntax, standard library, general language capabilities, and how to code effectively in it.
2: Students should develop a mindset to better prepare them for later CSE courses (e.g., starting projects early, independence, no cheating, etc) as well as more general computational thinking.
3: Final grades should accurately reflect how much C++ students understand by the end of the course.
4: The course should be welcoming, and not more stressful than required to meet the other goals here.
5: The course should also be less stressful and time intensive for Instructors (especially TAs dealing with helprooms, etc).
6: The course should keep students motivated throughout the semester with relatively consistent effort (not fading out, not needing to cram at the end).
7: The rules should be as fair across all students as possible.



## Proposed point breakdown

If we go with 8 and 9 above, we might want a breakdown something like this:
- 250 points - 16 HW + 13 labs (10 points each, but drop 2 of each)
- 390 points - 3 Projects (130 each; 100 tests + 30 manually graded)
- 360 - 3 Exams (30 points per topic; 12 topic categories)

As far as topic categories go, I actually think we would have 15 of them at 30 points each, but the manually graded portions on the projects would count for 3, so only 4 topics would need to be on each exam.

## Possible topic breakdown

In practice there are 15 categories, each assessed for 30 points, so 450 points of concept assessments + 300 project coding + 250 HW/labs)

**Types I** : Numeric types (int, bool, unsigned, float, double), initialization, type encodings
**Core Language I** : Equations, short circuiting, increment, relations, if, while, for, switch (+else, break, continue, etc)
**Standard Library I** : I/O, vectors, asserts, stol, substr, to_string, iterators
**Infrastructure I** : Working with shells (pwd, ls, mkdir, cd, ~ / .., cp, mv, rm, cat, less, help / man / info / -h, I/O Redirection), Simple coding guidelines
(Implicit - **Code crafting I** : manually graded on projects)

**Types II** : Scopes, references, pointers, const, auto, char, strings
**Core II** : Function definitions, calls, side effects, pointer/reference arguments, default arguments, overloading
**Standard Library II** : Generics (accumulate, find, sort, copy), streams / file streams, maps/sets (including unordered & multi)
**Infrastructure II** : Multi-file compilation; include guards; pre-processor basics, More coding guidelines
(Implicit - **Code crafting II** : manually graded on projects)

**Types III** : Templated functions, "using", class, struct (+data members, function members, private/public, this, constructors, destructors)
**Core III** : Lambdas, arrays (+converting arrays and pointers), initializer lists, overloaded operators, Memory management (new, delete, [])
**Coding Techniques** : copy-and-swap idiom, rule-of-three, when to make member functions const, when to use references, pointer bookkeeping (and their use in data structures like linked lists), test-driven development, sorting algorithms
**Infrastructure III** : gdb, ssh, git, compiler options
(Implicit - **Code crafting III** : manually graded on projects)
