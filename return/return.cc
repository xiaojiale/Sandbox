#include <iostream>
using namespace std;
int foo()
{
  throw 0;
  return 0;
}
int main()
{
  try {
    foo();
  }
  catch(int) {
    cout << "this is a accident." << endl;
  }
  cout << "after the accident." << endl;
  return 0;
}
