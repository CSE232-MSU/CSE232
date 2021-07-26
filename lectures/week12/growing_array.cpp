#include <algorithm>
#include <iostream>
#include <iterator>

void print_array(int* array, size_t size) {
  std::copy(array, array + size, std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

void double_size(int*(&array), size_t& size) {
  size_t new_size = size * 2;
  int* array2 = new int[new_size]{};
  std::copy(array, array + size, array2);
  size = new_size;
  delete[] array;
  array = array2;
}

int main() {
  size_t const size = 2;
  int* array = new int[size];
  array[0] = 9;
  array[1] = 7;
  print_array(array, size);

  size_t new_size = size + 1;
  int* array2 = new int[new_size]{};
  std::copy(array, array + size, array2);

  // Never use array after this point
  delete[] array;

  print_array(array2, new_size);
  array2[2] = 3;
  print_array(array2, new_size);

  std::cout << "Double!" << std::endl;
  double_size(array2, new_size);
  print_array(array2, new_size);

  delete[] array2;
}