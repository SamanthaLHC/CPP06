#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>

#include "colors.h"
#include "cast.hpp"

bool is_int(std::string const &input_to_parse)
{
	int int_type = 0;

	std::istringstream ss(input_to_parse);
	if (ss >> int_type && (ss.rdbuf()->in_avail() == 0))
	{
		conv_int(int_type);
		return true;
	}
	else
		return false;
}

bool is_inff_or_nanf(std::string const &input, float &float_type, bool &flag_inff_nanff)
{
	// std::string a une surcharge d'opé qui permet les comp directes
	if (input == "inff" || input == "+inff")
	{
		float_type = std::numeric_limits<float>::infinity();
		flag_inff_nanff = 1;
		return true;
	}
	else if (input == "-inff")
	{
		float_type = -std::numeric_limits<float>::infinity();
		flag_inff_nanff = 1;
		return true;
	}
	else if (input == "nanf")
	{
		float_type = std::numeric_limits<float>::signaling_NaN();
		flag_inff_nanff = 1;
		return true;
	}	
	return false;
}

bool is_inf_or_nan(std::string const &input, double &double_type, bool &flag_inf_nan)
{
	// std::string a une surcharge d'opé qui permet les comp directes
	if (input == "inf" || input == "+inf")
	{
		double_type = std::numeric_limits<double>::infinity();
		flag_inf_nan = 1;
		return true;
	}
	else if (input == "-inf")
	{
		double_type = -std::numeric_limits<double>::infinity();
		flag_inf_nan = 1;
		return true;
	}
	else if (input == "nan")
	{
		double_type = std::numeric_limits<double>::signaling_NaN();
		flag_inf_nan = 1;
		return true;
	}
	return false;
}

bool is_float(std::string const &input_to_parse)
{
	float float_type;
	bool flag_inf_nan = false;

	std::istringstream ss(input_to_parse);
	if (is_inff_or_nanf(input_to_parse, float_type, flag_inf_nan))
	{
		conv_float(float_type, flag_inf_nan);
		return true;
	}
	else if ((ss >> float_type && ss.rdbuf()->sgetc() == 'f'))
	{
		conv_float(float_type, flag_inf_nan);
		return true;
	}
	return false;
}

bool is_double(std::string const &input_to_parse)
{
	double double_type;
	bool flag_inf_nan = false;

	std::istringstream ss(input_to_parse);
	if (is_inf_or_nan(input_to_parse, double_type, flag_inf_nan))
	{
		conv_double(double_type, flag_inf_nan);
		return true;
	}
	else if (input_to_parse.find(".") != std::string::npos)
	{
		if (ss >> double_type && ss.rdbuf()->in_avail() == 0)
		{
			conv_double(double_type, flag_inf_nan);
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
		conv_char(char_type);
		return true;
	}
	else
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
