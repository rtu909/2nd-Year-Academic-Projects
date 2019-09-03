#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genmatrix ( int n , double A[]) 
{
  int i;
  srand(time(NULL));

  for (i = 0; i <= n*n; i++){
    A[i] = rand() % 20;
  }
}

void genvector ( int n , double b[]) 
{
  int i;
  srand(time(0));

  for (i = 0; i <= n; i++){
    b[i] = rand() % 20;
  }
}

