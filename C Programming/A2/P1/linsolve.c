#include <stdio.h>
#include <math.h>

int linsolve ( int n, double A [], double b [], double x []){
   int i, j, k;
   double a_ik, sum;

   /*Gaussian elimination taken from http://www.math-cs.gordon.edu/courses/ma342/handouts/gauss.pdf*/
   /*reference to https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html for NaN and infinity*/
   /*for a matrix A[i][j] a one dimensional matrix would be indexed by calling A[i*n + j]*/


   a_ik = 0;
    for(k=0; k < n - 1; k++) 
    {
        for(i= k + 1; i < n; i++)
        {
          a_ik=A[(i*n) + k]/A[(k*n) + k];
          for(j= k + 1; j < n; j++)
          {
              A[(i*n) + j]=A[(i*n) + j]-a_ik*A[(k*n) + j];
          }
            
        }
    }

    printf("\nReduced Matrix: \n");
     for ( i = 0; i < n; i++ ) {
      for ( j = 0; j < n; j++ ) {
         printf("a[%d][%d] = %lf\n", i,j, A[(i*n) + j] );
      }
   }

   for (k = 0; k < n-1; k++){
     for (i = k+1; i < n; i++){
       b[i] = b[i] - a_ik*b[k];
     }
   }

   printf("\nb vector: \n");
   for (i = 0; i < n; i++){
     printf("b[%d] = %lf \n", i, b[i]);
   }


   for (i = n-1; i >= 0; i--)
   {
     sum = b[i];
     for (j = i + 1; j < n; j++)
     {
       sum = sum - A[(i*n) + j]*x[j];
     }
     x[i] = sum/A[(i*n) + i];
   }

   printf("\nx vector: \n");
   for (i = 0; i < n; i++){
     printf("x[%d] = %lf \n", i, x[i]);
   }

   for (i = 0; i < n; i++){
     if ((x[i] != x[i]) || (x[i] == INFINITY) || (x[i] == -INFINITY))
     {
       printf("Returning 0");
       return 0;
     }
     else{
       printf("Returning 1");
       return 1;
     }
   }
}
