#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& copy);

	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal &other);

	std::string getType()const;

	void makeSound()const;
};

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog &copy);
		WrongDog(std::string type);

		~WrongDog();

		WrongDog& operator=(const WrongDog &other);

		void makeSound() const;		
		
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat(std::string type);

		~WrongCat();

		WrongCat& operator=(const WrongCat &other);

		void makeSound() const;
};

std::ostream& operator<<(std::ostream& os, const WrongAnimal &obj);

#endif
