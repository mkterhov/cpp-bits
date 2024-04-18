#include <iostream>

class Matrix
{
private:
    int rows = 0;
    int columns = 0;
    int *ptr_matrix = nullptr;

    void swapElem(const int& x, const int& y)
    {
        int temp = *((ptr_matrix + y * columns) + x);
        *((ptr_matrix + y * columns) + x) = *((ptr_matrix + x * rows) + y);
        *((ptr_matrix + x * rows) + y) = temp;
    }

public:
    Matrix(const int& p_rows, const int& p_cols)
    {
        rows =  p_rows;
        columns =  p_cols;
        ptr_matrix = (int*)malloc(rows*columns*sizeof(int));
    }

    void populateMatrix() const
    {
        int counter = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                *(ptr_matrix + i * columns + j) = counter;
                counter++;
            }
        }
    }

    void printMatrix() const
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "[" << i << "][" << j << "]: ";

                std::cout << *(ptr_matrix + i * columns + j) << " ";
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
        free(ptr_matrix);
        ptr_matrix = nullptr;
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
