#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <queue>
#include <tuple>
#include <vector>

int main()
{
	size_t T{ 0 }, N{ 0 }, M{ 0 }, tmp{ 0 };

	std::cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		std::queue<std::tuple<size_t /*index*/, size_t /*priority*/>> q{};
		std::cin >> N >> M;
		std::vector<size_t> priorities{};
		priorities.reserve(N);

		for (size_t j = 0; j < N; j++)
		{
			std::cin >> tmp;
			q.emplace(j, tmp);
			priorities.emplace_back(tmp);
		}

		std::sort(priorities.begin(), priorities.end(), [](size_t left, size_t right) { return left > right; });

		size_t index{ 0 }, priority{ 0 }, sequence{ 0 };
		while(!q.empty())
		{
			std::tie(index, priority) = q.front();
			if (priority == priorities.front())
			{
				q.pop();
				priorities.erase(priorities.begin());
				++sequence;
				if (index == M)
				{
					std::cout << sequence << std::endl;
					break;
				}
			}
			else
			{
				const auto& peek = q.front();
				q.pop();
				q.push(peek);
			}
		}
	}

	return 0;
}