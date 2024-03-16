#include <iostream>
#include <string>

#include "login.h"

int main() {
  Login l1{"Celestia", "star"};
  Login l2{"Rarity", "star"};
  Login l3{"Celestia", "rainbow"};
  Login l4{"Celestia", "star"};
  std::cout << (l1 == l2) << (l1 == l3) << (l1 == l4) << std::endl;
}