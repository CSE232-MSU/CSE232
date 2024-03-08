#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

#include "16.1-clock.h"

// default constructor
Clock::Clock() {
  minutes = 0;
  hours = 0;
  period = "AM";
}

// constructor of 3 arguments
Clock::Clock(int min, int hr, string prd) {
  minutes = min;
  hours = hr;
  period = prd;
}

// add to minutes, correct hours if overflow
void Clock::add_minutes(int min) {
  auto temp = minutes + min;
  if (temp >= 60) {
    minutes = temp % 60;
    hours = temp / 60 + hours;
  } else
    minutes = temp;
}

// convert clock to string
string clk_to_string(Clock const &c) {
  ostringstream oss;
  oss << "Hours:" << c.hours << ", Minutes:" << c.minutes
      << ", Period:" << c.period;
  return oss.str();
}
