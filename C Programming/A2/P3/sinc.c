#include <stdio.h>
#include <math.h>

double sinc (double x ){
  if (x != 0){
    return sin(M_PI*x)/(M_PI*x);
  } 
  else if (x == 0){
    return 1;
  }
}

double comph (int N ){
  return (M_PI) / sqrt(2* N);
}

double comprho (double x , double a , double b ){
  return (x - a)/(b - x);
}

double complambda (double x, double h, double a, double b, int j){
  return sinc(log(comprho(x, a, b)) - (j*h))/h;
}

void wj (double x , double a , double b , int N , double *w ){
  int i, i2, j, j_counter;
  double w_j, sum_N, sum_Nfinal;

  sum_N = 0;

  for (i = ((-1) * N) + 1; i <= N; i++){
    sum_N = sum_N + (complambda(x, comph(N), a, b, i))/(1 + exp(i * comph(N)));
  }

  w[0] = (1 + exp(-1 * N * comph(N))) * ((1 / (1 + comprho(x, a, b))) - sum_N);

  j_counter = 0;

  for (j = ((-1) * N) + 1; j <= N - 1; j++){
    j_counter++;
      w[j_counter] = complambda(x, comph(N), a, b, j);
    }
  

  sum_Nfinal = 0;

  for (i2 = ((-1) * N); i2 <= N - 1; i2++){
    sum_Nfinal = sum_Nfinal + ((exp(i2 * comph(N)))*(complambda(x, comph(N), a, b, i2)))/(1 + exp(i2 * comph(N)));
  }

  w[N] = (1 + exp(-1 * N * comph(N))) * (((comprho(x, a, b))/(1 + comprho(x, a, b))) - sum_Nfinal);

}


