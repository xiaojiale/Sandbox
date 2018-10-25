#include <iostream>
using namespace std;

void fn();
int main()
{
  fn();
  fn();
  fn();
}
void fn()
{
  static int n = 10;
  cout << n << endl;
  n++;
}
