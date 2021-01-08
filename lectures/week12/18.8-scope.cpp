#include<iostream>
using std::cout; using std::endl; using std::ostream;

long* fn1(size_t sz, long start, long inc ){
  auto ptr =  new long[sz];
  ptr[0]=start;
  for(size_t i=1; i<sz; i++)
    ptr[i]=ptr[i-1]+inc;
  return ptr;
}

ostream& print(ostream& out, long ary[], size_t sz){
  for(size_t i=0;i<sz;i++){
    out << ary[i];
    if (i < sz-1)
      out << ", ";
  }
  out << endl;
  return out;
}

int main (){
  long *ptr_l;
  // double *ptr_d;
  size_t sz=10;
  ptr_l = fn1(sz, 100, 10);
  cout << ptr_l << endl;
  print(cout, ptr_l, 10) << endl;  
  // leak without this, even though allocated in fn1
  delete [] ptr_l;
}
