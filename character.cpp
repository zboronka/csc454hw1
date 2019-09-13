#include "character.hpp"
#include "room.hpp"

bool Character::move(int direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor->add_occupant(this)) {
		location = neighbor;
		return true;
	}

	return false;
}
