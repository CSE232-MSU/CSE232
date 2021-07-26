#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "16.1-clock.h"

int main() {
  Clock my_clk;             // default ctor
  Clock a_clk(1, 1, "PM");  // 3-arg ctor

  cout << clk_to_string(my_clk) << endl;
  cout << clk_to_string(a_clk) << endl;

  my_clk.hours = 1;
  my_clk.minutes = 55;
  my_clk.add_minutes(10);
  cout << clk_to_string(my_clk) << endl;
}
