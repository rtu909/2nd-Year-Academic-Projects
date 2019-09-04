#include <stdio.h>
#include <stdlib.h>
#include "a4.h"
//Code based on https://github.com/RickoLacharity/Genetic-Algorithm-Parallel-OpenMP
// Read and write PPM file
PPM_IMAGE *read_ppm(const char *file_name){
  //vars
  FILE* file;
  char a, b;
  int nwidth, nheight, nmax_color, n, n1, n2, n3;
  int i;
  int red, green, blue;

  //opening file
  file = fopen(file_name, "r");

  n = fscanf(file, "%c%c", &a, &b ); //line one reads P3 value
  n1 = fscanf(file, "%d %d %d", &nwidth, &nheight, &nmax_color);

  int arr_len = nwidth * nheight; //finding length of pixel array

  //allocating and initializing the image
  PPM_IMAGE* image = malloc(sizeof(PPM_IMAGE));
  image->data = malloc(arr_len*(sizeof(PIXEL)));
  image->width = nwidth;
  image->height = nheight;
  image->max_color = nmax_color;

  for(i = 0; i < arr_len; i++){
    	n3 = fscanf(file, "%d %d %d", &red, &green, &blue);
	    image->data[i].r = red;
	    image->data[i].g = green;
	     image->data[i].b = blue;

  }
  fclose(file);
  return image;
};

void write_ppm(const char *file_name, const PPM_IMAGE *image){
  char a = 'P', b = '3';
  //arbitrary values for now
  int nwidth = image->width, nheight = image->height;
  int nmax_color = image->max_color;

  FILE* file;
  file = fopen(file_name, "w");

  fprintf(file, "%c%c\n", a, b );
  fprintf(file, "%d %d\n", nwidth, nheight );
  fprintf(file, "%d\n", nmax_color);

  int array_size = nheight*nwidth;
  int i;

  for (i = 0; i < array_size; i++) {
        fprintf(file, "%d %d %d ",image->data[i].r, image->data[i].g, image->data[i].b);
    }

  fclose(file);
};
