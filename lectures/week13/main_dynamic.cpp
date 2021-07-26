#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <stdexcept>
using std::underflow_error;

#include "stack.h"

int main() {
  // exercise things a bit
  Stack<char> stk_chr = {'a', 'b', 'c'};

  cout << "==== char stack ====" << endl;
  cout << stk_chr << endl;
  cout << "Top:" << stk_chr.top() << endl;
  stk_chr.pop();
  stk_chr.push('z');
  cout << stk_chr << endl;
  for (int i = 1; i < 20; ++i) stk_chr.push(static_cast<char>('c' + i));
  cout << stk_chr << endl;

  while (!stk_chr.empty()) stk_chr.pop();

  try {
    stk_chr.pop();
  } catch (underflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  try {
    stk_chr.top();
  } catch (underflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  stk_chr.clear();
  cout << stk_chr << endl;

  cout << endl;
  cout << "==== long stack ====" << endl;
  Stack<long> stk_lng = {1, 2, 3, 4};
  cout << stk_lng << endl;
  cout << "Top:" << stk_lng.top() << endl;
  stk_lng.pop();
  stk_lng.push(100);
  cout << stk_lng << endl;
  for (int i = 1; i < 20; ++i) stk_lng.push(100 + i);
  cout << stk_lng << endl;

  while (!stk_lng.empty()) stk_lng.pop();

  try {
    stk_lng.pop();
  } catch (underflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  try {
    stk_lng.top();
  } catch (underflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  stk_lng.clear();
  cout << stk_lng << endl;
}
