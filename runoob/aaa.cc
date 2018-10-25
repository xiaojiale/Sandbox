#include <iostream>
using namespace std;
int main()
{
  int a = 5;
  int b = a++;
  cout << a*10 + b << endl;
  a = 5;
  int c = a--;
  cout << a*10 + c << endl;
  a = 5;
  int d = ++a;
  cout << a*10 + d << endl;
  a = 5;
  int f = --a;
  cout << a*10 + f << endl;
  return 0;
}
