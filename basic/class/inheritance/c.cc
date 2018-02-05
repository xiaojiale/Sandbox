#include <iostream>
using namespace std;

class Base1 {
  public:
    Base1(int a)
      : m_a(a)
    {}

  protected:
    int m_a;
};

class Base2 {
  public:
    Base2();
    Base2(int b, int c)
      : m_b(b),
        m_c(c)
    {}

  protected:
    int m_b;
    int m_c;
};

class Intermediate1 : public Base1, virtual public Base2
{
  public:
    Intermediate1(int a, int b, int c)
      : Base1(a),
        Base2(b, c)
    {}
};

class Intermediate2 : public Intermediate1
{
  public:
    Intermediate2(int a, int b, int c)
      : Intermediate1(a, b, c)
    {}
};

class Intermediate3 : virtual public Base2
{
  public:
    Intermediate3(int b, int c)
      : Base2(b, c)
    {}
};

class Final : public Intermediate2, public Intermediate3
{
  public:
    Final(int a, int b, int c)
      : Base2(b, c),
        Intermediate2(a, b, c),
        Intermediate3(b, c)
    {}

    void Print() {
      cout << m_a << ", " << m_b << ", " << m_c << endl;
    }
};

int main()
{
  Final obj(1, 2, 3);
  obj.Print();
  return 0;
}
