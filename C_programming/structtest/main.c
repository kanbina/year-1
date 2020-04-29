#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct user
{
  char name[24];
  int id;
  int link[50];
  int numLink;
};

int my_strcmp(char comp[], char og[])
{
    int i = 0;
    while(comp[i] != '\0' && og[i] != '\0' && comp[i]==og[i])
        i++;
    if(comp[i]<og[i])
        return -1;
    else if(comp[i]>og[i])
        return 1;
    else if(comp[i] == og[i])
        return 0;
}

int checkID(struct user records[], char n1[], int count)
{
  int id = -1;
  int check;
  for(int i = count; i>= 0; i--)
  {
    check = my_strcmp(records[i].name, n1);
    if(check == 0)
    {
      id = i;
    }
  }
  return id;
}

int main(void)
{
  struct user records[50];
  struct user a;
  struct user b;
  char name1[] = "eun";
  char name2[] = "yo";
  int count = 1;
  strcpy(a.name,"yo");
  strcpy(b.name,"eun");
  a.id = 0;
  b.id = 1;
  records[0] = a;
  records[1] = b;
  int check = checkID(records, name2, count);
  printf("%d\n\ncheckingrecords:%d%s", check, records[0].id, records[0].name);
  /*records[id1].numLink++;
  records[id2].numLink++;
  my_strcpy(records[id2].link[records[id2].numLink],records[id1].name);
  my_strcpy(records[id1].link[records[id1].numLink],records[id2].name);
  printf("%s was added as %s's friend.\n", sname,fname);*/

}