#pragma once

#include "Animal.h"

class Lion : public Animal {
public:
	Lion(const Location& loc, std::string& str);

	char getInitial() const override;
	void step() override;
	void printDetails() const;

};