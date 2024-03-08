#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  std::ifstream input("grades.txt");
  std::ofstream output("output.txt");

  std::string name;
  while (input >> name) {
    std::vector<int> grades;
    int grade;

    // Reads until a non-int occurs (next name)
    while (input >> grade) {
      grades.push_back(grade);
    }
    input.clear();

    int sum = std::accumulate(grades.begin(), grades.end(), 0);
    double average = sum / static_cast<double>(grades.size());
    output << "Average grade for " << name << " is " << average << endl;
  }
  input.close();
  output.close();
}
