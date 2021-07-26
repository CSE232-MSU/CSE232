#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using std::string;
#include <vector>
using std::vector;

class Clock {
 private:
  int minutes_ = 0;
  int hours_ = 0;
  string period_;
  void adjust_clock(int, int, string);

 public:
  // constructors
  Clock() = default;
  Clock(int, int, string);
  explicit Clock(string s);

  // getters
  int hours() const { return hours_; }
  int minutes() const { return minutes_; }
  string period() const { return period_; }
  // setters
  void hours(int);
  void minutes(int);
  void period(string);

  // members
  void add_minutes(int);
  friend string clk_to_string(Clock const &);
};

string clk_to_string(Clock const &);
void split(string const &, vector<string> &, char);

#endif
