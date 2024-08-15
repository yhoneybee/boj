#include <iostream>
#include <vector>

int main()
{
	std::vector<size_t> dp{};
	dp.resize(11);

	dp.at(0) = 1;
	dp.at(1) = 2;
	dp.at(2) = 4;

	for (size_t i = 3; i < 11; i++)
	{
		dp.at(i) = dp.at(i - 1) + dp.at(i - 2) + dp.at(i - 3);
	}

	size_t T{ 0 }, N{ 0 };
	std::cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		std::cin >> N;
		std::cout << dp.at(N - 1) << std::endl;
	}

	return 0;
}
