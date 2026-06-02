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
		Brain(std::string idea[100]);

		~Brain();

		Brain &operator=(const Brain &other);
};


#endif //BRAIN_HPP
