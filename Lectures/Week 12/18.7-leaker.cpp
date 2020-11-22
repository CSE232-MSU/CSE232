#include<cstddef>
using std::size_t;
#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;

int main (){
  int reps = 1024;
  const size_t chunk = 1048576; // be careful!!!
  long last;
  string s;

  for(int i=0;i<reps;i++){
    long *ary = new long[chunk]; // leak memory here each iteration
    ary[0] = 1;
    for (size_t j=1; j < chunk; ++j)
      ary[j] = ary[j-1] + 1;
    last = ary[chunk-1];
  }
  cout << last << endl;
  cout << "A string please:";
  cin >> s;
}
