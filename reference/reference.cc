#include <iostream>
using namespace std;

int fun1(int& a)
{
  a = 1;
  return 0;
}

int fun2(int& a)
{
  a = 2;
  return 0;
}

int main()
{
  int a;
  a = 0;
  fun1(a);
  cout << a << endl;
  fun2(a);
  cout << a << endl;
  return 0;
}
