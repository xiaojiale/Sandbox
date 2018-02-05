#include <iostream>
using namespace std;

int main()
{
  char a[] = "Hello";
  cout << a[2] << endl;
  a[0] = 'X';
  cout << a;
  return 0;
}
