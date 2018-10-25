#include <iostream>
#include <vector>

#define STACK_CAPACITY 10

#if 0
typedef struct {
  int data;
}Elem_t;
#endif

struct Elem_t {
  int data;
};

class stack {
  public:
    vector<Elem_t> v;
    int top;
    int capacity;
    int cur_len;

    void init();
    void clear();
    bool is_empty();
    Elem_t get_top_elem();
    bool push(Elem_t e);
    bool pop(Elem_t &e);
    int get_len();
    void traverse();
};

