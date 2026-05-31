#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "animal.hpp"

class Brain
{
	std::string 		ideas[100];

	Brain();
	Brain(const Brain &copy);

	~Brain();

	Brain &operator=(const Brain &other);
};


#endif //BRAIN_HPP
