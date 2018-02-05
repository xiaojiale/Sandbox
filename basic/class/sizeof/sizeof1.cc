#include <iostream>
using namespace std;

class Base
{
  public:
    Base();                 // 成员函数,不计入
    virtual ~Base();        // 虚函数表,8
    void set_num(int num)   // 成员函数,不计入sizeof
    {
      m_a = num;
    }
  private:
    int m_a;                // 4,字节对齐,计入8
    char *p;                // 8
};

class Derive:public Base
{
  public:
    Derive();        // 成员函数,不计入
    ~Derive();       // 成员函数,非虚函数表,不计入
  private:
    static int st;   // 静态成员,非实例独占,不计入
    int d;           // 4,字节对齐,计入8
    char *p;         // 8
    char c;          // 1,字节对齐,计入8
};

int main()
{
  cout << sizeof(int) << sizeof(char*) << endl;
  cout << sizeof(Base) << endl;   // 8(4要字节对齐)+8+8=24
  cout << sizeof(Derive) << endl;   // 24+8(4要字节对齐)+8+8(1要字节对齐)=48

  return 0;
}
