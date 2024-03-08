#include <iostream> // Using include, not import

double square(double x) { // Different brace style
  return x*x; // Indentation with 2 spaces
}

void print_square(double x) {
  std::cout << "the square of " << x << " is " 
            << square(x) << "\n"; // Broke statement into 2
}

int main() {
  print_square(1.234);
}
