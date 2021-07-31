#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>
using std::ostream_iterator;
#include <initializer_list>
using std::initializer_list;
#include <stdexcept>
using std::underflow_error;

template <typename T>
class Stack {
 private:
  vector<T> vec_;

 public:
  Stack() = default;
  Stack(initializer_list<T> lst) : vec_(lst){};

  // take defaults for the following 4. Vector handles it already.
  Stack() = default;
  Stack(Stack const &s) = default;
  Stack &operator=(Stack const &s) = default;
  ~Stack() = default;

  // stack operations
  T top();
  void pop();
  void push(T);
  bool empty();
  // bool full; // not a problem with vectors
  void clear();

  // friends inline, template matching works properly then.
  friend ostream &operator<<(ostream &out, Stack<T> const &s) {
    out << "(bottom),";
    copy(s.vec_.begin(), s.vec_.end(), ostream_iterator<T>(out, ","));
    out << "(top)";
    return out;
  }
};

template <typename T>
T Stack<T>::top() {
  if (vec_.size() == 0) throw underflow_error("top, empty stack");
  return vec_.back();
}

template <typename T>
void Stack<T>::pop() {
  if (vec_.size() == 0) throw underflow_error("pop, empty stack");
  vec_.pop_back();
}

template <typename T>
void Stack<T>::push(T s) {
  vec_.push_back(s);
}

template <typename T>
bool Stack<T>::empty() {
  return vec_.empty();
}

template <typename T>
void Stack<T>::clear() {
  vec_.clear();
}

#endif
