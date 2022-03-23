---
title: Lab - Linked List
---

# Lab - Linked List

There is no Unix tutorial this week

## Coding Assignment

Today, we're going to practice pointer manipulation in the context of a singly-linked list. [You can find more information regarding linked lists here.](https://en.wikipedia.org/wiki/Linked_list)

### Background

[Download the starter code provided here.](../assets/downloads/lab_linked_list.zip)

In a nutshell: a singly-linked list is a data structure for implementing a generic array of elements, where each node has data, and a pointer to the next node. The list structure typically has pointers to the list's first node and last node. A singly-linked list's first node is typically called the _head_, and the last node the _tail_.

<div align="center">
    <img src="../assets/images/labs/linked_list.svg">
</div>

Linked above is a header file containing the definition for a singly-linked list class named `SingleLink`, and a definition for a linked list node class named `Node`.

Below is the interface for the two classes as it stands right now:

```c++
struct Node {
    public:
        int data_;
        Node *next_;
    
        Node() : data_(0), next_(nullptr) {};
        Node(int d) : data_(d), next_(nullptr) {};
};
```

- `Node` has two private members, `Node* next_` and `int data_`.
    - `next_` is a pointer to another instance of type `Node`; the "chain" that makes up the structure of the entire list.
    - `data_` is the value held by the `Node`. For the purposes of today's lab, it'll only be allowed to hold integers.
- It has two constructors, a default that initializes `data_` to 0, and a one-parameter variant that initializes `data_` to the incoming argument.

```c++
class SingleLink {
    private:
        Node *head_;
        Node *tail_;

    public:
        SingleLink();         
        SingleLink(int dat);    
        void append_back(int);

        friend std::ostream& operator<<(std::ostream &out, SingleLink &s);
        bool del(int val);
        Node& operator[](size_t index);
        
        // Rule of three stuff
        ~SingleLink();
        SingleLink(const SingleLink &);
        SingleLink& operator=(SingleLink);
};
```
- `SingleLink` has two private members, `Node* head_` and `Node* tail_`, which are pointers to the first and last node of the list, respectively.
    - If the list is ever empty, `head_` and `tail_` should point to `nullptr`.
    - If the list ever has one `Node`, both the `head_` and `tail_` should point to that one `Node`.
- `SingleLink` has two constructors; a default with no arguments, and a one-parameter variant that should add a `Node` with data, `dat`, to the list.
    - If the one-parameter variant is invoked, the head and tail pointers will need to be adjusted to point to this new `Node`.

### What's missing?

Pretty much everything. But, this is an opportunity to get more practice with pointers, and get a feel for how to program something you'll be becoming much more familiar with in CSE 331. You probably won't finish all of it, but work through from the beginning and see how far you can get! 

### Program Specifications

Download and extract the starter code's .zip file into your working directory (see top of Background). Next, create a 'singlelink.cpp' implementation file. You are _only_ going to be modifying the implementation file and main.cpp. If you submit to Coding Rooms, only the implementation file is needed for submission.

None of the Rule of Three functions have been implemented. If you have the time, it would be good if you implemented those.

Before jumping into the methods, I would make the default and one-parameter constructors.

Listed below are the methods you'll want to implement. I recommend designing these methods in the order they appear down this list.

&nbsp;

```c++
void append_back(int dat)
```

Method function; creates a new `Node` instance with `data_=dat` and appends it to the end of the list. 

Make sure you use dynamic allocation (the `new` keyword) so that the `Node` you create isn't deleted when it falls out of scope.

Also make sure that you're re-routing the `head_` and `tail_` pointers correctly (what happens when this is the first `Node` being appended vs. when it's the second `Node` being appended?)

&nbsp;

```c++
ostream & operator<<(ostream &out, SingleLink &s)
```

Friend function; pushes the `data_` member of each `Node` instance in the list to the output stream, `out`, and returns `ostream &`.
    
I recommend modifying 'main.cpp' to show that your method works before moving on. Call the `append_back()` method with, say, integers `{1, 2, 4, 8}`, and then use `cout` to print them.

&nbsp;

The next task on our list is the `del()` method (we can't call it `delete()`, since `delete` is a keyword ☹️). `del()` should remove a particular value from the list. Before you write any code, identify all of the cases your list might have to deal with. Type them as comments under the `del()` method.

⭐ Show the TA your working `append_back()` and `operator<<()` functions. And, show your TA all of the cases `del()` must account for before moving on.

&nbsp;

```c++
bool del(int val)
```

Searches through the list for the first `Node` that has the same `data_` value as `val`. If found, deletes the `Node` and returns `true`, otherwise returns `false`.

Again, I recommend modifying 'main.cpp' for testing.

&nbsp;

```c++
Node & operator[](size_t index)
```

This method is an override for the `[]` operator. On a call, such as `sl[3]`, the argument, 3, is assigned to the parameter, `index`. The return value is a _reference_ to a `Node` so that the `Node` can be modified (i.e., can show up on either side of an assignment operator). 

You'll have to search the list (starting from the `head_` pointer) for the `index`-th `Node`. Then, return a reference to that `Node`, or throw an `out_of_range` exception if you've traversed to the end of the list.

⭐ Show the TA your completed `SingleLink` class. Include example functionality for *all* of the methods.  
