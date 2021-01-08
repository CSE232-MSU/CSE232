#include<iostream>
using std::cout; using std::endl;

// let template deduce size, we don't have to say!!
template<typename Type, size_t Size>
long squares(const Type (&ary)[Size]){
  Type result=0;
  cout << "sizeof array (template size):"<<sizeof(ary)<<endl;
  for(auto element : ary)
    result = result + (element * element);
  return result;
}

int main (){
  const size_t cnst_sz = 5;
  int ary1[cnst_sz]{8,5,6,7,4};
  cout << squares(ary1) << endl;

  int ary2[]{80,50,60,70,40};
  cout << squares(ary2) << endl;

  size_t sz = 4;
  sz += 1;
  int ary3[sz];
  ary3[sz]={0};
  cout << squares(ary3) << endl;
}
