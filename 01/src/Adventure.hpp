#ifndef HAVE_ADVENTURE_H
#define HAVE_ADVENTURE_H

class Adventure {
  const char* _next_message;

  public:
    void get_next_step();
    void print_next_step();
};

#endif
