#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "a4.h"
//Code based on https://github.com/RickoLacharity/Genetic-Algorithm-Parallel-OpenMP
// Random image and population
PIXEL *generate_random_image(int width, int height, int max_color){
  int array_size = width*height; //making 1D arrray of size width*height read from image
  int i; //counter
  PIXEL *pixel_array = (PIXEL*)malloc(sizeof(PIXEL)*array_size); //declaring our array of pixel structures

  //loop to populate pixel with random values for R, G, B
  for (i = 0; i < array_size; i++){
    pixel_array[i].r = (rand() % max_color+1);
    pixel_array[i].g = (rand() % max_color+1);
    pixel_array[i].b = (rand() % max_color+1);
  }
  return pixel_array; //return pointer to pixel_array
};

Individual *generate_population(int population_size, int width, int height, int max_color){
  //variables
  int i, size = width*height;
  //allocating memory for individual
  Individual *ind_arr = (Individual*)malloc(sizeof(Individual)*population_size);

  //generating the random pixels in the individul array
  for(i = 0; i < population_size; i++){
    ind_arr[i].image.width = width;
    ind_arr[i].image.height = height;
    ind_arr[i].image.max_color = max_color;
    ind_arr[i].image.data = generate_random_image(width, height, max_color);
  }
  return ind_arr;
};
