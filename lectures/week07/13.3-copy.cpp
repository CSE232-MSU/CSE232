#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
using std::copy_if;
using std::transform;
#include <iterator>
using std::back_inserter;
using std::ostream_iterator;

bool even(int elem) { return !(elem % 2); }

int main() {
  vector<int> v_i{1, 2, 3, 4, 5};
  vector<int> target(10, 1);

  // overwite 1st 5 of target with v_i
  copy(v_i.begin(), v_i.end(), target.begin());
  for (auto loc = target.begin(); loc != target.end(); ++loc)
    cout << *loc << ", ";
  cout << endl;

  // reset target, only copy over even numbers
  target.assign(10, 1);
  copy_if(v_i.begin(), v_i.end(), target.begin(), even);

  // print with ostream_iterator
  copy(target.begin(), target.end(), ostream_iterator<int>(cout, ", "));
  cout << endl;

  // back_inserter on an empty vector, print that vector with ostream_iterator
  vector<int> v_empty;
  copy(target.begin(), target.end(), back_inserter(v_empty));
  copy(v_empty.begin(), v_empty.end(), ostream_iterator<int>(cout, ", "));
  cout << endl;

  // transform, back_insert, lambda
  vector<int> v_times2;
  transform(v_i.begin(), v_i.end(), back_inserter(v_times2),
            [](int i) { return i * 2; });

  copy(v_times2.begin(), v_times2.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
}
