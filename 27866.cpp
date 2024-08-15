#include <iostream>

int main()
{
	std::string S{};
	std::size_t i{};

	std::cin >> S >> i;
	std::cout << S.at(i - 1);

	return 0;
}