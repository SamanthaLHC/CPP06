#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "colors.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
	int generate = 0;
	std::srand(std::time(NULL));
	generate = (std::rand() % 3);

	if (generate == 0)
	{
		std::cout << BWHT << "create A class" << RES << std::endl;
		return new A;
	}
	else if (generate == 1)
	{
		std::cout << BWHT << "create B class" << RES << std::endl;
		return new B;
	}
	else
	{
		std::cout << BWHT << "create C class" << RES << std::endl;
		return new C;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << BWHT << "object is type A " << RES << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << BWHT << "object is type B " << RES << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << BWHT << "object is type C" << RES << std::endl;
	else
		std::cout << BRED << "ERROR " << RES << std::endl;
}

void identify(Base &p)
{
	try
	{
		p = dynamic_cast<A &>(p);
		std::cout << BWHT << "object is type A " << RES << std::endl;
	}
	catch (const std::exception &)
	{
		try
		{
			p = dynamic_cast<B &>(p);
			std::cout << BWHT << "object is type B " << RES << std::endl;
		}
		catch (const std::exception &)
		{
			try
			{
				p = dynamic_cast<C &>(p);
				std::cout << BWHT << "object is type C " << RES << std::endl;
			}
			catch (const std::exception &) {}
		}
	}
}

int main()
{
	Base *gen = generate();
	identify(gen);
	// le prototype attend un ref donc le compilo passe une ref plutot qu une copie
	identify(*gen);
	delete gen;
}