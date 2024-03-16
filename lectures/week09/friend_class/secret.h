#pragma once
#include <string>

#include "login.h"

class Secret {
 private:
  std::string text;
  Login creator;

 public:
  Secret(std::string const &text_, Login const &creator_)
      : text(text_), creator(creator_) {}
  std::string GetText(std::string const &);
};