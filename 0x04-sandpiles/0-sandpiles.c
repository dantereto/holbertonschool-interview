#include "sandpiles.h"


/**
 * is_stable - Knows if the sandpile is stable
 * @grid1: The grid
 * Return: 0
 */
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * check_topple - Fix the sandpile
 * @grid1: The grid
 * Return: 0
 */
void check_topple(int grid1[3][3])
{
	int i, j;
	int sand_grid1[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	printf("=\n");
	print_grid1(grid1);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] += 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] += 1;
				if (i + 1 < 3)
					grid1[i + 1][j] += 1;
				if (j + 1 < 3)
					grid1[i][j + 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += sand_grid1[i][j];
}

/**
 * print_grid1 - Print the grid
 * @grid: The grid
 * Return: 0
 */
void print_grid1(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_sum - Sums the sand piles
 * @grid1: First grid
 * @grid2: Second grid
 * Return: 0
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	while (is_stable(grid1) == 1)
	{
		check_topple(grid1);
	}
}
