#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid1[3][3]);
void print_grid1(int grid[3][3]);
void check_topple(int grid1[3][3]);
#endif
