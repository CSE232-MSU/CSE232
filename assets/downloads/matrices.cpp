#include <iostream>
#include <string>
#include <vector>

template <typename T>
using MatrixRow = std::vector<T>;

template <typename T>
using Matrix = std::vector<MatrixRow<T>>;

/*
Nicely print a matrix. Should have row/column alignment
converts it to a string (doesn't print to cout!!!)
uses width to space elements (setw). Default is 3
*/
template <typename T>
std::string MatrixToString(Matrix<T> const &m, int width = 3) {}

/*
true if the two matrices have the same shape
false otherwise
*/
template <typename T>
bool IsSameSize(Matrix<T> const &m1, Matrix<T> const &m2) {}

/*
matrices must not be empty and must be the same shape:
- if true, return a new matrix that adds m1+m2
- if false, return an empty matrix (no elements)
*/
template <typename T>
Matrix<T> operator+(Matrix<T> const &m1, Matrix<T> const &m2) {}

/*
matrix must not be empty:
- if true, multiply T scalar value by m
- if false, return empty matrix (no elements)
*/
template <typename T>
Matrix<T> operator*(Matrix<T> const &m, T const &scalar_value) {}

int main() {
  // case 1
  std::cout << "Case 1" << std::endl;
  Matrix<int> m1{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  std::cout << MatrixToString(m1, 4) << std::endl;

  /* Latter cases commented so you don't have to write everything at once.
  // case 2
  std::cout << "Case 2" << std::endl;
  Matrix<int> result = m1 + m1;
  if (!result.empty()) {
    std::cout << MatrixToString(result) << std::endl;
  } else {
    std::cout << "could not add" << std::endl;
  }

  // case 3
  std::cout << "Case 3" << std::endl;
  Matrix<int> m2{{0, 1}, {2, 3}, {4, 5}};
  result = m1 + m2;
  if (!result.empty()) {
    std::cout << MatrixToString(result) << std::endl;
  } else {
    std::cout << "could not add" << std::endl;
  }

  // case 4
  std::cout << "Case 4" << std::endl;
  Matrix<double> m_d{{0.3, 1.2}, {2, 3.4}, {4, -5}};
  double factor = 3.8;
  Matrix<double> result_d = m_d * factor;
  if (!result_d.empty()) {
    std::cout << MatrixToString(result_d, 8) << std::endl;
  } else {
    std::cout << "could not multiply" << std::endl;
  }

  // case 5
  std::cout << "Case 5" << std::endl;
  Matrix<int> m3;
  result = m3 * 3;
  if (!result.empty()) {
    std::cout << MatrixToString(result) << std::endl;
  } else {
    std::cout << "could not multiply" << std::endl;
  }
  */
  return 0;
}
