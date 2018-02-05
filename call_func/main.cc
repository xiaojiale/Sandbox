#include "getHuntPathImpl.h"

int main(int argc, char* argv[])
{
  std::string huntPath;
  GetHuntPathImpl obj;
  obj.printHuntPath(huntPath);
  std::cout << "Print HuntPath successfully." << std::endl;
  return 0;
}
