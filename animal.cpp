#include "room.hpp"
#include "animal.hpp"

Animal::Animal (Room * r) {
	location = r;
	type = 2;
}

bool Animal::move (int direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor->get_cleanliness() <= 1 && neighbor->add_occupant(this)) {
		location = neighbor;
		return true;
	}

	return false;
}
