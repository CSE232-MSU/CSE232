#pragma once
#include <string>

class Login {
 public:
  std::string username;
  Login(std::string const &username_, std::string const &password_)
      : username(username_), password(password_) {}

 private:
  std::string password;
  // ...
  friend bool operator==(Login const &, Login const &);
};
