
#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::ostream;
#include <initializer_list>
using std::initializer_list;

class Stack {
 private:
  char* ary_ = nullptr;
  int sz_ = 0;
  int top_ = -1;
  void grow();

 public:
  Stack() = default;
  // Stack(size_t sz);
  Stack(initializer_list<char>);

  Stack(Stack const& s);          // copy
  ~Stack();                       // destructor
  Stack& operator=(Stack const);  // copy not ref

  char top();
  void pop();
  void push(char);
  bool empty();
  // bool full();
  void clear();
  friend ostream& operator<<(ostream&, Stack const&);
  friend void swap(Stack&, Stack&);
};

void swap(Stack&, Stack&);
ostream& operator<<(ostream&, Stack const&);
#endif
