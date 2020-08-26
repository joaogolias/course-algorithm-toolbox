#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
	int length;

	cin >> length;

	int maximum = 0;
	int second_maximum = 0;
	int value;

	for (int i = 0; i < length; ++i)
	{
		cin >> value;
		if (value > maximum)
		{
			second_maximum = maximum;
			maximum = value;
		}
		else if (value > second_maximum)
		{
			second_maximum = value;
		}
	}

	long long result = (long long)maximum * second_maximum;
	cout << result;
	return result;
}