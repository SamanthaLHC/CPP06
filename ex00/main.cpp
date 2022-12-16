// #include "colors.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

bool check_int_limits(int int_type)
{
	if (int_type <= std::numeric_limits<int>::max() || int_type >= std::numeric_limits<int>::min())
		return true;
	else
		return false;
}

bool check_float_limits(float float_type)
{
	if (float_type <= std::numeric_limits<float>::max() || float_type >= std::numeric_limits<float>::min())
		return true;
	else
		return false;
}

bool is_int(std::string input_to_parse)
{
	int int_type = 0;

	std::istringstream ss(input_to_parse);
	if (ss >> int_type && (check_int_limits(int_type)))
	{
		std::cout << "int: " << input_to_parse << std::endl;
		return true;
	}
	else
		// execute la method pour convertir en float double et char
		return false;
}
// ATTENTION NOT MINE A DELETE
bool isInteger(double N)
{

	// Convert float value
	// of N to integer
	int X = static_cast<double> (N);

	double temp2 = N - X;

	// If N is not equivalent
	// to any integer
	if (temp2 > 0)
	{
		return false;
	}
	return true;
}

// un int peutr etre contenu ds un float
// un float peut etre contenu ds un double
bool is_float(std::string input_to_parse)
{
	float float_type;

	std::istringstream ss(input_to_parse);
	if (ss >> float_type && (check_float_limits(float_type)))
	{
		std::cout << "Seem to be a float" << std::endl;
		// -inff +inff nan et limits float ?
		return true;
	}
	else
		// call method convert char int double
		return false;
}

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	double N = 1.5;
	if (isInteger(N))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	// if (ac != 2)
	// 	std::cout << "You have to pass one str as param." << std::endl;
	// else
	{
		// bool result;
		// std::string input = av[1];
		// result = is_float(input);
		// std::cout << result << std::endl;
	}
}
