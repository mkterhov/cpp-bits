#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <limits>

const int MIN_LENGTH_INPUT_ARRAY = 1;
const int MIN_LENGTH_RAND_ARRAY = 20;

int* init_array(int n)
{
    return new int[n];
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int read_int_input(int min, std::string prompt)
{
    int n = -1;
    bool valid = false;
    while (!valid)
    {
        std::cout << prompt;
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cout << "Input entered is not int" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (n < min)
        {
            std::cout << "Please enter a number bigger than " << min << "!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            valid = false;
        } else {
            valid = true;
        }
    }

    return n;
}

void create_array_with_inputs()
{
    int length = read_int_input(MIN_LENGTH_INPUT_ARRAY, "Input array length: ");
    int* arr =  init_array(length);

    int counter = 0;
    while (counter < length)
    {
        std::cout << "Enter input for array["<< counter <<"]: ";
        std::cin >> arr[counter];
        counter++;
    }

    print_array(arr, length);

    delete[] arr;
}

//Returns the number of elements copied
int copy_odd_nums(int* output_array,int* input_array, int arr_size)
{
    int odd_counter = 0;

    for (int i = 0; i < arr_size; i++)
    {
        if (input_array[i] % 2 != 0) {
            output_array[odd_counter] = input_array[i];
            odd_counter++;
        }
    }

    return odd_counter;
}

void create_array_with_rand()
{
    int length = read_int_input(MIN_LENGTH_RAND_ARRAY, "Input array length: ");
    int* array_rand = init_array(length);

    srand(time(0));

    for (int i = 0; i < length; i++)
    {
        array_rand[i] = rand();
    }

    int* array_odd = init_array(length);

    int nr_odd_entries = copy_odd_nums(array_odd, array_rand, length);
    
    std::cout << "Rand array, with length : " << length<< "\n";
    print_array(array_rand, length);

    std::cout << "Odd array, with length: "<< nr_odd_entries << "\n";
    print_array(array_odd, nr_odd_entries);

    delete[] array_rand;
    delete[] array_odd;
}

void run()
{
    int choice = 0;

    while (true)
    {
        std::cout << "1) create array with inputs\n2) create array with rand values\n0) exit\n";
        choice = read_int_input(0, "Choose option: ");

        switch (choice)
        {
            case 1:
                create_array_with_inputs();
                break;
            case 2:
                create_array_with_rand();
                break;
            case 0:
                exit(EXIT_SUCCESS);
                break;
        }
    }
}

int main()
{
    run();
    
    return 0;
}
