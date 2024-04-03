#include <iostream>
#include <random>
#include <string>
#include <algorithm>


int main() {
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<> dist(1,6);
  for (int i{0}; i < 20; ++i) {
    std::cout << dist(gen) << " ";
  }
  std::cout << std::endl;

  std::string text{"This isn't randomized."};
  std::ranges::shuffle(text, gen);
  std::cout << text << std::endl;

}