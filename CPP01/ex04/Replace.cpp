/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:28:04 by antuel            #+#    #+#             */
/*   Updated: 2026/04/20 22:57:10 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>

Replace::Replace(std::string filename, std::string search, std::string replace)
{
	_filename = filename;
	_search = search;
	_replace = replace;
}

std::string Replace::readFile() const
{
	std::ifstream infile(_filename.c_str());
	if (!infile)
		return (std::cout << "can't open file" << std::endl, "");
	
	std::string content, line;

	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += "\n";
	}

	return (content);
}

std::string Replace::replaceall(const std::string& content) const
{
	std::string	result;
	size_t		pos;
	size_t		startpos = 0;
	
	pos = content.find(_search, startpos);
	/*if (pos == std::string::npos)
		return (std::cout << "Error: nothing to change" << std::endl, "");*/
	
	while (pos != std::string::npos)
	{
		result += content.substr(startpos, pos - startpos);
		result += _replace;
		startpos = pos + _search.length();
		pos = content.find(_search, startpos);
	}
	
	result += content.substr(startpos);
	return result;
}


void Replace::writeFile(const std::string& content) const
{
	std::ofstream outfile((_filename + ".replace").c_str());
	if (!outfile)
	{
		std::cout << "Error: cannot create file" << std::endl;
		return;
	}
	outfile << content;
}