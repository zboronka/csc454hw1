#include <stdlib.h>
#include "room.hpp"
#include "animal.hpp"

Animal::Animal (Room * r) {
	location = r;
	type = ANIMAL;
}

bool Animal::move (char direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor->add_occupant(this)) {
		if(neighbor->get_cleanliness() < HALFCLEAN) {
			neighbor->clean(neighbor->get_pc());
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
					location->clean(location->get_pc());
				}

				return;
			}
		}

		delete this;
	}
}

void Animal::interact (Player * pc, char action) {
	if(action == CLEAN) {
		pc->mod_respect(1);
	}
	else {
		pc->mod_respect(-1);
	}
}
