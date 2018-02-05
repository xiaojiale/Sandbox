#include <iostream>
using namespace std;

class A
{
};

class B
{
  char ch;
  virtual void func0(){}
};

class C
{
  char ch1;
  char ch2;
  char ch3;
  virtual void func(){}
  virtual void func1(){}
  void func5(){}
};

class D: public A, public C
{
  int d;
  char ch4;
  virtual void func(){}
  virtual void func1(){}
  void func6(){}
};

class E: public B, public C
{
  int e;
  char f;
  virtual void func0(){}
  virtual void func1(){}
};

int main()
{
  cout << sizeof(A) << endl;  // 1
  cout << sizeof(B) << endl;  // 16
  cout << sizeof(C) << endl;  // 16 1+1+1+8(没有继承时，存在多个虚函数也只需加上一个虚指针)
  cout << sizeof(D) << endl;  // 24 16(C副本)+8(4+1,D本身)
  cout << sizeof(E) << endl;  // 40 16+16+8(4+1,E本身)
  return 0;
}
