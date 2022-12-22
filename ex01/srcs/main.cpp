#include "data.hpp"
#include "colors.h"

#include <stdint.h>
#include <iostream>

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data *data = new Data;
	data->i = 42;
	data->f = 8.0f;
	data->str = "pouet";
	std::cout << BWHT << "int in data: " << data->i << std::endl
			  << BWHT << "float in data: " << data->f << std::endl
			  << BWHT << "str in data: " << data->str << RES << std::endl;
	uintptr_t ret = serialize(data);
	std::cout << BYEL << "serialized data:  " << ret << std::endl;
	Data *data_serialized = deserialize(ret);
	std::cout << BCYN << "data's ptr:  " << data << std::endl
			  << BCYN << "ret deserialize: " << data_serialized << RES << std::endl;
	std::cout << BWHT << "int in data_serialized: " << data_serialized->i << std::endl
			  << BWHT << "float in data_serialized: " << data_serialized->f << std::endl
			  << BWHT << "str in data_serialized: " << data_serialized->str << RES << std::endl;
	delete data;
}