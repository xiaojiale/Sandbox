#include <iostream>

int main()
{
  int a = 10;
  int &b = a;

  auto c = b;
  auto &d = b;

  std::cout << a << b << c << d  << std::endl; 

  c = 100;

  std::cout << a << b << c << d  << std::endl; 

  d = 100;
  std::cout << a << b << c << d  << std::endl; 
  return 0;
}
