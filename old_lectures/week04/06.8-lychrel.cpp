#include <iostream>
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::stol;
using std::string;
using std::to_string;

int rev_num(int num) {
  string rev = "";
  string str = to_string(num);
  for (int i = str.size() - 1; i >= 0; --i) {
    rev += str[i];
  }
  return stol(rev);
}

bool is_palindrome(int n) {
  int rnum = rev_num(n);
  return (n == rnum);
}

bool check_lychrel(int n, int limit) {
  int cnt = 0;
  int num = n, rnum = 0;
  while (cnt < limit && (!is_palindrome(num))) {
    rnum = rev_num(num);
    num = num + rnum;
    cnt++;
    cout << cnt << ":" << num << endl;
  }
  cout << endl;
  return cnt == limit;
}

int main() {
  cout << boolalpha;
  int num;
  int limit = 40;
  cin >> num;
  cout << "checking " << num << endl;
  bool result = check_lychrel(num, limit);
  if (result)
    cout << num << " is a lychrel number " << endl;
  else
    cout << num << " is NOT a lychrel number " << endl;
}
