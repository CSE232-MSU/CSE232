#ifndef STACK_H
#define STACK_H

#include<iostream>
using std::ostream;
#include<string>
using std::string; using std::to_string;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
#include<algorithm>
using std::copy;
#include<initializer_list>
using std::initializer_list;

template<typename ElementType>
class Stack;

template <typename ElementType>
ostream& operator<<(ostream& out, const Stack<ElementType> &s);

template<typename ElementType>
class Stack{
private:
    ElementType *ary_ = nullptr;
    int sz_ = 0;
    int top_ = -1; 
    void grow();

public:
    Stack()=default;
    // Stack(size_t sz);
    Stack(initializer_list<ElementType>);
    
    Stack(const Stack &s);   // copy
    ~Stack();                // destructor
    Stack& operator=(Stack);
    
    ElementType top();
    void pop();
    void push(ElementType);
    bool empty();
    // bool full();
    void clear();
    friend ostream& operator<< <ElementType>(ostream&,
					     const Stack&);
};

template<typename ElementType>
void Stack<ElementType>::grow(){
  ElementType *new_ary;

  if (sz_ == 0){
    new_ary = new ElementType[1]{};
    sz_ = 1;
    // ary_ empty, just assign
    ary_ = new_ary;
  }
  else{
    // use {} to init to default
    new_ary = new ElementType[sz_ * 2]{};
    copy(ary_, ary_+sz_, new_ary);
    sz_ *= 2;
    // stl swap, not Stack swap
    std::swap (new_ary, ary_);
    delete [] new_ary;
  }
}

template<typename ElementType>
Stack<ElementType>::Stack(initializer_list<ElementType> lst){
  sz_ = lst.size();
  ary_ = new ElementType[sz_];
  size_t indx = 0;
  top_ = sz_ - 1;
      
  for (auto e : lst)
    ary_[indx++] = e;
}

template <typename ElementType>
Stack<ElementType>::Stack(const Stack<ElementType> &s){
    sz_ = s.sz_;
    top_ = s.top_;
    ary_= new ElementType[s.sz_];
    copy(s.ary_, s.ary_+s.sz_, ary_);
}

template <typename ElementType>
Stack<ElementType>& Stack<ElementType>::operator=(Stack<ElementType> s){
    // just did the swap here
    swap(this->sz_, s.sz_);
    swap(this->top_, s.top_);
    swap(this->ary_, s.ary_);
    return *this;
}

template <typename ElementType>
    Stack<ElementType>::~Stack(){
    delete [] ary_;
}

template <typename ElementType>
ElementType Stack<ElementType>::top(){
  if (top_ < 0)
    throw underflow_error("top, empty stack");
  return ary_[top_];
}

template <typename ElementType>
void Stack<ElementType>::push(ElementType element){
  if (top_ >= (sz_ - 1) ){
    // never throws, grows!
    grow();
    cout << "Grew to size:"<<sz_<<endl;    
  }
  ary_[++top_] = element;
}

template <typename ElementType>
void Stack<ElementType>::pop(){
  if (top_ < 0)
    throw underflow_error("pop, empty stack");
  --top_;
}

template <typename ElementType>
bool Stack<ElementType>::empty(){
    return top_== -1;
}

template<typename ElementType>
void Stack<ElementType>::clear(){
  top_ = -1;
}

template <typename ElementType>
ostream& operator<<(ostream &out, const Stack<ElementType> &s){
    out << "(bottom)";
    copy(s.ary_, (s.ary_+s.top_+1), ostream_iterator<ElementType>(out, ","));
    cout << "(top)" << endl;
    return out;
}


#endif
