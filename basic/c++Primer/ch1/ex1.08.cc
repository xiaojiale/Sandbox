#include <iostream>
int main()
{
  std::cout << "/*"; 
  std::cout << "*/"; 
  std::cout << /* "*/" */;    // 句末缺少一个双引号
  std::cout << /* "*/" /* "/*" */;
  return 0;
}
