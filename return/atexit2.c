#include <iostream>
#include <stdlib.h>
using namespace std;

void fun1()
{
  cout << "fun1" << endl;
}

int main()
{
  cout << "main1" << endl;
  atexit(fun1);
  cout << "main2" << endl;
  return 0;
}
