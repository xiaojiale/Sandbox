#include <iostream>
using namespace std;

#if 0
enum days{one, two, three}day;
enum time{first, second, third, forth, fifth};
#endif
enum rank{first, second, third};
#if 0
int main()
{
  day = two;
  switch(day) {
    case one:
      cout << "one" << endl;
      break;
    case two:
      cout << "two" << endl;
      break;
    default:
      cout << "three" << endl;
      break;
  }
  return 0;
}
#endif 
#if 0
int main()
{
  enum time a = fifth;
  if (a == fifth) {
    cout << "Succeed!" << endl;
    cout << a << endl;
  }
  return 0;
}
#endif

int main()
{
  int nRank = 1;
  switch(nRank)
  {
    case first:
      cout << "No.1";
      break;
    case second:
      cout << "No.2";
      break;
    case third:
      cout << "No.3";
      break;
    default:
      break;
  }
  return 0;
}
