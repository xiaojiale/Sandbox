#include <iostream>
#include <stdlib.h>

using namespace std;

void outc(char c)
{
  unsigned char k = 0x80;
  for(int i=0; i<8; i++, k>>=1) {
    if(c&k) {
      cout << 1;
    }else {
      cout << 0;
    }
  }
  cout << " ";
}

int main()
{
  char str[] = "DATA";
  for(int i=0; str[i]; i++) {
    outc(str[i]);
  }
  cout << endl;
  return 0;
}
