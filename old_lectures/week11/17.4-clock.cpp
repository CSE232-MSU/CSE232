#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
using std::ostringstream;

#include "17.4-clock.h"

/*
// overloaded operator+ as a method
Clock Clock::operator+(Clock const &c2){
    Clock new_c;
    new_c.minutes_ = minutes_ + c2.minutes_;
    new_c.hours_ = hours_ + c2.hours_;
    new_c.period_ = period_;
    new_c.adjust_clock(0,0,"");
    return new_c;
}
*/

// overload operator+ as a *function*
// declared a friend in the header
Clock operator+(Clock const &c1, Clock const &c2) {
  Clock new_c;
  new_c.minutes_ = c1.minutes_ + c2.minutes_;
  new_c.hours_ = c1.hours_ + c2.hours_;
  new_c.period_ = c1.period_;
  new_c.adjust_clock(0, 0, c1.period_);
  return new_c;
}

// overload operator<< as a *function*
// declared a friend in the header
ostream &operator<<(ostream &out, Clock const &c) {
  out << "Hours:" << c.hours_ << ", Minutes:" << c.minutes_
      << ", Period:" << c.period_;
  return out;
}

// copy constructor
Clock::Clock(Clock const &c) {
  // this->minutes_ = c.minutes_;
  minutes_ = c.minutes_;
  hours_ = c.hours_;
  period_ = c.period_;
}

// overload assignment method
// should return a ref to lhs
// param must be const
Clock &Clock::operator=(Clock const &c) {
  // this->minutes_ = c.minutes_
  minutes_ = c.minutes_;
  hours_ = c.hours_;
  period_ = c.period_;
  return *this;
}
// 3 arg constructor
Clock::Clock(int mins, int hrs, string prd) {
  minutes_ = 0;
  hours_ = 0;
  period_ = "";
  adjust_clock(mins, hrs, prd);
  // this->adjust_clock(mins,hrs,prd);
}

// string constructor
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
// setters below

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

// split string based on sep, ref return of vector<string>
void split(string const &s, vector<string> &elems, char sep) {
  istringstream iss(s);
  string item;
  while (getline(iss, item, sep)) elems.push_back(item);
}
