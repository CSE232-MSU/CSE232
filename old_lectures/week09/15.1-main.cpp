#include <iostream>
#include <string>

#include "15.1-clock.h"

using std::cout;
using std::endl;
using std::string;

int main() {
  Clock clk1, clk2;

  clk1.hours = 10;
  clk2.hours = 1;
  cout << clk1.hours << ":" << clk2.hours << endl;
  clk1.minutes = 20;
  clk1.period = "AM";

  Clock &ref_c = clk1;
  Clock *ptr_c = &clk1;
  ref_c.minutes = 10;
  ptr_c->period = "PM";

  cout << "clk1:" << print_clk(clk1) << endl;
}
