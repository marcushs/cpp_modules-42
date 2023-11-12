#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc && argc > 1; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
			argv[i][j] = std::toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
}
