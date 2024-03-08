#ifndef STACK_H
#define STACK_H

using std::ostream;
#include <iostream>
using std::string;
#include <string>
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;

class Stack {
 private:
  vector<char> vec_;

 public:
  Stack() = default;
  // Stack(size_t sz)
  Stack(initializer_list<char> c) : vec_(c){};

  char top();
  void pop();
  void push(char);
  bool empty();
  // bool full();  // not a problem with vectors
  void clear();

  friend ostream& operator<<(ostream& out, Stack const& s);
};

ostream& operator<<(ostream& out, Stack const& s);

#endif
