#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLACK "\033[0m"
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

	Animal& operator=(const Animal &other);

	std::string 		getType()const;
	virtual	void 		makeSound()const;
};

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog(std::string type);

		~Dog();

		Dog& operator=(const Dog &other);

		void makeSound() const;
};

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		Cat(std::string type);

		~Cat();

		Cat& operator=(const Cat& copy);

		void makeSound() const;
};

std::ostream& operator<<(std::ostream& os, const Animal &obj);

#endif //ANIMAL_HPP
