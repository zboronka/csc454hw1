#include "character.hpp"
#include "room.hpp"
#include <iostream>

using namespace std;
bool Character::move(int direction) {
	cout << location->get_neighbor(direction);
	return true;
}
