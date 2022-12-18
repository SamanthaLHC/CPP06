#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>

bool is_int(std::string const &input_to_parse)
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

bool is_inff_or_nanf(std::string const &input, float &float_type)
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

bool is_inf_or_nan(std::string const &input, double &double_type)
{
	// std::string a une surcharge d'opé qui permet les comp directes
	if (input == "inf" || input == "+inf")
	{
		double_type = std::numeric_limits<double>::infinity();
		std::cout << "double: " << double_type << std::endl;
		return true;
	}
	else if (input == "-inf")
	{
		double_type = -std::numeric_limits<double>::infinity();
		std::cout << "double: " << double_type << std::endl;
		return true;
	}
	else if (input == "nan")
	{
		double_type = std::numeric_limits<double>::signaling_NaN();
		std::cout << "double: " << double_type << std::endl;
		return true;
	}
	return false;
}

bool is_float(std::string const &input_to_parse)
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

bool is_double(std::string const &input_to_parse)
{
	double double_type;
	std::istringstream ss(input_to_parse);
	if (is_inf_or_nan(input_to_parse, double_type))
		return true;
	else if (input_to_parse.find(".") != std::string::npos)
	{
		if (ss >> double_type && ss.rdbuf()->in_avail() == 0)
		{
			std::cout << "double: " << input_to_parse << std::endl;
			return true;
		}
	}
	return false;
}

bool is_char(std::string const &input_to_parse)
{
	char char_type = 0;

	std::istringstream ss(input_to_parse);
	if (ss >> char_type && (isdigit(char_type) == false && isprint(char_type)) && ss.rdbuf()->in_avail() == 0)
	{
		std::cout << "char: " << input_to_parse << std::endl;
		return true;
	}
	else
		// execute la method pour convertir en float double et char
		return false;
}

bool detect_type(std::string const &input_to_parse)
{
	bool (*func_list[4])(std::string const &) = {&is_int, &is_float, &is_double, &is_char};

	for (int i = 0; i < 4; i++)
		if ((*func_list[i])(input_to_parse))
			return true;
	return false;
}