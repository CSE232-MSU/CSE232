#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "16.2-clock.h"

int main() {
  Clock my_clk;               // default ctor
  Clock a_clk(1, 1, "PM");    // 3 arg ctor
  Clock str_clk("10:15:AM");  // string ctor

  cout << clk_to_string(my_clk) << endl;
  cout << clk_to_string(a_clk) << endl;
  cout << clk_to_string(str_clk) << endl;

  my_clk.hours = 1;
  my_clk.minutes = 55;
  my_clk.add_minutes(10);
  cout << clk_to_string(my_clk) << endl;

  string s = "12:12:PM";

  // implicit conversion
  cout << clk_to_string(s) << endl;
  // implicit conversion
  cout << clk_to_string(string("11:11:PM")) << endl;
  // cannot, 2 conversions!
  // cout << clk_to_string("11:11:PM"));
  cout << endl;
}
