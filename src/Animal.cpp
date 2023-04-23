#include "Animal.h"

using namespace std;

void Animal::printDetails() const
{
	cout << "The animal's name is " << name << endl;
	cout << location;

	if (canMove)
		cout << "He can move" << endl;
	else
		cout << "He cannot move" << endl;

	if (goingUp)
		cout << "He is going up" << endl;
	else
		cout << "He is going down" << endl;

	if (goingRight)
		cout << "He is going right" << endl;
	else
		cout << "He is going left" << endl;
}

Location Animal::getLocation() const
{
	return location;
}


void Animal::stop()
{
	canMove = false;
}

void Animal::move()
{
	if (!canMove) {
		goingRight = rand() % 2;
		goingUp = rand() % 2;
	}
	canMove = true;
}

void Animal::turnVertically()
{
	goingUp = !goingUp;
}

void Animal::turnHorizontally()
{
	goingRight = !goingRight;
}
