#include <algorithm>
using std::copy;
#include <iterator>
using std::ostream_iterator;
#include <stdexcept>
using std::underflow_error;

#include "19.1-stack.h"

char Stack::top() {
  if (vec_.size() == 0) throw underflow_error("top, empty stack");
  return vec_.back();
}

void Stack::pop() {
  if (vec_.size() == 0) throw underflow_error("pop, empty stack");
  vec_.pop_back();
}

void Stack::push(char s) { vec_.push_back(s); }
bool Stack::empty() { return vec_.empty(); }
void Stack::clear() { vec_.clear(); }

ostream &operator<<(ostream &out, Stack const &s) {
  out << "(bottom) ";
  copy(s.vec_.begin(), s.vec_.end(), ostream_iterator<char>(out, ","));
  out << " (top)";
  return out;
}
