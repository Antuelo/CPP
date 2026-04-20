#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>

class Replace
{
	private:
		std::string 	_filename;
		std::string		_search;
		std::string		_replace;
	
	public:
		Replace(std::string _filename, std::string _search, std::string _replace);
		std::string readFile() const;
		std::string replaceall(const std::string& content) const;
		void writeFile(const std::string& result) const;
};

#endif //REPLACE_HPP
