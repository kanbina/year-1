#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a;
  printf("Input a number: ");
  scanf("%d", &a);
  for (int i=-(a-1); i<a; i++)
  {
    for(int j=0;j<abs(i);j++)
    {
      printf(" ");
    }
    for(int h=abs(i)*2;h<(a*2-1);h++)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}