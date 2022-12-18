#include "cast.hpp"
#include <iostream>
#include <iomanip>

void print_char(char c_val, bool flag_inf_nan)
{
	if (flag_inf_nan == true)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c_val) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c_val << "'" << std::endl;
}

void print_float(float f_val)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f_val << "f" << std::endl;
}

void print_double(double d_val)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d_val << std::endl;
}

void print_int(int int_val, bool flag_inf_nan)
{
	if (flag_inf_nan == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int_val << std::endl;
}

void conv_int(int &int_type)
{
	char c_val = static_cast<char>(int_type);
	float f_val = static_cast<float>(int_type);
	double d_val = static_cast<double>(int_type);

	print_char(c_val, 0);
	print_int(int_type, 0);
	print_float(f_val);
	print_double(d_val);
}

void conv_float(float &float_type, bool flag_inf_nan)
{
	double d_val = static_cast<double>(float_type);
	int int_val = static_cast<int>(float_type);
	char c_val = static_cast<char>(float_type);

	print_char(c_val, flag_inf_nan);
	print_int(int_val, flag_inf_nan);
	print_float(float_type);
	print_double(d_val);
}

void conv_char(char &char_type)
{
	int int_val = static_cast<int>(char_type);
	float f_val = static_cast<float>(char_type);
	double d_val = static_cast<double>(char_type);

	print_char(char_type, 0);
	print_int(int_val, 0);
	print_float(f_val);
	print_double(d_val);
}

void conv_double(double& double_type, bool flag_inf_nan)
{
	int int_val = static_cast<int>(double_type);
	float c_val = static_cast<char>(double_type);
	double f_val = static_cast<float>(double_type);

	print_char(c_val, flag_inf_nan);
	print_int(int_val, flag_inf_nan);
	print_float(f_val);
	print_double(double_type);
}