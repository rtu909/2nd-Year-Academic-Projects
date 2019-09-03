#include <stdio.h>
#include <math.h>

int main(void) {

  double error, xi, a;

  printf("Enter a: ");
  scanf("%lf", &a);

  xi = 2/(1 + a);
  while (1){
    xi = xi*(1.5 - 0.5*a*xi*xi);
    error = fabs((xi - (1/ sqrt(a)))*(sqrt(a)));
    printf("  %.15e %.2e", xi, error);
    printf("\n");
    if (error <= 10E-13){
      break;
    }

  }

  return 0;
}
