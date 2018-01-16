#include <stdlib.h>
#include <stdio.h>

void f1()
{
  puts("pushed first");
}
void f2()
{
  puts("pushed second");
}
int main()
{
  atexit(f1);
  atexit(f2);
}
