#include <stdio.h>
#include <math.h>
#include "a4.h"
#define SQR(x) (x)*(x)
//Code based on https://github.com/RickoLacharity/Genetic-Algorithm-Parallel-OpenMP
double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double sum_di = 0;
  for(int i = 0; i < image_size; i++){
    //finding difference between red pixels
    double r = A[i].r - B[i].r; 
    double rsq = SQR(r); //squaring the difference
    //finding difference between green pixels
    double g = A[i].g - B[i].g;
    double gsq = SQR(g); //squaring the difference 
    //finding difference between blue pixels
    double b = A[i].b - B[i].b;
    double bsq = SQR(b); //squaring the difference

    double di = rsq + gsq + bsq;//the di value
    sum_di = sum_di + di; // the summation of di values
  }
  //distance between A and B
  double f_AB = sqrt(sum_di);
  return f_AB;
};

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
  int size;
  double fitness; //stores funtion call to be printed
  //loops through the individual array to calculate distance of each pixel in individual array and image pixel
  size = individual[0].image.width * individual[0].image.height;
  for(int i = 0; i < population_size; i++){
    fitness = comp_distance(image, individual[i].image.data, size); //distance between image and individual pixel array (data)
    individual[i].fitness = fitness;
  }
};
