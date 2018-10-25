#include <iostream>
int main()
{
  int v1 = 0, v2 = 0;
  std::cout << "Please input the value of v1: ";
  std::cin >> v1;
  std::cout << "Please input the value of v2: ";
  std::cin >> v2;
  std::cout << v1;
  std::cout << "*";
  std::cout << v2;
  std::cout << "=";
  std::cout << v1*v2 << std::endl;
  return 0;
}
