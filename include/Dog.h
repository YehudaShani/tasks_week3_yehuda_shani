# pragma once
#include "Animal.h"
#include "Location.h"

using namespace std;

class Dog : public Animal {
	int goBackwards = 0;

	public:

	Dog (const Location& loc, std::string& str);

	char getInitial() const override;
	void step() override;
	void printDetails() const;
};