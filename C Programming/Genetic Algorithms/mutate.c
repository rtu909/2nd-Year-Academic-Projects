#include <stdio.h>
#include <stdlib.h>
#include "a4.h"
//Code based on https://github.com/RickoLacharity/Genetic-Algorithm-Parallel-OpenMP
void mutate(Individual *individual, double rate){
  int n = individual->image.width * individual->image.height; //finding the n value by muliplying width and height
  int max_colour = individual->image.max_color ;
  double mut_pix;
  mut_pix = rate/(100*n); //number of mutated PIXELs
  int i;                
  for(i=0; i < mut_pix; i++){
    int rand_ind = rand()%n;
    individual->image.data[rand_ind].r = rand()%max_colour; //mutating the red value
    individual->image.data[rand_ind].g = rand()%max_colour;
    individual->image.data[rand_ind].b = rand()%max_colour;
  }
};

void mutate_population(Individual *individual, int population_size, double rate){
  int quarter;
  for(quarter = population_size*0.25; quarter < population_size; quarter++ ){
		mutate(individual, rate);
	}
};
