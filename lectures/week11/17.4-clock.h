#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::ostream;

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
  Clock(Clock const &);  // copy constructor
  ~Clock(){};            // destructor. Does nothing yet
  Clock(int i) : minutes_(i), hours_(0), period_("AM"){};

  // getters
  int hours() const { return hours_; }
  int minutes() const { return minutes_; }
  string period() const { return period_; }

  // setters, defined elsewhere
  void hours(int);
  void minutes(int);
  void period(string);

  // members
  void add_minutes(int);

  // overloaded operator= method
  Clock &operator=(Clock const &);

  // overloaded operator+ method
  // Clock operator+(Clock const &);

  // friends
  friend Clock operator+(Clock const &, Clock const &);
  friend ostream &operator<<(ostream &, Clock const &);
};

// overloaded operator+ function
Clock operator+(Clock const &, Clock const &);
// overloaded operator<< function
ostream &operator<<(ostream &, Clock const &);

void split(string const &, vector<string> &, char);

#endif
