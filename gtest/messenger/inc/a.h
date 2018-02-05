#include <iostream>

class A
{
  public:
    void print(int x){
      std::cout << x << std::endl;
    }
    A();
    virtual ~A();

  private:
    int x;
};

