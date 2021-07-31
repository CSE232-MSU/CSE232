#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::ostream;
#include <string>
using std::string;
using std::to_string;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <algorithm>
using std::copy;
#include <initializer_list>
using std::initializer_list;

template <typename T>
class Stack;

template <typename T>
ostream &operator<<(ostream &out, Stack<T> const &s);

template <typename T>
class Stack {
 private:
  T *ary_ = nullptr;
  int sz_ = 0;
  int top_ = -1;
  void grow();

 public:
  Stack() = default;
  // Stack(size_t sz);
  Stack(initializer_list<T>);

  Stack(Stack const &s);  // copy
  ~Stack();               // destructor
  Stack &operator=(Stack);

  T top();
  void pop();
  void push(T);
  bool empty();
  // bool full();
  void clear();
  friend ostream &operator<<<T>(ostream &, Stack const &);
};

template <typename T>
void Stack<T>::grow() {
  T *new_ary;

  if (sz_ == 0) {
    new_ary = new T[1]{};
    sz_ = 1;
    // ary_ empty, just assign
    ary_ = new_ary;
  } else {
    // use {} to init to default
    new_ary = new T[sz_ * 2]{};
    copy(ary_, ary_ + sz_, new_ary);
    sz_ *= 2;
    // stl swap, not Stack swap
    std::swap(new_ary, ary_);
    delete[] new_ary;
  }
}

template <typename T>
Stack<T>::Stack(initializer_list<T> lst) {
  sz_ = lst.size();
  ary_ = new T[sz_];
  size_t indx = 0;
  top_ = sz_ - 1;

  for (auto e : lst) ary_[indx++] = e;
}

template <typename T>
Stack<T>::Stack(Stack<T> const &s) {
  sz_ = s.sz_;
  top_ = s.top_;
  ary_ = new T[s.sz_];
  copy(s.ary_, s.ary_ + s.sz_, ary_);
}

template <typename T>
Stack<T> &Stack<T>::operator=(Stack<T> s) {
  // just did the swap here
  swap(this->sz_, s.sz_);
  swap(this->top_, s.top_);
  swap(this->ary_, s.ary_);
  return *this;
}

template <typename T>
Stack<T>::~Stack() {
  delete[] ary_;
}

template <typename T>
T Stack<T>::top() {
  if (top_ < 0) throw underflow_error("top, empty stack");
  return ary_[top_];
}

template <typename T>
void Stack<T>::push(T element) {
  if (top_ >= (sz_ - 1)) {
    // never throws, grows!
    grow();
    cout << "Grew to size:" << sz_ << endl;
  }
  ary_[++top_] = element;
}

template <typename T>
void Stack<T>::pop() {
  if (top_ < 0) throw underflow_error("pop, empty stack");
  --top_;
}

template <typename T>
bool Stack<T>::empty() {
  return top_ == -1;
}

template <typename T>
void Stack<T>::clear() {
  top_ = -1;
}

template <typename T>
ostream &operator<<(ostream &out, Stack<T> const &s) {
  out << "(bottom)";
  copy(s.ary_, (s.ary_ + s.top_ + 1), ostream_iterator<T>(out, ","));
  cout << "(top)" << endl;
  return out;
}

#endif
