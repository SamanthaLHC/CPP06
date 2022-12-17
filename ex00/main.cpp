// #include "colors.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

bool is_int(std::string input_to_parse)
{
	int int_type = 0;

	std::istringstream ss(input_to_parse);
	if (ss >> int_type && (ss.rdbuf()->in_avail() == 0))
	{
		std::cout << "int: " << input_to_parse << std::endl;
		return true;
	}
	else
		// execute la method pour convertir en float double et char
		return false;
}

bool is_inff_or_nanf(std::string input, float &float_type)
{
	// std::string a une surcharge d'opé qui permet les comp directes
	if (input == "inff" || input == "+inff")
	{
		float_type = std::numeric_limits<float>::infinity();
		std::cout << "float: " << float_type << "f" << std::endl;
		return true;
	}
	else if (input == "-inff")
	{
		float_type = -std::numeric_limits<float>::infinity();
		std::cout << "float: " << float_type << "f" << std::endl;
		return true;
	}
	else if (input == "nanf")
	{
		float_type = std::numeric_limits<float>::signaling_NaN();
		std::cout << "float: " << float_type << "f" << std::endl;
		return true;
	}
	return false;
}

bool is_float(std::string input_to_parse)
{
	float float_type;

	std::istringstream ss(input_to_parse);
	if (is_inff_or_nanf(input_to_parse, float_type))
		return true;
	else if ((ss >> float_type && ss.rdbuf()->sgetc() == 'f'))
	{
		std::cout << "float: " << input_to_parse << std::endl;
		return true;
	}
	// call method convert char int double
	return false;
}

int main(int ac, char **av)
{

	if (ac != 2)
		std::cout << "You have to pass one str as param." << std::endl;
	else
	{
		bool result;
		std::string input = av[1];
		result = is_float(input);
		std::cout << result << std::endl;
	}
}
