#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE	9

void	fill_matrix(int matrix[10][10], char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	for (j = 1; j <= SIZE; j++)
	{
		for (i = 1; i <= SIZE; i++)
		{
			if (!isdigit(str [k]))
				matrix [i][j] = 0;
			else
				matrix [i][j] = str [k] - 48;
			k++;
		}
	}
}

void	print_matrix(int matrix[10][10])
{
	int	i;
	int	j;

	for (j = 1; j <= SIZE; j++)
	{	
		for (i = 1; i <= SIZE; i++)
		{
			if (matrix [i][j] != 0)
				printf ("%d", matrix [i][j]);
			else
				printf (".");
			if (i % (SIZE / 3) == 0)
				printf (" ");
		}
		printf ("\n");
		if (j % (SIZE / 3) == 0)
			printf ("\n");
	}
}

int	possible(int matrix[10][10], int x, int y, int n)
{
	int	i;
	int	j;
	int	x_cell;
	int	y_cell;

	for (i = 1; i <= SIZE; i++)
	{
		if (matrix [i][y] == n)
			return (0);
		if (matrix [x][i] == n)
			return (0);
	}
	x_cell = (((x - 1) / 3) * 3) + 1;
	y_cell = (((y - 1) / 3) * 3) + 1;
	for (j = 0; j <= 2; j++)
	{
		for (i = 0; i <= 2; i++)
		{
			if (matrix [x_cell + i][y_cell + j] == n)
				return (0);
		}
	}
	return (1);
}

int	solve(int matrix[10][10])
{
	int	n;
	int	i;
	int	j;

	for (j = 1; j <= SIZE; j++)
	{
		for (i = 1; i <= SIZE; i++)
		{
			if (matrix [i][j] == 0)
			{
				for (n = 1; n <= SIZE; n++)
				{
					if (possible (matrix, i, j, n))
					{
						matrix [i][j] = n;
						if (solve (matrix) == 1)
							return (1);
						matrix [i][j] = 0;
					}					
				}
				return (0);
			}
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		matrix[10][10];

	if (argc == 2 && strlen(argv[1]) == SIZE * SIZE)
	{
		fill_matrix (matrix, argv[1]);
		printf ("\nInitial Sudoku:\n");
		print_matrix (matrix);
		if (solve (matrix))
		{
			printf ("Solution Found:\n");
			print_matrix (matrix);
		}
		else
			printf ("No Solution\n");
		return (0);
	}
	printf ("Wrong Arguments\n");
	return (0);
}
