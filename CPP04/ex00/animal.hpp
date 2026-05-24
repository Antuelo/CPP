#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& copy);

	
		void makeSound();
};

class Dog : public Animal
{

};

class Cat : public Animal
{

};


#endif //ANIMAL_HPP
