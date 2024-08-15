#include <array>
#include <iostream>
#include <tuple>
#include <vector>

struct Node
{
	auto Connect(Node* node) -> void
	{
		connection.at(connectionIndex++) = node;
	}

	bool is_visited = false;
	std::array<Node*, 100> connection = { nullptr, };
	size_t connectionIndex = 0;
};

int main()
{
	size_t computers{ 0 }, connections{ 0 };
	std::cin >> computers >> connections;

	std::vector<Node> nodes{};
	nodes.resize(computers);

	size_t from{ 0 }, to{ 0 };
	for (size_t i = 0; i < connections; i++)
	{
		std::cin >> from >> to;
		nodes.at(from - 1).Connect(&nodes.at(to - 1));
		nodes.at(to - 1).Connect(&nodes.at(from - 1));
	}

	const auto search = [](const auto self, Node* node) -> size_t
		{
			if (node->is_visited)
			{
				return 0;
			}

			node->is_visited = true;

			size_t result{ 1 };
			for (size_t i = 0; i < 100 && node->connection.at(i); i++)
			{
				result += self(self, node->connection.at(i));
			}

			return result;
		};

	std::cout << search(search, &nodes.at(0)) - 1 << std::endl;

	return 0;
}
