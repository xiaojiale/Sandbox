#include <iostream>
using namespace std;

class A {
  public:
    int a;
};

class B : virtual public A {
  public:
    char b;
};

class C : virtual public A {
};

class D : public B, public C {
};

int main()
{
  cout << sizeof(A) << endl;  // 4
  cout << sizeof(B) << endl;  // 8(4字节对齐) + 8 = 16
  cout << sizeof(C) << endl;  // 8(4字节对齐) + 8 = 16
  cout << sizeof(D) << endl;  // 8(A的副本,4字节对齐)+8(B的虚表)+8(B的变量,1字节对齐)+8(C的虚表) = 32
  return 0;
}
