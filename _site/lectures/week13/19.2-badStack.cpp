#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<iterator>
using std::ostream_iterator;
#include<algorithm>
using std::copy;
#include<stdexcept>
using std::underflow_error; using std::overflow_error;
#include<initializer_list>
using std::initializer_list;

#include "19.2-badStack.h"

BadStack::BadStack(size_t sz){
  sz_ = sz;
  ary_ = new char[sz]{};
  top_ = -1;
}

BadStack::BadStack(initializer_list<char> c){
  sz_ = c.size();
  ary_ = new char[sz_];
  top_ = sz_ - 1;
  copy (c.begin(), c.end(), ary_);
}

char BadStack::top(){
  if (top_ < 0)
    throw underflow_error("top, empty stack");
  return ary_[top_];
}

void BadStack::pop(){
  if (top_ < 0)
    throw underflow_error("pop, empty stack");
  --top_;
}

void BadStack::push(char element){
  if (top_ >= (sz_ - 1) )
    throw overflow_error("push, full stack");
  ary_[++top_] = element;
}

bool BadStack::empty(){
  return top_ < 0;
}
  
bool BadStack::full(){
  return top_ >= ( sz_ - 1);
}

void BadStack::clear(){
  top_ = -1;
}
  
ostream& operator<<(ostream &out, const BadStack &s){
    out << "(bottom) ";
    copy(s.ary_, s.ary_ + s.top_ + 1,
	 ostream_iterator<char>(out, ","));
    out << " (top)";
    return out;
}


