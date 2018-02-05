#include <iostream>
using namespace std;

class A{
  public:
    A(int i){
      cout << i << "constructor of A" << endl;
    }
};

class B{
  public:
    B(int i):a(i){
      cout << i << "constructor of B" << endl;
    }
  private:
//    A a = A(5);
    A a;
};

int main()
{
  B b = B(2);
}
