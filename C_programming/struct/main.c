#include <stdlib.h>
#include <stdio.h>

void my_strcpy(char copy[], char input[]) //coded version of strcpy, copies string into designated output char array
{
    int i;
    for(i = 0; input[i] != '\0';i++)
    {
        copy[i] = input[i];
    }
    copy[i] = '\0';
}

int my_strcmp(char comp[], char og[]) //coded version of strcmp, returns 0 if matched or difference in ASCII if unmatched
{
    int i = 0;
    while(comp[i] != '\0' && og[i] != '\0' && comp[i]==og[i])
        i++;
 return og[i]-comp[i];
}

void add_matrices(int n_rows, int n_columns)
{
    int m1[n_rows][n_columns];
    int m2[n_rows][n_columns];
    int sum[n_rows][n_columns];

    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            printf("Number at row %d, column %d of matrix 1 is: ",i,j);
            scanf(" %d", &m1[i][j]);
        }
    }
    
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            printf("Number at row %d, column %d of matrix 2 is: ",i,j);
            scanf(" %d", &m2[i][j]);
        }
    }
    printf("First matrix:\n");
    for(int i = 0;i<n_rows;i++)
    {
        printf("[ ");
        for(int j = 0;j<n_columns;j++)
        {
            int temp = m1[i][j];
            printf(" %d", m1[i][j]);
        }
        printf(" ]\n");
    }
    printf("Second matrix:\n");
    for(int i = 0;i<n_rows;i++)
    {
        printf("[ ");
        for(int j = 0;j<n_columns;j++)
        {
            printf(" %d", m2[i][j]);
        }
        printf(" ]\n");
    }
    for(int i = 0;i<n_rows;i++)
    {
        for(int j = 0;j<n_columns;j++)
        {
            sum[i][j] = m1[i][j]+m2[i][j];
        }
    }
    printf("Sum of matrices:\n");
    for(int i = 0;i<n_rows;i++)
    {
        printf("[ ");
        for(int j = 0;j<n_columns;j++)
        {
            int temp = m1[i][j];
            printf(" %d", sum[i][j]);
        }
        printf(" ]\n");
    }
}

struct user
{
  char name[24];
  int id;
  int link[50];
  int numLink;
};

struct user create(ID)
{
  char name[24];
  struct user newuser;
  newuser.id = ID;
  newuser.numLink = 0;
  printf("What is your name? ");
  scanf(" %s", name);
  my_strcpy(newuser.name, name);
  return newuser;
}

void addRel(struct user records[], int id1, int id2)
{
  if(records[id1].numLink<51 && records[id2].numLink<51)
  {
    records[id2].link[records[id2].numLink] = records[id1].id;
    records[id1].link[records[id1].numLink] = records[id2].id;
    printf("%s was added as %s's friend.\n", records[id2].name,records[id1].name);
    records[id1].numLink++;
    records[id2].numLink++;
  }
  else
  {
    printf("One of the users has maxed out their friend list.");
  }
}

int checkID(struct user records[], char n1[], int count)
{
  int id = -1;
  int check;
  for(int i = 0; i < count + 1; i++)
  {
    check = my_strcmp(records[i].name, n1);
    if(check == 0)
    {
      id = i;
    }
  }
  return id;
}

void printRecords(struct user records[], int count)
{
  printf("Records:\n");
  for(int i=0;i<count;i++)
  {
    printf("ID%d: %s\nNetwork:\n",records[i].id,records[i].name);
    for(int j = 0;j<records[i].numLink;j++)
    {
      printf("%s\n", records[records[i].link[j]].name);
    }
  }
}

int main(void)
{
    int choice, smenu, rows, columns, count;
    struct user records[50];
    char fname[20],sname[20];
    count = 0;
    while(choice != 3)
    {
      printf("Pick an option:\n1 - add two matrices\n2 - access social network\n3 - exit\n\n");
      scanf(" %d", &choice);
      switch(choice)
      {
        case 1:
          printf("How many rows?  Your answer: ");
          scanf(" %d", &rows);
          printf("How many columns?  Your answer: ");
          scanf(" %d", &columns);
          add_matrices(rows,columns);
          break;
        case 2:
          while(smenu != 4)
          {
            printf("\n\nSocial Networks Menu:\n1 - add new user\n2 - add a friend\n3 - see user records\n4 - exit to main menu\n\n");
            scanf(" %d", &smenu);
            switch(smenu)
            {
              case 1:
                printf("Create a new user:\n");
                records[count] = create(count);
                count++;
                break;
              case 2:
                printf("Print your name: ");
                scanf(" %s", fname);
                printf("Print the person's name: ");
                scanf(" %s", sname); 
                int id1 = checkID(records, fname, count);
                int id2 = checkID(records, sname, count);
                if(id1 != -1 && id2 != -1)
                {
                  addRel(records, id1, id2);
                }
                else
                {
                  printf("The user(s) were not found.");
                }
                break;
              case 3:
                printRecords(records,count);
                break;
              case 4:
                break;
              default:
                printf("\nThe option was not recognized.\n");
            }
          }
          break;
        case 3:
          break;
        default:
          printf("\nThe option was not recognized.\n");
      }
    }
}