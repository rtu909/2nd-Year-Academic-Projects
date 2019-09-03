#include <stdio.h>

int main(void) {

  int n, i, fib_term1, fib_term2, counter2, counter3, counter5, counter6, counter10, counter15, counter_none;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  i = 1;
  fib_term1 = 0;
  fib_term2 = 1;

  printf("Fibonacci sequence up to %d: ", n);
  printf("\n1, ");

  counter2 = -1;
  counter3 = 0;
  counter5 = 0;
  counter6 = 0;
  counter10 = 0;
  counter15 = 0;
  counter_none = 2;

  while (i <= n)
  {
    printf("%d, ", i);
    fib_term1 = fib_term2;
    fib_term1 = fib_term2;
    fib_term2 = i;



    i = fib_term1 + fib_term2;

    if (i%2 == 0){
      counter2++;
    }
    if (i%3 == 0){
      counter3++;
    }
    if (i%5 == 0){
      counter5++;
    }
    if (i%6 == 0){
      counter6++;
    }
    if (i%10 == 0){
      counter10++;
    }
    if (i%15 == 0){
      counter15++;
    }
    if ((i%2 != 0)&&(i%3 != 0)&&(i%5 != 0)&&(i%6 != 0)&&(i%10 != 0)&&(i%15 != 0)){
      counter_none++;

    }
  }
  printf("\n");
  printf("Divisible by: \n");
  printf("2           %d\n", counter2);
  printf("3           %d\n", counter3);
  printf("5           %d\n", counter5);
  printf("6           %d\n", counter6);
  printf("10          %d\n", counter10);
  printf("15          %d\n", counter15);
  printf("--          %d\n", counter_none);

  return 0;
}
