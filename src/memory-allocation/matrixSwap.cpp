#include <iostream>

int** init_square_matrix(int size)
{
    int** matrix = new int* [size];

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
            std::cout << "[" << i << "][" << j << "]: ";

            std::cout << array[i][j] << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

void swapRows(int a, int b, int** arr, int size)
{
    if (size <= a || size <= b)
    {
        return;
    }

    int* temp = arr[a];
    arr[a] = arr[b];

    arr[b] = temp;
    temp = nullptr;
}

void swapCols(int a, int b, int** arr, int size)
{
    if (size <= a || size <= b)
    {
        return;
    }

    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == a) {
                temp = arr[i][j];
                arr[i][j] = arr[i][b];
                arr[i][b] = temp;
            }
        }
    }
}

void run()
{
    int size = 5;
    int swap_a = 0;
    int swap_b = size - 1;

    int** matrix = init_square_matrix(size);

    populate_square_matrix(matrix, size);

    std::cout << "Swap Column " << swap_a << " to column " << swap_b << std::endl;

    std::cout << "Original Matrix" << std::endl;
    print_square_matrix(matrix, size);
    
    swapCols(swap_a, swap_b, matrix, size);

    std::cout << "Column Swapped Matrix" << std::endl;
    print_square_matrix(matrix, size);

    std::cout << "Swap Row "<< swap_a << " to row "<< swap_b << std::endl;

    std::cout << "Original Matrix" << std::endl;
    print_square_matrix(matrix, size);

    swapRows(swap_a, swap_b, matrix, size);

    std::cout << "Row Swapped Matrix" << std::endl;
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
}
