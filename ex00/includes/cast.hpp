#ifndef CAST_HPP
# define CAST_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>


bool detect_type(std::string const &input_to_parse);
void conv_int(int& int_type);
void conv_float(float &float_type, bool flag_inf_nan);
void conv_char(char &char_type);
void conv_double(double &double_type, bool flag_inf_nan);

#endif
