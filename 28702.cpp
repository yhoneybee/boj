#include <array>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::array<std::string, 3> lines{};
	for (auto& line : lines)
	{
		std::cin >> line;
	}

	for (size_t i = 0; i < lines.size(); i++)
	{
		const auto& line = lines.at(i);

		if (line.at(0) == 'F' || line.at(0) == 'B')
		{
			continue;
		}

		const auto integer = std::stoi(line) + std::abs(static_cast<int32_t>(i - lines.size()));
		if (integer % 3 == 0 && integer % 5 != 0)
		{
			std::cout << "Fizz" << std::endl;
		}
		else if (integer % 3 != 0 && integer % 5 == 0)
		{
			std::cout << "Buzz" << std::endl;
		}
		else if (integer % 3 == 0 && integer % 5 == 0)
		{
			std::cout << "FizzBuzz" << std::endl;
		}
		else
		{
			std::cout << integer << std::endl;
		}
		break;
	}
}