#include <iostream>

class Matrix
{
private:
    int rows = 0;
    int columns = 0;
    int *store = nullptr;

    void swapElem(const int& x, const int& y)
    {
        int temp = *((store + y * columns) + x);
        *((store + y * columns) + x) = *((store + x * rows) + y);
        *((store + x * rows) + y) = temp;
    }

public:
    Matrix(const int& crows, const int& ccols)
    {
        rows =  crows;
        columns =  ccols;
        store = (int*)malloc(rows*columns*sizeof(int));
    }

    void populateMatrix() const
    {
        int counter = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                *(store + i * columns + j) = counter;
                counter++;
            }
        }
    }

    void printMatrix() const
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "[" << i << "][" << j << "]: ";

                std::cout << *(store + i * columns + j) << " ";
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
        free(store);
        store = nullptr;
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
