#include <iostream>
using namespace std;

class CommonBase
{
  int co;
};

class Base1 : virtual public CommonBase
{
  public:
    virtual void print1(){}
    virtual void print2(){}
  private:
    int b1;
};

class Base2 : virtual public CommonBase
{
  public:
    virtual void dump1(){}
    virtual void dump2(){}
  private:
    int b2;
};

class Derived : public Base1, public Base2
{
  public:
    void print1(){}
    void print2(){}
  private:
    int d;
};

int main()
{
  cout << sizeof(CommonBase) << endl;  // 4
  cout << sizeof(Base1) << endl;       // 16
  cout << sizeof(Base2) << endl;       // 16 1+1+1+8(没有继承时，存在多个虚函数也只需加上一个虚指针)
  cout << sizeof(Derived) << endl;     // 24 16(C副本)+8(4+1,D本身)
  return 0;
}
