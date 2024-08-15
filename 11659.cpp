#include <iostream>
#include <vector>
#include <cstdint>

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

	int64_t N{ 0 }, M{ 0 };
	std::cin >> N >> M;

	std::vector<std::pair<int64_t /*value*/, int64_t /*sum*/>> v{};
	v.resize(N);

	std::cin >> v.at(0).first;
	v.at(0).second = v.at(0).first;

	for (int64_t i = 1; i < N; i++)
	{
		std::cin >> v.at(i).first;
		v.at(i).second = v.at(i - 1).second + v.at(i).first;
	}

	int64_t begin{ 0 }, end{ 0 };
	for (int64_t i = 0; i < M; i++)
	{
		std::cin >> begin >> end;
		std::cout << v.at(end - 1).second - ((begin - 2 >= 0) ? v.at(begin - 2).second : 0) << nl;
	}

	return 0;
}