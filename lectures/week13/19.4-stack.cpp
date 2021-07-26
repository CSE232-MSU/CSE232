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

#include "19.4-stack.h"

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

Stack::Stack(size_t sz) {
  sz_ = sz;
  ary_ = new char[sz];
  top_ = -1;
}

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

void Stack::push(char element) {
  // cout << "sz:"<<sz_<<" top:"<<top_<<" e:"<<element<<" sub:"<< top_ + (sz_ -
  // 1) << endl;
  if (top_ >= (sz_ - 1)) throw overflow_error("push, full stack");
  ary_[++top_] = element;
}

bool Stack::empty() { return top_ < 0; }

bool Stack::full() { return top_ >= (sz_ - 1); }

void Stack::clear() { top_ = -1; }

ostream &operator<<(ostream &out, Stack const &s) {
  out << "(bottom) ";
  copy(s.ary_, s.ary_ + s.top_ + 1, ostream_iterator<char>(out, ","));
  out << " (top)";
  return out;
}
