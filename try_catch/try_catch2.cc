#include <iostream>
#include <exception>
using namespace std;

class myException: public exception
{
  const char* what() const noexcept override
  {
    return "My exception happened";
  }
};

int main()
{
  myException myex;
  try {
    throw myex;
  }
  catch(exception& e) {
    cout << e.what() << endl;
  }
  return 0;
}
