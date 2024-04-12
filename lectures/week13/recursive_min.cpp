#include <iostream>
#include <vector>

// Returns the minimum element in vec from the start_index to the end
int RecursiveMin(std::vector<int> const & vec, int start_index) {
  if (start_index == static_cast<int>(vec.size()) - 1) {
    return vec.at(start_index);
  }
  int min_of_rest = RecursiveMin(vec, start_index + 1);
  if (vec.at(start_index) < min_of_rest) {
    return vec.at(start_index);
  } else {
    return min_of_rest;
  }
}

int main() {
  std::vector<int> input{4, 5, -3, 10};
  std::cout << RecursiveMin(input, 0) << std::endl;
}