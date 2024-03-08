#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "15.2-clock.h"

int main() {
  Clock my_clk;
  my_clk.hours = 1;
  my_clk.minutes = 55;
  my_clk.period = "AM";

  my_clk.add_minutes(10);
  cout << clk_to_string(my_clk) << endl;
}
