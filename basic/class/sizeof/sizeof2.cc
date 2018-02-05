#include <iostream>
#pragma pack(4)
using namespace std;

typedef struct aa
{
  int id;           // 4  0-3
  double weight;    // 8  8-15
  float height;     // 4  16-19
}AA;

typedef struct bb
{
  char name[2];     // 2  0-1
  int id;           // 4  4-7
  double score;     // 8  8-15
  short grade;      // 2  16-17
  AA a;             // 24 24-47
}BB;

int main()
{
  cout << sizeof(float) << endl;    // 4
  cout << sizeof(short) << endl;    // 2
  cout << sizeof(double) << endl;   // 8
  cout << sizeof(AA) << endl;       // 24
  cout << sizeof(BB) << endl;       // 48
  return 0;
}
