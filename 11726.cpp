#include <iostream>
#include <vector>

constexpr auto nl = '\n';

static auto fast_io()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
}

int main()
{
	fast_io();

	size_t N{ 0 };
	std::cin >> N;

	if (N == 1)
	{
		std::cout << 1 << nl;
		return 0;
	}

	std::vector<size_t> v{};
	v.resize(N);

	v.at(0) = 1;
	v.at(1) = 2;

	for (size_t i = 2; i < N; i++)
	{
		v.at(i) = v.at(i - 1) + v.at(i - 2);
		v.at(i) %= 10007;
	}

	std::cout << v.at(N - 1) % 10007 << nl;

	return 0;
}
