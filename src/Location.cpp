#include "..\include\Location.h"

std::ostream& operator<<(std::ostream& os, const Location loc)
{
	os << "The location is: (" << loc.row << "," << loc.col << ")" << std::endl;
	return os;
}

Location::Location()
{
	row = rand() % 20;
	col = rand() % 40;
}

bool Location::operator==(const Location loc)
{
	return (loc.row == row && loc.col == col);
}

bool Location::operator!=(const Location loc)
{
	return (loc.row != row || loc.col != col);
}

Location Location::operator+(Location loc)
{
	loc.row += row;
	loc.col += col;
	return loc;
}

Location Location::operator+=(const Location loc)
{
	row += loc.row;
	col += loc.col;
	
	// Check if the location is out of bounds

	if (row > 19) {
		int extra = row - 19;
		row = 19 - extra;
	}

	if (row < 0) {
		int extra = 0 - row;
		row = 0 + extra;
	}

	if (col > 39) {
		int extra = col - 39;
		col = 39 - extra;
	}

	if (col < 0) {
		int extra = 0 - col;
		col = 0 + extra;
	}

	return *this;
}

