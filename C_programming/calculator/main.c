#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("Enter the calculator: y/n?\n");
    char enter;
    int choice;
    scanf(" %c",&enter);
    while (enter == 'y') {
        enter = ' ';
        char s[5][60] = {"Type the number of an option:\n","\n1. Average",
            "\n2. Calculate pi to the nth iteration using Gregory-Leibniz",
            "\n3: Square root"
            "\n4: Exit\n"};
        printf("%s%s%s%s",s[1], s[2],s[3],s[4],s[5]);
        scanf(" %d",&choice);
        switch((int)choice) {
            char exit;
            case 1:
                printf("Please enter up to 20 numbers:\n");
                int i = 0;
                double inputs[20];
                while(exit != 'n'){
                    inputs[i] = scanf(" %f", &inputs[i]);
                    i++;
                    printf("Another number? y/n\n");
                    scanf(" %c",&exit);
                }
                printf("%f", average(inputs));
                break;
        }
    }
}

double average (double* inputArr) {
  double sum = 0;
  double length = sizeof(inputArr);
  for(int i = 0;i<sizeof(inputArr);i++) {
     sum += inputArr[i];
  }
  double av = sum/length;
  return av;
}