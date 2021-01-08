#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include<stdexcept>
using std::out_of_range; using std::invalid_argument;
using std::runtime_error;

int main (){
  string my_str;
  size_t indx;
  long char_long;
  char C;
  
  cin >> my_str;
  cin >> indx;
  
  try {
    C = my_str.at(indx);                   // thows out_of_range
    char_long = stol( string(1,C) );         // throws invalid_argument
    if (char_long == 0)
      throw runtime_error("division by zero");
    cout << my_str.size() / char_long << endl;
  } catch (out_of_range& e) {
    cout << "In the out of range catcher" << endl;
    cout << e.what() << endl;
  } catch (invalid_argument& e) {
    cout << "in the invalid_arg catcher" << endl;
    cout << e.what() << endl;
  }
  /*
  catch(...){
    cout << "something bad happened" << endl;
  }
  */
    
  // past the try-catch construct
  cout << "finishing up" << endl;
}
  
