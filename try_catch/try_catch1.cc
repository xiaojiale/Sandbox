#include <iostream>
#include <exception>
using namespace std;
int main()
{
  try {
    throw 1;
    throw "error";
  }
  catch(const char* str) {
    cout << str << endl;
  }
  catch(int i) {
    cout << i << endl;
  }
}
