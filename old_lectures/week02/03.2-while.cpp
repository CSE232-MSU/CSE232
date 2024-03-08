// Example 3.2
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  // single statement while
  int cnt = 0;
  while (cnt < 5) ++cnt;
  cout << cnt << endl;

  // while block, count down
  cnt = 5;
  while (cnt > 0) {
    cout << cnt << ", ";
    --cnt;
  }  // of while
  cout << endl << cnt << endl;

  /* basic while structure
     - set up start condition, outside loop
     - measure condition in Boolean
     - change condition in loop
  */
  int user_input;
  cout << "Repeat until zero is entered" << endl;
  cout << "Give me an int:";
  cin >> user_input;
  while (user_input != 0) {
    cout << "Saw the val:" << user_input << endl;
    cout << "Give me another:";
    cin >> user_input;
  }  // end of while
  cout << "Saw the zero" << endl;

  // do while, count digits in integer by integer division
  int count_digs = 0;  // The number of digits in the parameter
  cout << "Count digits in integer:";
  cin >> user_input;
  int temp = user_input;
  do {
    ++count_digs;
    temp /= 10;
  } while (temp != 0);  // of do-while block

  cout << "There are " << count_digs << " digits in the number " << user_input
       << endl;

  cnt = 1;
  while (cnt != 1) {
    // loop never starts, top tested!
  }

  cnt = 1;
  while (cnt = 1) {
    // infinite loop
  }

}  // of main
