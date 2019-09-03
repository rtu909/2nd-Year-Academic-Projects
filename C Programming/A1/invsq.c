#include <stdio.h>
#include <math.h>

int main(void) {

  int  n, i;
  double x0, error, xi, a;

  printf("Enter a, x0 and n: ");
  scanf("%lf%lf%d", &a, &x0, &n);

  xi = x0;
  i = 0;
  while (i < n){
    i++;
    xi = xi*(1.5 - 0.5*a*xi*xi);
    error = fabs((xi - (1/ sqrt(a)))/(1/(sqrt(a))));
    printf("%d %.15e %.2e", i, xi, error);
    printf("\n");

  }


  return 0;
}
