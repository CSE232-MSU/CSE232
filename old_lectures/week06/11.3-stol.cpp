#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <stdexcept>
using std::invalid_argument;
using std::out_of_range;
using std::runtime_error;
#include <string>
using std::stoi;
using std::string;

int main() {
  string my_input;
  size_t pos;
  size_t* pos_ptr = &pos;
  bool keep_trying = true;

  while (keep_trying) {
    try {
      cout << "Give me an int:";
      cin >> my_input;

      int my_int = stoi(my_input, pos_ptr);
      if (my_input.length() != pos) {
        throw runtime_error("didn't get it all");
        // continue;
      }

      cout << "Got an int:" << my_int << endl;
      keep_trying = false;
    } catch (invalid_argument& e) {
      cout << "stoi could not convert any of the string" << endl;
      cout << "We'll retry" << endl;
      cout << e.what() << endl;
    } catch (out_of_range& e) {
      cout << "number bigger than max int" << endl;
      cout << "We'll retry" << endl;
      cout << e.what() << endl;
    } catch (runtime_error& e) {
      cout << "Characters mixed in string" << endl;
      cout << "We'll retry" << endl;
      cout << e.what() << endl;
    }

  }  // of the while

  cout << "After the try/catch block, moving on" << endl;
}  // of main
