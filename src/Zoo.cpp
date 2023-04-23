#include "Zoo.h"
#include "Animal.h"
#include "Lion.h"
#include "Dog.h"
#include "Monkey.h"

using namespace std;

Zoo::Zoo()
{
	create("Simba", "Lion");
	create("Nala", "Lion");
	create ("Rex", "Dog");
	create ("Fido", "Dog");
	create ("George", "Monkey");
	create ("Curious George", "Monkey");

}

void Zoo::run()
{
	string command;
	while (true) {
		cin >> command;
		if (command == "stop") {
			int index;
			cin >> index;
			stop(index);
		}
		else if (command == "move") {
			int index;
			cin >> index;
			move(index);
		}
		else if (command == "create") {
			string name;
			string animalType;
			cin >> name >> animalType;
			create(name, animalType);
		}
		else if (command == "del") {
			int index;
			cin >> index;
			del(index);
		}
		else if (command == "delAll") {
			string typeOfAnimal;
			cin >> typeOfAnimal;
			delAll(typeOfAnimal);
		}
		else if (command == "help") {
			help();
		}
		else if (command == ".") {
			step();
		}
		else if (command == "exit"){
			break;
		}
		else {
			cout << "Invalid command" << endl;
		}
	}
}

void Zoo::stop(int index)
{
	listOfAnimals[index]->stop();
}
void Zoo::move(int index)
{
	listOfAnimals[index]->move();
}

void Zoo::create(string name, string animalType)
{
	Location loc;
	if (animalType == "Lion") {
		Lion* lion = new Lion(loc, name);
		listOfAnimals.push_back(lion);
		cout << "Lion created" << endl;
	}

	else if (animalType == "Dog") {
		Dog* dog = new Dog(loc, name);
		listOfAnimals.push_back(dog);
		cout << "Dog created" << endl;
	}

	else if (animalType == "Monkey") {
		Monkey* monkey = new Monkey(loc, name);
		listOfAnimals.push_back(monkey);
		cout << "Monkey created" << endl;
	}
	else {
		cout << "Invalid animal type" << endl;
	}
}

void Zoo::del(int index)
{
	delete listOfAnimals[index];
	listOfAnimals.erase(listOfAnimals.begin() + index);
}

void Zoo::delAll(string typeOfAnimal)
{
	for (int i = 0; i < listOfAnimals.size(); i++) {
		if (listOfAnimals[i]->getInitial() == typeOfAnimal[0]) {
			delete listOfAnimals[i];
			listOfAnimals.erase(listOfAnimals.begin() + i);
		}
	}
}

void Zoo::help()
{
	// explain every function

	cout << "stop: stops the animal from moving" << endl;
	cout << "move: lets the animal move" << endl;
	cout << "create: creates a new animal" << endl;
	cout << "del: deletes an animal" << endl;
	cout << "delAll: deletes all animals" << endl;
	cout << "help: displays all commands" << endl;
	cout << "step: moves all animals" << endl;

}

void Zoo::step()
{
	for (int i = 0; i < listOfAnimals.size(); i++) {
		listOfAnimals[i]->step();
	}
	draw();

}

void Zoo::draw() const
{
	// draw the zoo

	Location temp(0,0);
	bool isThereAnimal = false;

	if (listOfAnimals.size() == 0) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 40; j++) {
				cout << "-";
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			for (int k = 0; k < listOfAnimals.size(); k++) {
				if (listOfAnimals[k]->getLocation() == temp) {
					cout << listOfAnimals[k]->getInitial();
					isThereAnimal = true;
					break;
				}
			}
			if (!isThereAnimal) {
				cout << "-";
			}
			isThereAnimal = false;
			temp.col++;
		}
		temp.col = 0;
		temp.row++;

		cout << endl;
	}
}
