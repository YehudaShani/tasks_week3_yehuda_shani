#pragma once
# include <vector>
# include "Animal.h"

using namespace std;

class Zoo {
	vector<Animal*> listOfAnimals;

	void stop (int index);
	void move (int index);
	void create (string name, string typeOfAnimal);
	void del (int index);
	void delAll (string typeOfAnimal);
	void help ();
	void step();
	void draw() const;

public:

	Zoo();
	void run();


};