#include <iostream>

void* operator new(size_t size)
{
    std::cout << "new Hello world " << std::endl;
    void* p = malloc(size);
    return p;
}

void operator delete(void* p)
{
    std::cout << "delete Hello world" << std::endl;
    free(p);
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
    int size = 3;
    int swap_a = 0;
    int swap_b = size - 1;

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

    std::cout << "Swap Column " << swap_a << " to column " << swap_b << std::endl;

    std::cout << "Original Matrix" << std::endl;
    print_square_matrix(matrix, size);

    swapCols(swap_a, swap_b, matrix, size);

    std::cout << "Column Swapped Matrix" << std::endl;
    print_square_matrix(matrix, size);

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

    int* arr = new int[10];

    delete[] arr;
    arr = nullptr;
}
