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

	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal &copy);

	std::string getType()const;
	virtual	void makeSound()const;
};

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog &copy);
		WrongDog(std::string type);

		~WrongDog();
		void makeSound() const;		
		
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat(std::string type);

		~WrongCat();

		WrongCat& operator=(const WrongCat& copy);

		void makeSound() const;
};

std::ostream& operator<<(std::ostream& os, const WrongAnimal &obj);

#endif
