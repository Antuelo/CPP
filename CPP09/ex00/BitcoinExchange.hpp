#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream> //read files
#include <cstdlib> //atoi et tout ça ...stdtod
//#include <exception>


class BitcoinExchange
{
	private:
		std::map<std::string, float> _data; // string date | float prix

		void 		load_database();
		bool		validationDate(const std::string &date)				const; //pour valider la date
		bool		Value_valid(float value)							const; //pour valider entre 0 et 1000
		float		lookingfor_exchangerate(const std::string &date)	const; //la date exacte o celui d avant
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);

	//public methods
		void		processLine(const std::string &line) const; //fait presque, tout le boulot

};

#endif


	//LES EXCEPTION...
// 		class 	date_Invalid : public std::exception
// 		{
// 			public:
// 				virtual const char* what() const throw(){return "Error: Invalid date";};
// 		};

// 		class 	value_invalid : public std::exception
// 		{
// 			public:
// 				virtual const char* what() const throw(){return "Error: Invalid value";};
// 		};

// 		class Negative_error : public std::exception
// 		{
// 			public:
// 				virtual const char *what() const throw(){return "Error: Only possitive numbers!";};
// 		};

// 		class TooLongNumberError : public std::exception
// 		{
// 			public:
// 				virtual const char *what() const throw(){return "Error: Number is too long!";};
// 		};

// 		class Badinput : public std::exception
// 		{
// 			public:
// 				virtual const char *what() const throw(){return "Error: Bad imput!";};
// 		};
// };

