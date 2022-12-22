#include "colors.h"

#include "cast.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
		std::cout << "You have to pass one str as param." << std::endl;
	else
	{
		std::string input = av[1];
		if (detect_type(input) == false)
			std::cout << BRED  << "conversion impossile." << RES << std::endl;
	}
}
