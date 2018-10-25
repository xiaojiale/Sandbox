#include <iostream>
int main()
{
  std::cout << "ex1.9:" << std::endl;
  int sum = 0;
  for (int i = 50; i <= 100; ++i)
    sum += i;
  std::cout << sum << std::endl;

  std::cout << "ex1.10: " << std::endl;
  for (int j = 10; j > 0; --j)
    std::cout << j << std::endl;

  std::cout << "ex1.11: " << std::endl;
  int v1 = 0, v2 = 0, from = 0, end = 0;
  std::cout << "Please input the value of v1 and v2: ";
  std::cin >> v1 >> v2;

  if (v1 >= v2) {
    from = v2;
    end = v1;
  } else {
    from = v1;
    end = v2;
  }

  for (;from <= end; ++from)
    std::cout << from << std::endl;
  return 0;
}
