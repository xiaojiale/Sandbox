#include <iostream>
using namespace std;
#define PRINT cout << c << endl

void func1()
{
  unsigned int a = 60;    //  0011 1100
  unsigned int b = 13;    //  0000 1101
  auto c = 0;

  c = a & b;              //  0000 1100
  PRINT;      //  12

  c = a | b;              //  0011 1101
  PRINT;      //  61

  c = a ^ b;              //  0011 0001
  PRINT;      //  49

  c = ~a;                 //  1100 0011
  PRINT;      //  -61,注意负数的补码转原码计算,结果不是-67

  c = a << 2;             //  1111 0000
  PRINT;      //  240,a是unsigned无符号整型正数,左右移后依然是无符号整型正数,结果不是-112

  c = a >> 2;             //  0000 1111
  PRINT;      //  15
}

void func2()
{
  int a = 21;
  int c;

  c = a;
  PRINT;

  c += a;
  PRINT;

  c -= a;
  PRINT;

  c *= a;
  PRINT;

  c /= a;
  PRINT;

  c = 200;
  
  c %= a;
  PRINT;

  c <<= 2;
  PRINT;

  c >>= 2;
  PRINT;

  c &= 2;
  PRINT;

  c ^= 2;
  PRINT;

  c |= 2;
  PRINT;
}
int main()
{
  func1();
  cout << "============" << endl;
  func2();

  return 0;
}
