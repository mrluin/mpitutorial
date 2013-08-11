// Author: Wes Kendall
// Copyright 2013 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header in tact.
//
// Runs the MPI_Rank function with random input.
//
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "mpi_rank.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: parallel_rank\n");
    exit(1);
  }

  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Seed the random number generator to get different results each time
  srand(time(NULL) * world_rank);

  float rand_num = rand() / (float)RAND_MAX;
  int rank;
  MPI_Rank(&rand_num, &rank, MPI_FLOAT, MPI_COMM_WORLD);
  printf("Rank for %f on process %d - %d\n", rand_num, world_rank, rank);

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
}
