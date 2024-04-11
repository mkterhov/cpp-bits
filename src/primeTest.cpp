#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <climits>

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

void run_is_prime_tests()
{
	std::vector<int> primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, INT_MAX };
	
	for (int n : primes)
	{
		assert(is_prime(n) == true);
	}
	
	std::vector<int> non_primes{ 1, 8, 12, 20, 77127390 };

	for (int n : non_primes)
	{
		assert(is_prime(n) == false);
	}
}

int factorial(int num)
{
	if (num <= 0)
	{
		return 1;
	}

	return num * factorial(num - 1);
}

void run_factorial_tests()
{
	std::vector<int> factorials{ 0, 1, 5, 9, 12};
	std::vector<int> results{ 1, 1, 120, 362880, 479001600 };

	for (int i = 0; i < factorials.size(); i++)
	{
		assert(factorial(factorials.at(i)) == results.at(i));
	}
}

int fibonacci(int position)
{
	if (position == 1 || position == 0)
	{
		return position;
	}

	return fibonacci(position - 1) + fibonacci(position - 2);
}

void run_fibonacci_tests()
{
	std::vector<int> positions{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	std::vector<int> results{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};

	for (int i = 0; i < positions.size(); i++)
	{
		assert(fibonacci(positions.at(i)) == results.at(i));
	}
}


int main()
{
	run_is_prime_tests();
	run_factorial_tests();
	run_fibonacci_tests();

	return 0;
}
