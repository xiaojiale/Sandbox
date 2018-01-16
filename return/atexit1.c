// Copyright 2018
// License BSD
// Author: Jerry Xiao
// This is the test of using int atexit(void (*func)(void))

#include <stdio.h>
#include <stdlib.h>

void exit_fn1();
void exit_fn2();

int main()
{
  // post exit function #1
  atexit(exit_fn1);
  // post exit function #2
  atexit(exit_fn2);
  printf("Hello World!\n");
  return 0;
}

void exit_fn1()
{
  printf("Exit function #1 called\n");
  exit(1);
  printf("test");
}

void exit_fn2()
{
  printf("Exit function #2 called\n");
  atexit(exit_fn1);
}
