#include <iostream>
using namespace std;
#define N 1000010
int a[N];

void func1()
{
  int i, s = 0;
  for(i = 1; i < 1001; i++)
    s = i^s;
  cout << s << endl;
}

void func2()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int x = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      x ^= a[i];
    }
    int num1 = 0, num2 =0;
    int tmp = 1;
    while(!(tmp & x))
      tmp <<= 1;
//    cout << tmp << endl;
    for(int i = 1; i <= n; i++) {
      if(tmp & a[i])
        num1 ^= a[i];
      else
        num2 ^= a[i];
    }
    cout << min(num1,num2) << max(num1,num2) << endl;
  }
}

void func3()
{
  long a = 123;
  int b = 1;
  cout << (a&b) << endl;
}

void func4()
{
  int i = -5;
  unsigned int ii = 1;
  cout << (unsigned int)i << endl;
  cout << (i>ii) << endl;
  short j = -5;
  unsigned short jj = 1;
  cout << (unsigned short)j << endl;
  cout << (unsigned int)j << endl;
  cout << (unsigned int)jj << endl;
  cout << (j>jj) << endl;
}

int main()
{
  func4();
}
