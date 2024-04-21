#include <iostream>

class Matrix
{
private:
    int rows = 0;
    int columns = 0;
    int** matrix = nullptr;

    void swap(const int& x, const int& y)
    {
        matrix[x][y] = matrix[y][x];
    }

public:
    Matrix(const int& p_rows, const int& p_cols)
    {
        rows = p_rows;
        columns = p_cols;
        matrix = new int* [p_rows];

        for (int i = 0; i < p_rows; i++)
        {
            matrix[i] = new int[p_cols];
        }
    }

    Matrix(const Matrix& m) 
    {
        std::cout << "calling copy" << std::endl;

        this->columns = m.columns;
        this->rows = m.rows;
        this->matrix = new int*[this->rows];

        for (int i = 0; i < this->columns; i++)
        {
            this->matrix[i] = new int[this->columns];
        }

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->matrix[i][j] = m.matrix[i][j];
            }
        }

    }

    Matrix& operator+(const Matrix& m)
    {
        if (this->rows != m.rows || this->columns != m.columns) {
            throw std::logic_error("Cannot add two matrices with varied column or row sizes");
        }

        std::cout << "calling assignment" << std::endl;

        if (this == &m)
        {
            return *this;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                this->matrix[i][j] = this->matrix[i][j]+ m.matrix[i][j];
            }
        }

        return *this;
    }

    Matrix& operator=(const Matrix& m)
    {
        std::cout << "calling assignment" << std::endl;

        if (this == &m)
        {
            return *this;
        }

        if (this->matrix != nullptr)
        {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
                this->matrix[i] = nullptr;
            }

            delete[] matrix;
            this->matrix = nullptr;
        }

        this->columns = m.columns;
        this->rows = m.rows;
        this->matrix = new int* [this->rows];

        for (int i = 0; i < this->columns; i++)
        {
            this->matrix[i] = new int[this->columns];
        }

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->matrix[i][j] = m.matrix[i][j];
            }
        }

        return *this;
    }

    void populate() const
    {
        int counter = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = counter;
                counter++;
            }
        }
    }

    void print() const
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "[" << i << "][" << j << "]: ";

                std::cout << matrix[i][j] << " ";
            }

            std::cout << "\n";
        }

        std::cout << "\n";
    }

    void transpose()
    {
        if (rows != columns) {
            throw std::logic_error("Cannot transpose the matrix when rows and columns are not equal");
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(i, j);
            }
        }
        std::cout << "\n";
    }

    ~Matrix()
    {
        std::cout << "calling destructor" << std::endl;
        if (matrix == nullptr)
        {
            return;
        }
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }

        delete[] matrix;
        matrix = nullptr;
    }
};

int main()
{
    Matrix matrix1{ 4, 4 };

    matrix1.populate();
    std::cout << "matrix 1 before assignment" << std::endl;
    matrix1.print();

    Matrix matrix2{ 3, 3 };
    matrix2.populate();
    std::cout << "matrix 2 before assignment" << std::endl;
    matrix2.print();
    matrix2 = matrix1;

    matrix1.print();
    std::cout << "matrix 2 after assignment to matrix 1" << std::endl;
    matrix2.print();

    Matrix matrix3(matrix2);

    std::cout << "matrix 3 after copy" << std::endl;
    matrix3.print();

    matrix1 = matrix1 + matrix2;
    std::cout << "print matrix 1 after adding matrix 2" << std::endl;
    matrix1.print();

    Matrix matrix4{ 100, 100 };
    matrix4.populate();
    try {
            matrix4 = matrix4 + matrix1;
    }
    catch (std::runtime_error const&)
    {
        std::cout << "cannot add together different sized matrices" << std::endl;
    }

    return 0;
}
