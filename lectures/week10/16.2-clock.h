#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using std::string;
#include <vector>
using std::vector;

struct Clock {
  int minutes = 0;
  int hours = 0;
  string period;

  Clock() = default;
  Clock(int m, int h, string s) : minutes(m), hours(h), period(s){};
  Clock(string s);
  // explicit Clock(string s);  // no implicit conversion

  void add_minutes(int);
};

string clk_to_string(Clock const &);
void split(string const &, vector<string> &, char);

#endif
