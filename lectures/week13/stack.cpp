#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <iterator>
using std::ostream_iterator;
#include <algorithm>
using std::copy;
#include <initializer_list>
using std::initializer_list;
#include <stdexcept>
using std::overflow_error;
using std::underflow_error;

#include "stack.h"

void Stack::grow() {
  char *new_ary;

  if (sz_ == 0) {
    new_ary = new char[1]{};
    sz_ = 1;
    // ary_ empty, just assign
    ary_ = new_ary;
  } else {
    // use {} to init to default
    new_ary = new char[sz_ * 2]{};
    copy(ary_, ary_ + sz_, new_ary);
    sz_ *= 2;
    // stl swap, not Stack swap
    std::swap(new_ary, ary_);
    delete[] new_ary;
  }
}

void Stack::push(char element) {
  if (top_ >= (sz_ - 1)) {
    // never throws, grows!
    grow();
    cout << "Grew to size:" << sz_ << endl;
  }
  ary_[++top_] = element;
}

void swap(Stack &s1, Stack &s2) {
  // have to indicate that in here we are using the stl swap
  std::swap(s1.top_, s2.top_);
  std::swap(s1.sz_, s2.sz_);
  std::swap(s1.ary_, s2.ary_);
}

// calls copy ctor for s (local var)
// swap means s points to old memory
// and dtor called on s (now old mem)
Stack &Stack::operator=(Stack s) {
  swap(*this, s);
  return *this;
}

Stack::Stack(Stack const &s) {
  sz_ = s.sz_;
  top_ = s.top_;
  ary_ = new char[s.sz_];
  // ary_ = s.ary_   BAD IDEA, just copies the pointers!!!
  copy(s.ary_, s.ary_ + s.sz_, ary_);
}

Stack::~Stack() { delete[] ary_; }

Stack::Stack(initializer_list<char> c) {
  sz_ = c.size();
  ary_ = new char[sz_];
  size_t indx = 0;
  top_ = sz_ - 1;

  for (auto e : c) ary_[indx++] = e;
}

char Stack::top() {
  if (top_ < 0) throw underflow_error("top, empty stack");
  return ary_[top_];
}

void Stack::pop() {
  if (top_ < 0) throw underflow_error("pop, empty stack");
  --top_;
}

bool Stack::empty() { return top_ < 0; }

/*
bool Stack::full(){
  return top_ >= ( sz_ - 1);
}
*/

void Stack::clear() { top_ = -1; }

ostream &operator<<(ostream &out, Stack const &s) {
  out << "(bottom) ";
  copy(s.ary_, s.ary_ + s.top_ + 1, ostream_iterator<char>(out, ","));
  out << " (top)";
  return out;
}
