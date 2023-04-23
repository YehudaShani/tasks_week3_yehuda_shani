#include "Dog.h"

Dog::Dog(const Location& loc, std::string& str)
{
	name = str;
	location = loc;
	goingUp = rand() % 2;
	goingRight = rand() % 2;
}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::step()
{
	Location additional(0, 0);
	if (!(goBackwards % 3 == 2)) {
		if (goingUp)
			additional.row = 3;
		else
			additional.row = -3;

		if (goingRight)
			additional.col = 3;
		else
			additional.col = -3;
	}
	else {
		if (goingUp)
			additional.row = -1;
		else
			additional.row = 1;
		if (goingRight)
			additional.col = -1;
		else
			additional.col = 1;
	}

	if (location.row + additional.row >= 19 && goingUp)
		goingUp = false;
	if (location.row + additional.row <= 0 && !goingUp)
		goingUp = true;
	if (location.col + additional.col >= 39 && goingRight)
			goingRight = false;
	if (location.col + additional.col <= 0 && !goingRight)
		goingRight = true;

	location += additional;
	goBackwards++;
}

void Dog::printDetails() const
{
	cout << "The animal is a Dog" << endl;
	Animal::printDetails();
}
