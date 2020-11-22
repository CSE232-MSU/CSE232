#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

#include "15.1-clock.h"

// convert a clock to a string
string print_clk(const Clock& c){
  ostringstream oss;
  oss << "Hours:"<< c.hours
      <<", Minutes:"<< c.minutes
      <<", Period:"<< c.period;
  return oss.str();
}
