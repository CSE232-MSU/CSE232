#include <iostream>
#include <vector>

int GetTotal(std::vector<int> numbers);

double GetTotal(std::vector<double> numbers);

int main() {
  std::cout << "START" << std::endl;
  std::vector<int> years;
  
  years.push_back(1855);
  years.push_back(1776);
  years.push_back(1999);

  std::cout << "Length: " << years.size() << std::endl; 

  for (int i = 0; i < static_cast<int>(years.size()); ++i) {
    std::cout << "Pos " << i << ": " << years.at(i) << std::endl;
  } 

  int total = GetTotal(years);
  std::cout << "Total: " << total << std::endl;

  std::vector<double> temps {98.6, 100.0, 99.4};
  GetTotal(temps);
}

double GetTotal(std::vector<double> numbers) {
  double total{0};
  for (double number : numbers) {
    total += number;
  }
  return total;
}

int GetTotal(std::vector<int> numbers) {
  int total{0};
  for (int number : numbers) {
    total += number;
  }
  return total;
}
