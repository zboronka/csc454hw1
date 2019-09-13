#include <stdlib.h>
#include "room.hpp"
#include "animal.hpp"

Animal::Animal (Room * r) {
	location = r;
	type = 2;
}

bool Animal::move (char direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor->add_occupant(this)) {
		if(neighbor->get_cleanliness() < HALFCLEAN) {
			neighbor->clean();
		}

		location = neighbor;
		return true;
	}

	return false;
}

void Animal::react (char cleanliness) {
	if(cleanliness > HALFCLEAN) {
		char direction = rand() % 4;
		for( char i = 0; i < 4; i++) {
			if(this->move((direction + i) % 4)) {
				if (location->get_cleanliness() > HALFCLEAN) {
					location->clean();
				}

				return;
			}
		}

		delete this;
	}
}
