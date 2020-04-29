/*
 ============================================================================
 Name        : daysInMonthSwitch.c
 Author      : Yolanne YR Lee
 Description : Outputs the number of days in inputted month of an inputted year
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
//setting up variables
int monthIn, yearIn;
int year;
int month = 30;
int leap = 0;
char monthName[12][10] = {
"January",
"February",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December",
};
printf("Enter a year: "); //takes user input for year
scanf("%d", &yearIn);
printf("Enter a month: "); //takes user input for month
scanf("%d", &monthIn);
if(yearIn%4 == 0 && yearIn%100 != 0 || yearIn%400 == 0) 
  leap = 1;
switch(monthIn)
{
  case 2:
    switch(leap)
    {
    case 1:
    month = 29;
    break;
    case 0:
    month = 28;
    break;
    }
  break;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    month = 31;
    break;
}
printf("\nThe number of days in %s, %d is %d.", monthName[monthIn-1],yearIn,month);
}