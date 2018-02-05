#include <iostream>

class A
{
  public:
    A(int x, int y) :
      i(x),
      j(y)
    {}
    A(){}

  private:
    int i;
    int j;
};

class B : public A
{
  public:
    B()
    {
      std::cout << "int B" << std::endl;
    }
};

int main()
{
  B b = B();
}
