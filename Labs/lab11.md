# Lab 11 - Pointer Manipulation

## Lab Assignment

### The Problem

You are going to work on pointer manipulation in the context of a singly linked list. See this link for details on this data structure: [https://en.wikipedia.org/wiki/Linked_list](https://en.wikipedia.org/wiki/Linked_list).

### Some Background

In the lab directory is a definition of a `SingleLink` list in ['singlelink.h'](lab12/singlelink.h). It is slightly non-standard in that this version maintains **two** pointers in the list; the `begin_` pointer, which points to the beginning node in the list and the `last_` pointer, which points to the last node in the list. Below is the interface for the Node as it stands in the 'singlelink.h' file.

#### Note:

*   Private data members: `Node* next_` and `int data_`.
*   Default constructor (done for you)
*   1-arg data constructor (done for you)

#### SingleLink

*   `Node* head_` and `Node* tail_`, pointers to the first and last node of the list
    *   Should both point to `nullptr` if the list is empty
    *   Should both point to the same node if only one element in the list
*   `SingleLink` constructor, no args, default constructor
*   `SingleLink(int n)` 1 parameter constructor. Adds Node as the head and tail (with n as data) into the list.

#### What's missing?

Pretty much everything, but this is an opportunity to work through some things and get a feel for how it has to go. You probably won't get it all but work through from the beginning.

### Tasks

1.  Copy header file '[singlelink.h](lab12/singlelink.h)' to your directory. Also copy '[main.cpp](lab12/main.cpp)' to your working directory. Next create a 'singlelink.cpp' implementation file. You are going to modify only the implementation file and the main.cpp. If you submit to Mimir, only the implementation file is needed for submission.
2.  None of the rule of 3 stuff is there.
    *   If you get time, it would be good if you implemented those.
3.  First make the needed default and single argument constructors.
4.  `void append_back(int dat)`, member function, no return. Creates a `Node` with `data_=dat` and appends that `Node` the end of the list. Make sure you use dynamic allocation (the `new` keyword) so that the Node you create isn't deleted when it falls out of scope.
5.  A friend function to print out the list. You're going to need that so do that early on
    *   `ostream& operator<<(ostream &out, SingleLink& s)`, friend function, returns `ostream&`. Prints the `data_` part of each node in the list. `Node` is a struct with public members, so you can indeed do that.
    *   Modify 'main.cpp' and show that you method works before you move on. Call the append_back with the longs {1, 2, 4, 8}, and then use the `<<` to print it.
6.  Your second task is a `del` member function. (Can't call it delete, that's a keyword). `del` should remove a particular value from the list. Before you write code, you must identify all of the cases you must deal with to do a `del`. Type them in comments for the `del` method.

    ![](Red_star.svg) Show your TA that your code can append and print. And, show your TA all of the cases `del` must account for.

    Having listed the special cases, now you should implement the following:

    `bool del(int val)`. The function:

    1.  Searches through the list for the first `Node` that has the same `data_` value as the parameter `val`. If found, deletes the node and returns true, otherwise returns false.
    2.  Implement the delete method.
    3.  Modify 'main.cpp' to show that it works.
7.  Now define an `operator[]` for SingleLink. The following is the declaration of the operator: `Node & SingleLink::operator[](size_t index)` On a call, such as `sl[3]`, the argument 3 is assigned to the parameter `index`. The return value is a **reference** to a `Node` so that the `Node` can be modified (can show up on either side of an assignment operator). You have to search the list (from the beginning) for the index-th `Node`. Return a reference to that `Node` or throw an exception `out_of_range` exception. Since we haven't covered how exceptions work in class, you can use the following code. (Make sure to ask about it in the lecture).

    <pre>#include<stdexcept>
    using std::out_of_range;  // standard error for a bad index
    ...
    if(badindex)                           // somehow this is a bad index
       throw out_of_range("Index out of range");</pre>

    Again, modify the 'main.cpp' to show that your code works, including catching an `out_of_range` error. Example of a try - catch is below:

    <pre>try {
       result = my_list[999];
    } catch (out_of_range err) {
       cout << "Error, message follows: ";
       cout << err.what() << endl;
    }</pre>

![](Red_star.svg) Show your TA a 'main.cpp' that uses all the methods of SingleLink. And, demonstrate that 'singlelink.h' can do everything.
