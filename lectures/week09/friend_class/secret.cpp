#include "secret.h"

#include <string>

std::string Secret::GetText(std::string const& password) {
  if (password == creator.password) {
    // error: password is private
    return text;
  }
  return "No secret for you!!!";
}