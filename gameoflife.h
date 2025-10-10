#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <stdio.h>

/* Count the number of alive neighbors for cell at position (i,j) in the field */
int count_alive(const char *field, int i, int j, int size);

/* Evolve the field one generation according to Conway's Game of Life rules */
void evolve(const char *field, char *t, int size);

/* Helper function to display the field (implemented in main.c) */
void dump_field(const char *f, int size);

#endif /* GAMEOFLIFE_H */