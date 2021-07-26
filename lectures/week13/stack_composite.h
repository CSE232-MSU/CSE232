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

template <typename ElementType>
class Stack {
 private:
  vector<ElementType> vec_;

 public:
  Stack() = default;
  Stack(initializer_list<ElementType> lst) : vec_(lst){};

  // take defaults for the following 4. Vector handles it already.
  Stack() = default;
  Stack(const Stack &s) = default;
  Stack &operator=(const Stack &s) = default;
  ~Stack() = default;

  // stack operations
  ElementType top();
  void pop();
  void push(ElementType);
  bool empty();
  // bool full; // not a problem with vectors
  void clear();

  // friends inline, template matching works properly then.
  friend ostream &operator<<(ostream &out, const Stack<ElementType> &s) {
    out << "(bottom),";
    copy(s.vec_.begin(), s.vec_.end(), ostream_iterator<ElementType>(out, ","));
    out << "(top)";
    return out;
  }
};

template <typename ElementType>
ElementType Stack<ElementType>::top() {
  if (vec_.size() == 0) throw underflow_error("top, empty stack");
  return vec_.back();
}

template <typename ElementType>
void Stack<ElementType>::pop() {
  if (vec_.size() == 0) throw underflow_error("pop, empty stack");
  vec_.pop_back();
}

template <typename ElementType>
void Stack<ElementType>::push(ElementType s) {
  vec_.push_back(s);
}

template <typename ElementType>
bool Stack<ElementType>::empty() {
  return vec_.empty();
}

template <typename ElementType>
void Stack<ElementType>::clear() {
  vec_.clear();
}

#endif
