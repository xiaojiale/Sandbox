#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  int a = 55;
  double b = 12.12;
  string str = "";

  ostringstream oss;
  oss << a << endl << b;
  str = oss.str();
  cout << "begin" << endl;
  cout << str << endl;
  return 0;
}
