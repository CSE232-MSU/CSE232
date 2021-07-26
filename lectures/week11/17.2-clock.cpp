#include <string>
using std::string;
#include <sstream>
using std::istringstream;
using std::ostringstream;

#include "17.2-clock.h"

// adjust clock values to be "reasonable"
void Clock::adjust_clock(int mins, int hrs, string prd) {
  int hrs_remainder;
  minutes_ = minutes_ + mins;
  hrs_remainder = minutes_ / 60;
  minutes_ %= 60;

  hours_ = hours_ + hrs + hrs_remainder;
  hours_ %= 12;
  if (prd != "AM" && prd != "PM")
    period_ = "AM";
  else
    period_ = prd;
}

Clock::Clock(int mins, int hrs, string prd) {
  minutes_ = 0;
  hours_ = 0;
  period_ = "";
  adjust_clock(mins, hrs, prd);
  // this->adjust_clock(mins,hrs,prd);
  //(*this).adjust_clock;
}

Clock::Clock(string s) {
  // format is hr:min:period_
  minutes_ = 0;
  hours_ = 0;
  period_ = "";
  vector<string> fields;
  split(s, fields, ':');
  auto hrs = stol(fields[0]);
  auto mins = stol(fields[1]);
  auto prd = fields[2];
  adjust_clock(mins, hrs, prd);
  // this->adjust_clock(mins,hrs,prd);
}

// setters
void Clock::hours(int val) {
  adjust_clock(0, val, period_);
  // this->adjust_clock(0, val, period_);
}

void Clock::minutes(int val) {
  adjust_clock(val, 0, period_);
  // this->adjust_clock(val, 0, period_);
}

void Clock::period(string s) {
  adjust_clock(0, 0, s);
  // this->adjust_clock(0, 0, s);
}

// add to minutes, correct hours if overflow
void Clock::add_minutes(int min) {
  adjust_clock(min, 0, period_);
  // this->adjust_clock(min, 0, period_);
}

// convert clock to string
// declared a friend in header
string clk_to_string(Clock const &c) {
  ostringstream oss;
  oss << "Hours:" << c.hours_ << ", Minutes:" << c.minutes_
      << ", Period:" << c.period_;
  return oss.str();
}

// split string based on sep, ref return of vector<string>
void split(string const &s, vector<string> &elems, char sep) {
  istringstream iss(s);
  string item;
  while (getline(iss, item, sep)) elems.push_back(item);
}
