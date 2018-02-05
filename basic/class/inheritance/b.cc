#include <iostream>
using namespace std;

class Animal
{
  public:
    Animal(int height, int weight) {
      cout << "animal constructor" << endl;
    }
};

class Fish : public Animal
{
  public:
    Fish():Animal(1,2) {
      cout << "fish constructor" << endl;
    }
};

int main()
{
  Fish fh;
  return 0;
}
