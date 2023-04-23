#pragma once
#include <iostream>

// Location class, represents grid of 20x40
struct Location { 
	int row;
	int col;


	friend std::ostream& operator<<(std::ostream& os, const Location loc);

	bool operator== (const Location loc);
	bool operator!= (const Location loc);
	Location operator+ (Location loc);
	Location operator+= (const Location loc);


public:
	Location();
	Location(int _row, int _col) : row(_row), col(_col) { };


};