#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m)
{
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i)
	{
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
	if (n <= 1)
		return n;

	long long period;
	long long previousRemainder = 0 % m;
	long long currentRemainder = 1 % m;

	std::vector<long long> numbers;
	std::vector<long long> remainders;
	numbers.push_back(0);
	numbers.push_back(1);

	remainders.push_back(previousRemainder);
	remainders.push_back(currentRemainder);
	for (long long i = 2; i < m * m; ++i)
	{
		numbers.push_back(numbers.at(i - 1) + numbers.at(i - 2));
		previousRemainder = currentRemainder;
		currentRemainder = numbers.at(i) % m;
		remainders.push_back(currentRemainder);
		if (currentRemainder == 1 && previousRemainder == 0)
		{

			period = i + 1;
			break;
		}

		if (i >= n)
		{
			return numbers.at(i) % m;
		}
	}

	long long remainder = n % period;

	return remainders.at(remainder);
}

int main()
{
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
