#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using std::string;

struct Clock {
  int minutes;
  int hours;
  string period;

  void add_minutes(int);
};

string clk_to_string(Clock const&);

#endif
