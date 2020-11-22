#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<vector>
using std::vector;
#include<cmath>
using std::sqrt;

int main (){
  long top_of_range;
  int i,j,k;
  cin >> top_of_range;
  vector<bool> primes(top_of_range+1, true);
  
  // for each potential prime
  for(i=2; i<=static_cast<int>(sqrt(top_of_range)); i++){
    if (primes[i]){
      // if prime, mark off all multiples
      for(j=i*i; j<=top_of_range; j += i)
	primes[j] = false;
    }
  }
  
  // print the primes remaning
  long cnt=0;
  for(k=2; k<=top_of_range; k++){
    if(primes[k]){
      cout << k <<",";
      ++cnt;
    }
  }
  cout << "\nprime count to "<<top_of_range<<":"<<cnt<<endl;
}
