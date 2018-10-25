#include <iostream>
using namespace std;

int func_call(string text) {
  cout << text << endl;
  return 5;
}

void func_pointer(int (*fp)(string)) {
  cout << fp("func_pointer") << endl;
}

int main()
{
  int (*fp)(string);
  fp = func_call;
  cout << "==== begin ====" << endl;
  func_pointer(fp);
  cout << "====  end  ====" << endl;
}
