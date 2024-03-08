#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <stdexcept>
using std::overflow_error;
using std::underflow_error;

#include "19.4-stack.h"

// calls copy ctor to pass the Stack,
// then exercise the copy
void fn1(Stack s) {
  // is the copy good?
  cout << "fn1 copied stk:" << s << endl;
  while (!s.empty()) s.pop();
  for (int i = 0; !s.full(); i++) s.push(static_cast<char>('z' - i));
  cout << "updated fn1 stk:" << s << endl;
}

int main() {
  // exercise things a bit
  Stack stk = {'a', 'b', 'c'};
  cout << stk << endl;
  cout << "Top:" << stk.top() << endl;
  stk.pop();
  stk.push('z');
  cout << stk << endl;

  try {
    stk.push('z');
  } catch (overflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  while (!stk.empty()) stk.pop();

  try {
    stk.pop();
  } catch (underflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  try {
    stk.top();
  } catch (underflow_error const& e) {
    cout << e.what() << ": continuing after error" << endl;
  }

  stk.clear();
  cout << stk << endl;

  // reverse a string
  string user_string = "", reverse_string = "";

  cout << "Give me a string to reverse:";
  getline(cin, user_string);
  Stack rev_stk(user_string.size());

  for (auto ch : user_string) {
    rev_stk.push(ch);
  }

  cout << "rev_stk, pre fn1:" << rev_stk << endl;
  fn1(rev_stk);  // calls the copy ctor
  // is the original stack changed?
  cout << "rev_stk, post fn1:";
  cout << rev_stk << endl;

  // assign call, a copy, then exercise
  Stack stk2 = rev_stk;
  stk2.pop();
  stk2.pop();
  stk2.push('7');
  stk2.push('8');
  cout << "op= stk2:";
  cout << stk2 << endl;

  // is the original stack changed?
  cout << "rev_stk post op=";
  cout << rev_stk << endl;

  while (!rev_stk.empty()) {
    reverse_string = reverse_string + rev_stk.top();
    rev_stk.pop();
  }

  cout << "Original String was:" << user_string << endl;
  cout << "Reversed String was:" << reverse_string << endl;
}
