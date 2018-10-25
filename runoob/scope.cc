#include <iostream>
using namespace std;

int g = 0;
int func1(int a, int b);

void func2()
{
  cout << "Current value: " << g << endl;
}
int main()
{
  func2();
  func1(10,20);
  func2();
  return 0;
}
int func1(int a, int b)
{
  g = a + b;
  return 0;
}
