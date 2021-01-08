#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<vector>
using std::vector;

int main (){
  vector<long> v_long{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<long> zeros(5, 0);
  
  // assignment is copy
  zeros = v_long;
  v_long.front() = -1;
  cout << zeros.front() << ":" << v_long.front() << endl;
  
  // list init is also copy
  zeros = {0,0,0,0,0};
  
  // compare
  cout << boolalpha;
  cout << "Are they:" << endl;
  cout << "Equal:" << (zeros == v_long ? "yep\n" : "nope\n");
  cout << "Less than:" << (zeros < v_long ? "yep\n" : "nope\n");
  cout << "Not Equal:" << (zeros != v_long ? "yep\n" : "nope\n");  
  
  // others
  cout << "front:"<<v_long.front() << endl;
  cout << "back:"<<v_long.back() << endl;
  cout << "size:"<<v_long.size()<<endl;
  v_long.clear();
  cout << "empty:"<<v_long.empty()<<endl;
  v_long.assign(10,1);
}
