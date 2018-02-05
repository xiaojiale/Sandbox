#include "../inc/a.h"

A::A()
{
}

A::~A()
{
}

int main(int argc, char* argv[])
{
  A* obj = new A();
  A obj2;
  obj->print(argc);
  obj2.print(*argv[1] - '0');
}
