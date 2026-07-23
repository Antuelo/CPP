#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

void	convertion(std::string param, std::string type);

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


/*
	el principio es que no tiene que ser instanciable, es decir, no necesita un objeto, se le pasa el dato directamente

ejemplo: 

❌ Si fuera instanciable (como está ahora):

ScalarConverter obj;               // ← se puede crear un objeto
obj.convert("42");                 // ← se puede llamar al método

✅ Si NO es instanciable (como debe ser):
cpp

ScalarConverter::convert("42");    // ← se llama directamente sin objeto

Ventaja: Más limpio, más eficiente, evita confusiones.
*/