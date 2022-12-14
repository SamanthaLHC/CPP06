// #include "colors.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>


bool is_int(std::string input_to_parse)
{
	int int_type;

	std::istringstream ss(input_to_parse);
	if (ss >> int_type)
	{
		if (int_type <= std::numeric_limits<int>::max() || int_type >= std::numeric_limits<int>::min())
			return true;
		return false;
	}
	else
		return false;
}

int main(int ac, char **av)
{

	if (ac != 2)
		std::cout << "You have to pass one str as param." << std::endl;
	else
	{
		bool result;
		std::string input =	std::getline(std::cin, av[1]);
		result = is_int(input);
		std::cout << result << std::endl;
	}
}
