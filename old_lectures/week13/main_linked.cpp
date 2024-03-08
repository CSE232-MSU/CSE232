#include <iostream>

#include "stack.h"

int main() {
  Stack s;
  s.push('a');
  std::cout << s.top() << std::endl;
  s.push('b');
  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;
}