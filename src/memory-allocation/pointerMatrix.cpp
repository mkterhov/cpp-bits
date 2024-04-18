#include <iostream>

int** init_square_matrix(int size)
{
    int** matrix = new int*[size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    return matrix;
}

void populate_square_matrix(int** matrix, int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand();
        }
    }
}

void print_square_matrix(int** array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << array[i][j] << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

void run()
{
    int size = 10;

    int** matrix = init_square_matrix(size);

    populate_square_matrix(matrix, size);

    print_square_matrix(matrix, size);

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;
}

int main()
{
    run();

    return 0;
}