#include <stdio.h>

void add(int *a, int *b, int *c)
{
  *c = *a+*b;
}

 void add_matrices(int *m1[], int *m2[], int *destination_matrix[], int n_rows, int n_columns)
 {
   for(int i = 0;i<n_rows;i++)
    {
        for(int j = 0;j<n_columns;j++)
        {
            destination_matrix[i][j] = m1[i][j]+m2[i][j];
        }
    }
 }

int main(void) {
  int a,b,c,rows,columns;
  scanf(" %d", &a);
  scanf(" %d", &b);
  scanf(" %d", &c);
  printf("%d %d %d\n", a,b,c);
  add(&a,&b,&c);
  printf("%d %d %d\n\nType rows then columns:", a,b,c);

  scanf(" %d\n%d", &rows,&columns);

  int m1[rows][columns];
  int m2[rows][columns];
  int sum[rows][columns];

  for(int i = 0; i < rows; i++)
  {
      for(int j = 0; j < columns; j++)
      {
          printf("Number at row %d, column %d of matrix 1 is: ",i,j);
          scanf(" %d", &m1[i][j]);
      }
  }
  
  for(int i = 0; i < rows; i++)
  {
      for(int j = 0; j < columns; j++)
      {
          printf("Number at row %d, column %d of matrix 2 is: ",i,j);
          scanf(" %d", &m2[i][j]);
      }
  }
  
  add_matrices(m1, m2, sum, rows, columns);
  printf("Sum of matrices:\n");
  for(int i = 0;i<rows;i++)
  {
      printf("[ ");
      for(int j = 0;j<columns;j++)
      {
          int temp = m1[i][j];
          printf(" %d", sum[i][j]);
      }
      printf(" ]\n");
  }
  return 0;
}