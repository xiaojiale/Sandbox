#include <iostream>
using namespace std;
class A
{
  public:
    A(int val) : i(val) {
      cout << "A::A()" << endl;
    }

    ~A() {
      cout << "A::~A()" << endl;
    }

    void print() {
      cout << "A::print()" << endl;
    }

    void print(int i) {
      cout << "now i =" << i << endl;
      print();
    }

    void set(int val) {
      i = val;
      cout << "set(" << i << ")" << endl;
    }

  private:
    int i;
};

class B : public A
{
  public:
    B(int a):
      A(15),
      t(a) {
      cout << "B::B()" << endl;
    }

    ~B() {
      cout << "B::~B()" << endl;
    }

    void print() {
      cout << "B::print()" << endl;
    }

    void f() {
      cout << t << endl;
      set(20);
//      i = 10;   // public继承，不能直接修改基类的private成员
      print();
    }
  private:
    int t;
};

int main()
{
  B b(1000);
  b.f();
  b.print();
  b.set(10);
  cout << "test beginning" << endl;
  b.print();  // 派生类和基类同时定义了一个函数名及参数列表均一样的函数时，基类的同名函数被隐藏
  b.A::print(); // 如需调用基类被隐藏的同名函数，需要用范围解析运算符::界定
  b.f();
  b.A::print(200);
  cout << "test over" << endl;
  return 0;
}
