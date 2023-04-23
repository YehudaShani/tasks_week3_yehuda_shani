#include "../include/Lion.h"
#include "../include/Animal.h"

using namespace std;

Lion::Lion(const Location& loc, std::string& str)
{
	name = str;
	location = loc;
	goingUp = rand() % 2;
	goingRight = rand() % 2;

}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::step()
{
	if (canMove) {
		Location additional(0, 2);
		if (!goingRight)
			additional.col = -2;
		if (location.col <= 1 && !goingRight)
			goingRight = true;
		if (location.col + additional.col >= 38 && goingRight)
			goingRight = false;
		location += additional;
		
	}
}

void Lion::printDetails() const
{
	cout << "The animal is a Lion" << endl;
	Animal::printDetails();


}
