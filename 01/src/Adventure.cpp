#include "Adventure.hpp"

#include <iostream>
#include <string>

void
Adventure::get_next_step() {
  std::string input;
  std::cin >> input;

  if (input.compare("u") == 0) {
    _next_message = "42!";
  } else {
    _next_message = "Here be dragons.";
  }
}

void
Adventure::print_next_step() {
  std::cout << _next_message << std::endl;
}
