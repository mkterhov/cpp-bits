#include <iostream>
#include <math.h>

bool is_prime(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }

    for (int i = 2; i < std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}


void populate_square_matrix(int** matrix, int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 1 + (rand() % 9);
        }
    }
}

void print_square_matrix(int** array, int size)
{
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {
            std::cout << "[" << i << "][" << j << "]: ";

            std::cout << array[i][j] << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

int find_lower_diagonal_elements(int** matrix, int size)
{
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        { 
                sum += matrix[i][j]; 
        } 
    }
    
    print_square_matrix(matrix, size);
    return sum;
}

void run()
{
    int size = 4;

    int** matrix = (int**)malloc(sizeof(int*) * size);

    if (matrix == NULL) {
        std::cout << "Couldn't allocate memory for the matrix" << std::endl;
        std::cout << "Exectuion failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * size);
        if (matrix[i] == NULL) {
            free(matrix);
            matrix = NULL;
            std::cout << "Couldn't allocate memory  for  the rows" << std::endl;
            std::cout << "Execution halted" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    populate_square_matrix(matrix, size);
    print_square_matrix(matrix, size);

    long long sum = find_lower_diagonal_elements(matrix, size);

    std::cout << "SUM of lower elements: " << sum << std::endl;

    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);
    matrix = NULL;
}

int main()
{
    run();
}
