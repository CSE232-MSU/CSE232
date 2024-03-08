#include <iostream>
using std::boolalpha;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> odds;
  vector<int> evens;

  string s = "abcd1234";
  string letters;
  string numbers;

  cout << boolalpha;

  // iterators, explicit and auto for same type
  vector<int>::iterator v_start = v.begin();
  string::iterator s_start = s.begin();
  auto v_past_end = v.end();
  auto s_past_end = s.end();

  /*  basic, common functions:
      dereference, not equal, preinc
  */
  // deref, lvalue and rvalue
  cout << *v_start << endl;
  cout << *s_start << endl;
  *v_start = 100;
  *s_start = 'z';

  // increase by one, pre-increment
  ++v_start;
  cout << *v_start << endl;
  ++s_start;
  cout << *s_start << endl;

  // comparison, not equal
  cout << (s_start != s_past_end) << endl;

  /* basic capabilities allow for this */
  // print with iterators
  for (auto itr = v_start; itr != v_past_end; ++itr) cout << *itr << ", ";
  cout << endl;

  /* some containers allow more operations */
  // vector iterator math
  cout << "Third:" << *(v_start + 2) << endl;
  cout << "Tenth:" << *(v_past_end - 1) << endl;
  cout << "Who knows:" << *v_past_end << endl;
  cout << "Grouping???:" << (*v_past_end - 1) << endl;
  cout << (v_start > v_past_end) << endl;

  // gather odds and evens, use iterators
  for (auto itr = v.begin(); itr != v.end(); ++itr)
    if (*itr % 2)
      odds.push_back(*itr);
    else
      evens.push_back(*itr);

  // gather letters and numbers
  for (auto itr = s.begin(); itr != s.end(); ++itr)
    if (isalpha(*itr))
      letters.push_back(*itr);
    else if (isdigit(*itr))
      numbers.push_back(*itr);
}
