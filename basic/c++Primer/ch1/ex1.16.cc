#include <iostream>
int main()
{
  int value = 0, sum = 0;
  while(std::cin >> value)
    sum += value;
  std::cout << "sum is " << sum << std::endl;
  return 0;
}
