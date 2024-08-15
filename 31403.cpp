#include <iostream>

int main()
{
	int A{ 0 }, B{ 0 }, C{ 0 };

	std::cin >> A >> B >> C;
	std::cout << A + B - C << '\n';

	for (int i = 10; i <= 10000; i *= 10)
	{
		if (B / i <= 0)
		{
			std::cout << A * i + B - C << '\n';
			break;
		}
	}

	return 0;
}