// #include "colors.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>

#include "cast.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
		std::cout << "You have to pass one str as param." << std::endl;
	else
	{
		bool result;
		std::string input = av[1];
		result = detect_type(input);
		std::cout << result << std::endl;
	}
}
