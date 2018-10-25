#include <iostream>
using namespace std;

int add(int c)
{
  int a = 0;
  c&&(a=add(c-1));
  cout << c+a << endl;
  return c+a;
}

void func1()
{
  int val = 2;
  if(val) {
    cout << "if(val)" << endl;
  }
  if(val == true) {
    cout << "if(val==true)" << endl;
  }
}

void func2()
{
  int i,j,k;
  k = 2;
  if(i<j<k) {
    cout << "no matter the relation of a & b" << endl;
  }
}

void func3()
{
  int i,j;
  i = 9;
  j = 5;
  cout << i%j << endl << i/j << endl;
  j = -5;
  cout << i%j << endl << i/j << endl;
  i = -9;
  cout << i%j << endl << i/j << endl;
}

int main()
{
  func3();
//  func2();
//  func1();
//  add(10);
}
