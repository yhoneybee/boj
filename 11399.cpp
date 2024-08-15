#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	size_t N{ 0 }, sum{ 0 }, before_sum{ 0 };
	std::vector<size_t> P;

	std::cin >> N;
	P.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> P.at(i);
	}

	std::sort(P.begin(), P.end(), [](size_t left, size_t right) { return left < right; });
	for (size_t i = 0; i < N; i++)
	{
		sum += before_sum + P.at(i);
		before_sum += P.at(i);
	}

	std::cout << sum << std::endl;

	return 0;
}