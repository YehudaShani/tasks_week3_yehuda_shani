#include "Monkey.h"

using namespace std;

Monkey::Monkey(const Location& loc, std::string& str)
{
	name = str;
	location = loc;
	goingUp = rand() % 2;
	goingRight = rand() % 2;
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::step()
{
	move();

	int steps = rand() % 2 + 1;

	Location additional(0, 0);
	if (goingUp)
		additional.row = steps;
	else
		additional.row = -steps;

	if (goingRight)
		additional.col = steps;
	else
		additional.col = -steps;

	if (location.row + additional.row >= 19 && goingUp)
		goingUp = false;
	if (location.row + additional.row <= 0 && !goingUp)
		goingUp = true;
	if (location.col + additional.col >= 39 && goingRight)	
		goingRight = false;
	if (location.col + additional.col <= 0 && !goingRight)
		goingRight = true;

	location += additional;
	changeDirection++;

}

void Monkey::printDetails() const
{
	cout << "The animal is a Monkey" << endl;
	Animal::printDetails();
}

void Monkey::move()
{
	if (changeDirection % 5 == 4) {
		goingRight = rand() % 2;
		goingUp = rand() % 2;
	}
}
