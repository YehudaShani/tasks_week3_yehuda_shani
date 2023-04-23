#include "Animal.h"

class Monkey : public Animal {

	int changeDirection = 0;

	public:
	Monkey(const Location& loc, std::string& str);
	char getInitial() const override;
	void step() override;
	void printDetails() const;
	void move() ;
};