#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"
//Code based on https://github.com/RickoLacharity/Genetic-Algorithm-Parallel-OpenMP
//comparison fucntion
static int compare(const void *a, const void *b){
  Individual *ai = (Individual *)a;
  Individual *bi = (Individual *)b;
  if (ai->fitness > bi->fitness)
    return 1;
  else if(ai ->fitness < bi->fitness)
    return (- 1);
  else
    return 0;
}

// Compute image
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
  int i;
  //generating the random population of population size
  //define individual pointer name for gen pop output
  Individual *population = generate_population(population_size, image->width, image->height, image->max_color); //returns a pointer to a "population", array of individual pointers of type pointer
  //computing the fitness of each individual
  comp_fitness_population(image->data, population, population_size);

  //sort the individuals by fitness
  qsort(population, population_size, sizeof(Individual), compare);

  //for loop for (4) in evolve
  for(i = 0; i < num_generations; i++){
    //crossing over the previous num_generations
    crossover(population,population_size);
    //mutating the new generation
    mutate_population(population,population_size,rate);            
    //computing the fitness of the new generation
    comp_fitness_population(image->data,population,population_size);
    //sorting for the individual with smallest fitness
    qsort(population, population_size, sizeof(Individual), compare);       
  }
  
  //freeing the memory of all the images that are not the fittest
  for(i = (population_size-1);i>0; i--){
    free(population[i].image.data); 
    //Individual *rmv = &population[i];
    //free(rmv); //invalid free
  }
  //free(population); 

  return &population[0].image;         
};

// Free image
void free_image(PPM_IMAGE *p){
  free(p->data);
  free(p);
};
