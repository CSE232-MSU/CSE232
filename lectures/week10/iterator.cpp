#include <iostream>
#include <vector>


int main() {
  int const size = 4;
  char array[size] = {'a', 'b', 'c', 'd'};
  char * beginning = array; // or array + 0 means the same thing
  char * one_past_end = array + size;
  for (char const * current_element = beginning; current_element != one_past_end; ++current_element) {
    std::cout << *current_element;
  }
  std::cout << std::endl;

  std::vector<char> vec = {'a', 'b', 'c', 'd'};
  for (std::vector<char>::iterator iter{vec.begin()}; 
      iter != vec.end(); ++iter) {
    std::cout << *iter;
  }
  std::cout << std::endl;
}