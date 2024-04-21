#include <iostream>

class Matrix
{
private:
    int rows = 0;
    int columns = 0;
    int *matrix = nullptr;

    void swapElem(const int& x, const int& y)
    {
        int temp = *((matrix + y * columns) + x);
        *((matrix + y * columns) + x) = *((matrix + x * rows) + y);
        *((matrix + x * rows) + y) = temp;
    }

public:
    Matrix(const int& p_rows, const int& p_cols)
    {
        rows =  p_rows;
        columns =  p_cols;
        matrix = (int*)malloc(rows*columns*sizeof(int));
    }

    void populateMatrix() const
    {
        int counter = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                *(matrix + i * columns + j) = counter;
                counter++;
            }
        }
    }

    void printMatrix() const
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "[" << i << "][" << j << "]: ";

                std::cout << *(matrix + i * columns + j) << " ";
            }

            std::cout << "\n";
        }

        std::cout << "\n";
    }

    void transposeMatrix()
    {
        if (rows != columns) {
            throw std::runtime_error("Cannot transpose the matrix when rows and columns are not equal");
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swapElem(i, j);
            }
        }
        std::cout << "\n";
    }

    ~Matrix()
    {
        free(matrix);
        matrix = nullptr;
    }
};

int main()
{
    Matrix matrix{4, 4};
    
    matrix.populateMatrix();
    matrix.printMatrix();

    matrix.transposeMatrix();
    matrix.printMatrix();

    return 0;
}
