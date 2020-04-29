#include <stdio.h>

int main(void) {
  //3) Write a program that calculates the least common multiple of two numbers
  int a,b,LCM;
 printf("Enter a number: ");
 scanf("%d", &a);
 printf("Enter another number: ");
 scanf("%d", &b);
 for(int i=a*b;i>0;i--)
 {
   if(i%a == 0 && i%b == 0)
   {
     LCM = i;
   }
 }
 printf("%d",LCM);
  return 0;
}