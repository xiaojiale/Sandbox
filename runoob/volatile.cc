#include <iostream>
using namespace std;
volatile bool isNext = false;

void A() {
  cout << "task A" << endl;
  isNext = true;
}

void B() {
  if(isNext) {
    cout << "task B" << endl;
  }
}

int main()
{
  for (int i=0; i<10; i++)
  {
    A();
    B();
  }
  return 0;
}
