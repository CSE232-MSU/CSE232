#include "login.h"

#include <string>

bool operator==(Login const& a, Login const& b) {
  return a.username == b.username && a.password == b.password;
  // error password is private
}
