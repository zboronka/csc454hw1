#include "character.hpp"
#include "room.hpp"
#include <iostream>

using namespace std;
bool Character::move(int direction) {
	cout << "NORTH      =" << location->get_neighbor(direction) << "\n"
		 << "CURRENT    =" << location << "\n";
	location = location->get_neighbor(direction);
	cout << "NEW CURRENT=" << location << "\n";
	return true;
}
