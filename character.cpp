#include "character.hpp"
#include "room.hpp"

#include <iostream>

bool Character::move(char direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor && neighbor->add_occupant(this)) {
		location->remove_occupant(this);
		location = neighbor;
		return true;
	}

	return false;
}
