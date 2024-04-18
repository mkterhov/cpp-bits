#include <iostream>

void populate_matrix(int* matrix, int rows, int cols)
{
	int counter = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(matrix + i * cols + j) = counter;
			counter++;
		}
	}
}

void print_matrix(int* array, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << "[" << i << "][" << j << "]: ";

			std::cout << *(array + i * cols + j) << " ";
		}

		std::cout << "\n";
	}

	std::cout << "\n";
}

void swap_elem(int *matrix, int i, int rows, int j, int cols)
{
	int temp = *((matrix + j * cols) + i);
	*((matrix + j * cols) + i) = *((matrix + i * rows) + j);
	*((matrix + i * rows) + j) = temp;
}

void transpose_matrix(int* matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
            swap_elem(matrix, i, cols, j, rows);
		}
	}
	std::cout << "\n";
}

void run()
{
	int rows = 4;
	int cols = 4;

	int* matrix = (int*)malloc(sizeof(int) * rows * cols);

	if (matrix == NULL) {
		std::cout << "Couldn't allocate memory for the matrix" << std::endl;
		std::cout << "Exectuion failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	populate_matrix(matrix, rows, cols);
	print_matrix(matrix, rows, cols);

	transpose_matrix(matrix, rows, cols);
	print_matrix(matrix, cols, rows);

	std::cout << std::endl;
	free(matrix);

	matrix = NULL;
}

int main()
{
	run();
}
