#pragma pack(8)
#include <iostream>
using namespace std;

class CommonBase
{
  char a;
  int co;
};

class Base1 : virtual public CommonBase
{
  public:
    virtual void print1(){}
    virtual void print2(){}
  private:
    int b1;
    char b3;
    long b2;
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
  cout << sizeof(CommonBase) << endl;  // 5   8(5)   4   
  cout << sizeof(Base1) << endl;       // 25  32 8(5)+8(4+1)+8+8
  cout << sizeof(Base2) << endl;       // 17  24 8(5)+8(4)+8
  cout << sizeof(Derived) << endl;     // 41  8(5)+8(4+1)+8+8+8(4)+0(4)+8
//  8(5)+4+8+4+8 52 32+24-8+4 40 16+16-4+4+8
  return 0;
}
