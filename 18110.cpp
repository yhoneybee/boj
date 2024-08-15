#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	uint32_t n{ 0 };
	std::cin >> n;

	if (n == 0)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	std::vector<uint32_t> v{};
	v.resize(n);

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> v.at(i);
	}

	std::stable_sort(v.begin(), v.end());

	const auto exclude_count = std::floor(n * 0.15 + 0.5);
	const auto sum = std::accumulate(v.begin() + exclude_count, v.end() - exclude_count, 0);
	const auto avg = std::floor(sum / (n - exclude_count * 2) + 0.5);
	std::cout << avg << std::endl;

	return 0;
}