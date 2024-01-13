#include <iostream>

int main() {
  std::cout << "Hello\n";
  char favorite_letter{'J'};
  std::cin >> favorite_letter;
  std::cout << "Your favorite letter is " 
    << favorite_letter << "!" << std::endl;
}