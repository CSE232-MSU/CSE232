#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "17.4-clock.h"

int main() {
  Clock my_clk;
  Clock a_clk(2, 2, "AM");
  Clock some_clk(a_clk);  // direct call to copy

  cout << "Copy: " << some_clk << endl;         // op<<
  my_clk = a_clk = some_clk;                    // op= chained
  cout << "Assign result: " << my_clk << endl;  // << op
  my_clk = a_clk + a_clk;                       // op+ followed by op=
  cout << "Add result: " << my_clk << endl;     // op<<
  my_clk = a_clk + 1;                           // implicit conversion, op+, op=
  cout << "Add int result: " << my_clk << endl;  // op<<
  my_clk = 1 + a_clk;  // implicit conversion, op+, op=
                       // won't compile as a method!
  cout << "Commute result: " << my_clk << endl;  // op<<
}
