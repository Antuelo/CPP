#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "animal.hpp"

class Brain
{
	private:
		std::string 		ideas[100];
	
	public:

		Brain();
		Brain(const Brain &copy);

		~Brain();

		Brain &operator=(const Brain &other);
};


#endif //BRAIN_HPP
