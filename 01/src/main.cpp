#include "Adventure.hpp"

int main(void) {
  Adventure adv;

  while (true) {
    adv.get_next_step();
    adv.print_next_step();
  }

  return 0;
}
