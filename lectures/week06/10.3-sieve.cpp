#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <cmath>
using std::sqrt;

int main() {
  int top_of_range;
  cin >> top_of_range;
  vector<bool> primes(top_of_range + 1, true);

  // for each potential prime
  for (int i = 2; i <= static_cast<int>(sqrt(top_of_range)); i++) {
    if (primes[i]) {
      // if prime, mark off all multiples
      for (int j = i * i; j <= top_of_range; j += i) primes[j] = false;
    }
  }

  // print the primes remaning
  int cnt = 0;
  for (int k = 2; k <= top_of_range; k++) {
    if (primes[k]) {
      cout << k << ",";
      ++cnt;
    }
  }
  cout << "\nprime count to " << top_of_range << ":" << cnt << endl;
}
