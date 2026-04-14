#include "utils.hpp"
#include <iostream>
#include <regex>
#include <stdexcept>

void check_email(const std::string& email){
  std::regex em_pat(".+@.+\\..+");
  if(!regex_match(email, em_pat)){
    throw std::invalid_argument("A bad character in your email");
}

}
