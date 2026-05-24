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

	virtual ~Animal();

	
		void makeSound();
};

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog(std::string type);

		~Dog();
};

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		Cat(std::string type);

		~Cat();
};


#endif //ANIMAL_HPP
