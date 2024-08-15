#include <iostream>
#include <array>

int main()
{
	std::size_t N{ 0 }, T{ 0 }, P{ 0 };
	std::array<std::size_t, 6> size{ 0,0,0,0,0,0 };

	std::cin >> N;
	for (size_t i = 0; i < 6; i++)
	{
		std::cin >> size[i];
	}
	std::cin >> T >> P;

	std::size_t bundle_count{ 0 };
	for (size_t i = 0; i < 6; i++)
	{
		bundle_count += size[i] / T + std::min(size.at(i) % T, 1ULL);
	}

	std::cout << bundle_count << '\n';
	std::cout << N / P << ' ' << N - P * (N / P) << '\n';

	return 0;
}