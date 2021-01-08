#include<iostream>
using std::cout; using std::endl; using std::cin;

void swap (long &first, long &second){
  // a reference is an alias
  long temp;
  temp = first;
  first = second;
  second = temp;
  // return true; // void, no return
}

int main (){
  long one=100, two=200;
  cout << "Pre swap, one has value:" << one 
       << ", two has value:" << two << endl;
  swap(one, two);
  cout << "Post swap, one has value:" << one
       << ", two has value:" << two << endl;
  // cout << temp << endl; // can't, not in scope
}
