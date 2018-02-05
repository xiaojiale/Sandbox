#include <iostream>
#include <cstring>
using namespace std;

char* strupr(char *s);
char* strlwr(char *s);

int main()
{
  char a[10] = " Hello.";
  int n;
  n = strlen(a);
  cout << n << endl;

  char b[10];
  char c[15] = "Hello.";
  strcpy(b, a);
  strupr(b);
  int m = strcmp(a, c);
  strlwr(a);
  cout << m << endl;
  strcat(c, a);
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  return 0;
}

char* strupr(char *s)
{
  char *t = s;
  while(*t)
  {
    if(*t >= 'a' && *t <= 'z')
    {
      *t += 'A' - 'a';
    }
    t++;
  }
  return s;
}

char* strlwr(char *s)
{
  char *t = s;
  while(*t)
  {
    if(*t >= 'A' && *t <= 'Z')
    {
      *t -= 'A' - 'a';
    }
    t++;
  }
  return s;
}
