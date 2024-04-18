#include <iostream>

void populate_square_matrix(int** matrix, int m, int n)
{
	int counter = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = counter;
			counter++;
		}
	}
}

void print_square_matrix(int** array, int m, int n)
{
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			std::cout << "[" << i << "][" << j << "]: ";

			std::cout << array[i][j] << " ";
		}

		std::cout << "\n";
	}

	std::cout << "\n";
}

void transpose_matrix(int** matrix, int** transpose, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			transpose[j][i] = matrix[i][j];

		}
	}
}

void run()
{
	int m = 5;
	int n = 20;

	int** matrix = (int**)malloc(sizeof(int*) * m);

	if (matrix == NULL) {
		std::cout << "Couldn't allocate memory for the matrix" << std::endl;
		std::cout << "Exectuion failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * n);
		if (matrix[i] == NULL) {
			free(matrix);
			matrix = NULL;
			exit(EXIT_FAILURE);
		}
	}

	int** transpose = (int**)malloc(sizeof(int*) * n);

	if (transpose == NULL) {
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++)
	{
		transpose[i] = (int*)malloc(sizeof(int) * m);
		if (transpose[i] == NULL) {
			free(transpose);
			transpose = NULL;
			exit(EXIT_FAILURE);
		}
	}

	populate_square_matrix(matrix, m, n);
	print_square_matrix(matrix, m, n);

	transpose_matrix(matrix, transpose, m, n);
	print_square_matrix(transpose, n, m);

	std::cout << std::endl;
	for (int i = 0; i < m; i++) {
		free(matrix[i]);
		matrix[i] = NULL;
	}
	free(matrix);

	for (int i = 0; i < n; i++) {
		free(transpose[i]);
		transpose[i] = NULL;
	}
	free(transpose);

	transpose = NULL;
}

int main()
{
	run();
}
