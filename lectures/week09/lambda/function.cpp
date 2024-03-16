#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

int SumFirstLast(vector<int> const & v) {
  return v.at(0) + v.at(v.size() - 1);
}

int main() {
  vector<int> v = {1, 2, 3, 4};
  cout << SumFirstLast(v) << endl;
}
