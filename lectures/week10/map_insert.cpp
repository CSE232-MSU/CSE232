#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::map, std::pair, std::string, std::cout, std::endl;

int main() {
  map<string, int> m {{"Mal", 100}};

  // New Key
  pair<map<string, int>::iterator, bool> result =  m.insert({"Josh", 50});
  cout << "Successful insert? " << result.second << endl;
  pair<string, int> entry = *(result.first);
  cout << entry.first << entry.second << endl;
  
  // Old Key
  result = m.insert({"Mal", 1000000});
  cout << "Successful insert? " << result.second << endl;
  entry = *(result.first);
  cout << entry.first << entry.second << endl;
}