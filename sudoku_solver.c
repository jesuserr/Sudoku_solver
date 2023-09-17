#include <stdio.h>
#include <stdlib.h>

void	print_matrix (int matrix[10][10])
{
	int	i;
	int	j;
	int	size;

	size = 9;	
	j = 1;
	while (j <= size)
	{
		i = 1;
		while (i <= size)
		{
			if (matrix [i][j] != 0)
				printf ("%d", matrix [i][j]);
			else
				printf (".");
			if (i % 3 == 0)
				printf (" ");
			i++;
		}
		printf ("\n");
		if (j % 3 == 0)
			printf ("\n");
	j++;				
	}
}

void	fill_matrix (int matrix[10][10], char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	for (j = 1; j <=9; j++)
	{
		for (i = 1; i <= 9; i++)
		{
			if (str [k] == '.')
				matrix [i][j] = 0;
			else
				matrix [i][j] = str [k] - 48;
			k++;
		}
	}
}

int	possible(int matrix[10][10], int x, int y, int n)
{
	int	i;
	int j;
	int	x_cell;
	int y_cell;
	
	i = 1;
	while (i <= 9)
	{
		if (matrix [i][y] == n)
			return (0);
		if (matrix [x][i] == n)
			return (0);
		i++;
	}
	x_cell = ((x - 1)/ 3) * 3;
	y_cell = ((y - 1) / 3) * 3;
	x_cell++;
	y_cell++;
	for (j = 0; j <= 2; j++)
	{
		for (i = 0; i <= 2; i++)
			{
				if (matrix [x_cell+i][y_cell+j] == n)
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
	int	size;

	size = 9;
	for (j = 1; j <= size; j++)
	{
		for (i = 1; i <= size; i++)
		{
			if (matrix [i][j] == 0)
			{
				for (n = 1; n <= size; n++)
				{
					if (possible (matrix, i, j, n))
					{
						matrix [i][j] = n;
						if (solve (matrix) == 1)
							return (1);
						else
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
	
	if (argc == 2)
	{
		fill_matrix (matrix, argv[1]);
		printf ("\nSudoku Inicial:\n");
		print_matrix (matrix);
		if (solve (matrix))
		{
			printf ("Solución Encontrada:\n");
			print_matrix (matrix);
		}
		else
			printf ("Sin Solución\n");
	}
	return (0);
}
