#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>

class replace
{
	private:
		std::string 	_filename;
		std::string		_search;
		std::string		_replace;
	
	public:
		replace(std::string _filename, std::string _search, std::string _replace);
		std::string readFile() const;
		std::string replaceall(const std::string& content) const;
		void writeFile(const std::string& content) const;
};

#endif //REPLACE_HPP
