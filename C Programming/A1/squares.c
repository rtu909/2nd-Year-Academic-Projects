#include <stdio.h>


/*Squares Function */

int main(void)
{
  int num_squares, i, rows, r, columns, c, remainder, remainder_counter;

  printf("Enter the number of squares to print: ");
  scanf("%d", &num_squares);
  if (num_squares <= 0 || num_squares > 50){
    printf("Enter the number of squares to print: ");
    scanf("%d", &num_squares);
  }


  rows = num_squares*3;
  if(num_squares >= 5){
    for (i = 0; i < (num_squares*3 - rows%15); i++){
      if (i > 0 && i%5 == 0){
        printf("\n");
      }
      if (i%15 == 0){
        printf("\n");
      }

      printf("###");
      printf(" ");
  }
  }

  if(num_squares < 5){
    for (i = 0; i < (num_squares*3); i++){
      if (i > 0 && i%num_squares == 0){
        printf("\n");
      }
      if (i%15 == 0){
        printf("\n");
      }

      printf("###");
      printf(" ");
    }
  }
  printf("\n");
  remainder = num_squares%5;
  for (i = 0; i < (remainder*3); i++){
      if (i > 0 && i%remainder == 0){
        printf("\n");
      }
      if (i%15 == 0){
        printf("\n");
      }

      printf("###");
      printf(" ");
    }
  return 0;

}
