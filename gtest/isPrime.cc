#include <iostream>

bool IsPrime(int n) {
  if (n <= 1) return false;
  if (n % 2 == 0) return n == 2;
  for (int i = 3; ; i++) {
    if (i > n/i) break;
    if (n % i == 0) return false;
  }
  return true;
}

int main(int argc, char* argv[])
{
  int n;
  std::string result;
//  std::cin >> n;
  result = IsPrime(*argv[0]);
  std::cout << argc;
  std::cout << *argv[0];
  return 0;
}
