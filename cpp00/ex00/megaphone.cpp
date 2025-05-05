#include <iostream>
#include <cctype>

int	main(int nargs, char **args)
{
	if (nargs == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i != nargs; i ++)
		for (int u = 0; args[i][u] != '\0'; u ++)
			std::cout << (char)toupper(args[i][u]);
	std::cout << std::endl;
}