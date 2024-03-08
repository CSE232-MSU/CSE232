#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find;
using std::find_if;
using std::search;
#include <iterator>
using std::distance;

template <typename T>
bool divisible_2_3(T element) {
  return !(element % 2) && !(element % 3);
}

int main() {
  vector<int> v_i{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6};
  int target_i = 3;
  vector<int> target_v{3, 4, 5};

  // simple find. mark is of type vector<int>::iterator
  auto mark = find(v_i.begin(), v_i.end(), target_i);
  if (mark != v_i.end()) {
    cout << "Found:" << *mark << endl;
    int indx = distance(v_i.begin(), mark);
    cout << "Index:" << indx << ", " << v_i[indx] << endl;
  } else
    cout << "Target:" << target_i << " not found" << endl;

  // find second occurrence, starting at mark of first occurrence
  if (mark != v_i.end()) {
    auto mark2 = mark + 1;
    mark2 = find(mark2, v_i.end(), target_i);
    if (mark2 != v_i.end())
      cout << "Found " << target_i << " at index "
           << distance(v_i.begin(), mark2) << endl;
  }

  // find_if, unary predicate
  mark = find_if(v_i.begin(), v_i.end(), divisible_2_3<int>);
  if (mark != v_i.end())
    cout << "Found divis 2 and 3: " << *mark
         << " at index:" << distance(v_i.begin(), mark) << endl;

  // find_if, lambda, evenly divisible by 10;
  mark =
      find_if(v_i.begin(), v_i.end(), [](int const& l) { return l % 10 == 0; });
  if (mark != v_i.end())
    cout << "Even by 10 at:" << distance(v_i.begin(), mark) << endl;
  else
    cout << "No value evenly divisible by 10" << endl;

  // search, looking for target_v sequence in v_i
  mark = search(v_i.begin(), v_i.end(), target_v.begin(), target_v.end());
  if (mark != v_i.end())
    cout << "Found subseq at index:" << distance(v_i.begin(), mark)
         << " of length:" << distance(target_v.begin(), target_v.end()) << endl;

  // search, binary predicate, ignores case
  string source = "This is a test, this is only a test";
  string target = "this";
  auto pos = search(
      source.begin(), source.end(), target.begin(), target.end(),
      [](char constc1, char constc2) { return tolower(c1) == tolower(c2); });
  if (pos != source.end())
    cout << "target at :" << distance(source.begin(), pos) << endl;
  else
    cout << "Not found" << endl;
}
