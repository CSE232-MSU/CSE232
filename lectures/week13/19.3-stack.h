
#ifndef STACK_H
#define STACK_H

#include<iostream>
using std::ostream;
#include<initializer_list>
using std::initializer_list;

class Stack{
private:
    char *ary_ = nullptr;
    int sz_ = 0;  
    int top_ = -1; 

public:
    Stack()=default;
    Stack(size_t sz);
    Stack(initializer_list<char>);
    
    Stack(const Stack &);   // copy
    ~Stack();               // destructor
    Stack& operator=(const Stack &);
    
    char top();
    void pop();
    void push(char);
    bool empty();
    bool full();
    void clear();
    friend ostream& operator<< (ostream&, const Stack &);
};

ostream& operator<< (ostream&, const Stack&);
#endif
