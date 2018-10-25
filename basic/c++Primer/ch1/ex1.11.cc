#include <iostream>
int main()
{
  int v1 = 0, v2 = 0, from = 0, end = 0;
  std::cout << "Please input value of v1 and v2:" << std::endl;
  std::cin >> v1 >> v2;
  
  if (v1 > v2) {
    from = v2;
    end = v1;
  } else {
    from = v1;
    end = v2;
  }

  while (from <= end) {
    std::cout << from << std::endl;
    ++from;
  }

  return 0;
}
