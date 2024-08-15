#include <iostream>
#include <vector>

int main()
{
	size_t N{ 0 }, K{ 0 }, count{ 0 };
	std::vector<size_t> A{};

	std::cin >> N >> K;
	A.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> A.at(i);
	}

	for (int i = A.size() - 1; i >= 0; i--)
	{
		while (K >= A.at(i))
		{
			K -= A.at(i);
			++count;
		}
	}

	std::cout << count << std::endl;

	return 0;
}