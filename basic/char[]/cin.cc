#include <iostream>
using namespace std;

int main()
{
//  char a[10];
  char a[] = "Hello";
  cin >> a;
  a[13] = 'a';
  cout << a;
  return 0;
}
