#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

// Returns the minimum element in vec from the start_index to the end
int recursive_min(vector<int> const& vec, int start_index) {
  if (start_index == static_cast<int>(vec.size()) - 1) {
    return vec[start_index];
  }

  int min_of_rest = recursive_min(vec, start_index + 1);
  if (vec[start_index] < min_of_rest) {
    return vec[start_index];
  } else {
    return min_of_rest;
  }
}

int main() {
  vector<int> input{4, 5, -3, 10};
  int smallest = recursive_min(input, 0);
  cout << "smallest = " << smallest << endl;
}