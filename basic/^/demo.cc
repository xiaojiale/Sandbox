#include <iostream>
using namespace std;
#define _ 0000
#define r 0010
#define w 0100
#define x 0001

int main()
{
  unsigned int num[3];
  char pri[9];
  int temp[3];
  int i, j;
  int shift = 0;
  for(i=0; i<3; i++) {
    cin >> num[i];
  }
  for(i=0; i<9; i++) {
    cin >> pri[i];
  }
  for(j=0; j<3; j++) {
    for(i=0+shift; i<3+shift; i++) {
      temp[j] |= pri[i];
    }
    cout << "temp[" << j << "] = " << temp[j] << endl;
    shift += 3;
  }
  for(j=0; j<3; j++) {
    if(temp[j] != num[j]) {
      cout << "No" <<endl;
      break;
    }
  }
  if(j ==3) {
    cout << "Yes" << endl;
  }

  return 0;
}
