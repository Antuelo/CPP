#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
	
		~ScalarConverter();

		ScalarConverter operator=(const ScalarConverter &other);
	
	public:
		static void convert(std::string param);
};

#endif //SCALARCONVERTER_HPP
