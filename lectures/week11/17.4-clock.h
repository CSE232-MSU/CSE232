#ifndef CLOCK_H
#define CLOCK_H

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::ostream;

class Clock{
private:
    int minutes_ = 0;
    int hours_ = 0;
    string period_;
    void adjust_clock(int, int, string);

public:
    // constructors
    Clock()=default;
    Clock(int, int, string);
    explicit Clock(string s);
    Clock(const Clock&); // copy constructor
    ~Clock() {};         // destructor. Does nothing yet
    Clock(int i): minutes_(i), hours_(0), period_("AM") {} ; 

    // getters
    int hours() const {return hours_;}
    int minutes() const {return minutes_;}
    string period() const {return period_;} 

    // setters, defined elsewhere
    void hours(int);
    void minutes(int);
    void period(string);
  
    // members
    void add_minutes(int);

    // overloaded operator= method
    Clock& operator=(const Clock&);

    // overloaded operator+ method
    //Clock operator+(const Clock&);

    // friends
    friend Clock operator+(const Clock &, const Clock&);
    friend ostream &operator<<(ostream&, const Clock&);
};

// overloaded operator+ function
Clock operator+(const Clock&, const Clock&);
// overloaded operator<< function
ostream& operator<<(ostream&, const Clock&);

void split(const string &, vector<string> &, char);

#endif
