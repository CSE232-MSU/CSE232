#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
using std::setw;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

template <typename T>
string print_2d(vector<vector<T>> const& v) {
  ostringstream oss;
  string result = "";
  string temp;
  int width = 3;
  for (auto row : v) {
    for (auto col : row) {
      oss << setw(width) << col << ", ";
    }
    // get row as string, trim last comma, concat with result string
    // clear oss for next row
    temp = oss.str();
    temp = temp.substr(0, temp.size() - 2);
    result = result + temp + "\n";
    oss.str("");
    oss.clear();
  }  // outer for, per row
  return result;
}

int main() {
  vector<double>::size_type const col_size = 4;
  size_t const row_size = 3;

  vector<double> row(col_size, 0.0);
  vector<vector<double>> board(row_size, row);

  cout << fixed << setprecision(1);

  board[0] = {1.0, 2.0, 3.0, 4.0};  // assign whole row
  cout << board[0][2] << endl;
  ;                   // fetch one element, 3.0
  board[1][1] = 5.0;  // assign one element

  for (auto e : board[1])  // print row 1
    cout << e << ", ";
  cout << endl;

  for (auto r : board)  // print col 0
    cout << r[0] << ", ";
  cout << endl;

  cout << board.size() << endl;     // # of rows
  cout << board[0].size() << endl;  // # of columns in row 0

  cout << "Whole Board" << endl;
  cout << print_2d(board) << endl;

  board.push_back(vector<double>{10.0, 11.0, 12.0, 13.0});
  board[3].push_back(14.0);

  cout << print_2d(board) << endl;
  board.pop_back();
  cout << print_2d(board) << endl;
}
