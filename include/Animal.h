#pragma once
#include "Location.h"

class Animal {


protected:
	std::string name;
	Location location;
	bool canMove = true;
	bool goingUp;
	bool goingRight;

public:
	void printDetails() const;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual void step() = 0;
	void stop();
	void move();
	void turnVertically();
	void turnHorizontally();


};