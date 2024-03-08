// Example 3.4
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;

int main() {
  // sum up the numbers, end at 0
  int sum = 0;
  int num;
  cout << "Enter a number. Ends when 0 entered" << endl;
  cout << "Number:";
  cin >> num;
  for (;;) {  // infinite for
    sum += num;
    if (num == 0) break;
    cout << "Number:";
    cin >> num;
  }  // of for
  cout << "Sum is:" << sum << endl;

  // check the divisors of a number
  double dbl, result;
  cout << fixed << setprecision(3);
  cout << "Give me a double to check:";
  cin >> dbl;
  for (int i = 0; i <= 5; i++) {
    if (i == 0) {
      cout << "Can't divide by 0" << endl;
      continue;
    }  // of if
    result = dbl / i;
    // result = dbl / static_cast<double>(i);
    cout << dbl << " divided by " << i << " equals " << result << endl;
  }  // of for
  cout << endl;

  // nested for
  for (int i = 0; i <= 3; ++i) {
    for (int j = 0; j <= 3; ++j) cout << i << ":" << j << ", ";
    cout << endl;
  }
  cout << endl;

  // what breaks, what continues
  for (int i = 0; i <= 3; ++i)
    for (int j = 0; j <= 3; ++j) {
      cout << i << ":" << j << endl;
      if (i == j) {
        cout << "breaking on i:" << i << "," << j << endl;
        break;
      }
      if (j == 0) {
        cout << "continuing on i:" << i << "," << j << endl;
        continue;
      } else
        cout << "i/j=" << i / j << ", ";
    }  // of j loop
}  // of main
