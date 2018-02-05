#include <iostream>
using namespace std;

class A {
  public:
    int a;
};

//class B : public A {
class B : virtual public A {
  public:
//    int b;    // 即使class B内没有变量,由于字节对齐,sizeof(B) 也会为16,但B没有变量时,C会变成直接继承A,sizeof(C) = 4(A副本)+8(虚表指针)+(自己变量)
};

//class C : public B {
class C : virtual public B {
  public:
  char c;
};

int main() {
  cout << sizeof(void*) << endl;  // sizeof(point) = 8
  cout << sizeof(A) << endl;      // sizeof(A) = 4
  cout << sizeof(B) << endl;      // 直接继承时，sizeof(B) = 4(A副本)+4(自己变量) = 8，虚继承时，sizeof(B) = 4(A副本)+8(虚表指针)+4(自己变量) = 16
  cout << sizeof(C) << endl;      // 直接继承时，sizeof(C) = sizeof(B)，虚继承时，sizeof(C) = 16(B副本) + 8(虚表指针) = 24
}

