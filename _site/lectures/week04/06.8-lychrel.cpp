#include<iostream>
using std::cout; using std::endl; using std::cin;
using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::stol;

long rev_num(long num){
  string rev = "";
  string str = to_string(num);
  for (int i = str.size()-1 ; i >= 0 ; --i){
    rev += str[i];
  }
  return stol(rev);
} 

bool is_palindrome(long n){
  long rnum = rev_num(n);
  return (n == rnum);
}

bool check_lychrel(long n, long limit){
  long cnt = 0;
  long num = n, rnum = 0;
  while (cnt < limit && (!is_palindrome(num))){
    rnum = rev_num(num);
    num = num + rnum;
    cnt++;
    cout << cnt << ":" << num << endl;
  }
  cout << endl;
  return cnt==limit;
}

int main() {
    cout << boolalpha;
    long num;
    long limit = 40;
    cin >> num;
    cout << "checking "<< num << endl;
    bool result = check_lychrel(num, limit);
    if (result)
      cout << num << " is a lychrel number " << endl;
    else
      cout << num << " is NOT a lychrel number " << endl;
}
