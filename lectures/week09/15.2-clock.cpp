#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

#include "15.2-clock.h"

/* add to minutes member,
correct hours if overflow
*/
void Clock::add_minutes(int min) {
  auto temp = minutes + min;
  if (temp >= 60) {
    minutes = temp % 60;
    hours = temp / 60 + hours;
  } else {
    minutes = temp;
  }
}

// convert clock to string
string clk_to_string(Clock const& c) {
  ostringstream oss;
  oss << "Hours:" << c.hours << ", Minutes:" << c.minutes
      << ", Period:" << c.period;
  return oss.str();
}
