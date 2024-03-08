#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using std::string;

struct Clock {
  int minutes;
  int hours;
  string period;
};

string print_clk(Clock const& c);

#endif
