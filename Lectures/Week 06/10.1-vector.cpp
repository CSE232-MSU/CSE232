#include<iostream>
using std::cout; using std::endl; using std::cin; using std::boolalpha;
#include<string>
using std::string;
#include<vector>
using std::vector;

/*
  wfp 2/9/15
  playing with vectors
*/

int main(){
  vector<long> v_long;
  vector<string> v_string(5,"abc");
  vector<char> v_char{'a', 'b', 'c', 'd'};
  // vector v; // must declare template type

  // size and push_back
  cout << v_long.size() << endl;
  for (int i=0; i<10; ++i)
    v_long.push_back(i*i);
  cout << v_long.size() << endl;

  // capacity
  cout << v_char.size() << endl;
  cout << v_char.capacity() << endl;
  v_char.clear();
  cout << v_char.size() << endl;
  cout << v_char.capacity() << endl;
  for (int i=0; i<10; ++i)
    v_char.push_back( static_cast<char>('a' + i) );
  cout << v_char.size() << endl;
  cout << v_char.capacity() << endl;  

  // access
  cout << v_string[2]<<endl;
  cout << v_char.at(9) << endl;
  cout << v_char[10] << endl;
  v_char.at(9) = 'z';
  v_long.back() = -10;
  cout << v_string[2][1] << endl;

  // print, range-based for
  for(auto element : v_char)
    cout << element <<":";
  cout << endl;

  // print using indexing, indx is of type vector<long>::size_type
  for( vector<long>::size_type indx = 0;
       indx < v_long.size();
       ++indx){
    cout << v_long[indx]<<", ";
  }
  
  cout << endl; 
}
