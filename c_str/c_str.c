#include <stdio.h>
#include <string.h>
int main(void)
{
  char buf[] = "hello my world";
  char* temp = strtok(buf, " ");
  while(temp) {
    printf("%s_",temp);
    temp = strtok(NULL, " ");
  }
  printf("\n");
  return 0;
}
