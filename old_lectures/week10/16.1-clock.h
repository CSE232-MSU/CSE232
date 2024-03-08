#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using std::string;

struct Clock {
  int minutes = 0;
  int hours = 0;
  string period;

  Clock();
  Clock(int, int, string);
  void add_minutes(int);
};

string clk_to_string(Clock const&);

#endif
