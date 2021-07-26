#ifndef BAD_STACK_H
#define BAD_STACK_H

#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <iterator>
using std::ostream_iterator;
#include <initializer_list>
using std::initializer_list;

class BadStack {
 private:
  char *ary_ = nullptr;
  int sz_ = 0;
  int top_ = -1;

 public:
  BadStack() = default;
  explicit BadStack(size_t sz);
  BadStack(initializer_list<char> c);

  BadStack(BadStack const &) = default;
  BadStack &operator=(BadStack const &) = default;
  ~BadStack() = default;

  char top();
  void pop();
  void push(char);
  bool empty();
  bool full();
  void clear();

  friend ostream &operator<<(ostream &, BadStack const &);
};
ostream &operator<<(ostream &out, BadStack const &s);

#endif
