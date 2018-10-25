#include <iostream>
extern int count;

void write_extern()
{
  std::cout << "count = " << count << std::endl;
}
