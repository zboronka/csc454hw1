#include <stdlib.h>
#include <iostream>

#include "room.hpp"
#include "animal.hpp"

Animal::Animal (char n, Room * r) {
	name = n;
	location = r;
	type = ANIMAL;
}

bool Animal::move (char direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor && neighbor->add_occupant(this)) {
		if(neighbor->get_cleanliness() < HALFCLEAN) {
			neighbor->clean(false, -1);
		}

		location->remove_occupant(this);
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
				cout << (int)this->get_name() << " leaves towards the " << cardinals[(direction + i) % 4] << ".\n";
				if (location->get_cleanliness() > HALFCLEAN) {
					location->clean(false, -1);
				}

				return;
			}
		}

		cout << (int)name << " left the room or whatever. I guess.\n";
		location->remove_occupant(this);
		location->leave();
		delete this;
	}
}

void Animal::interact (Player * pc, char mod, char action) {
	if(action == CLEAN) {
		pc->mod_respect(mod);
		cout << (int)this->get_name() << " licks your face" << (mod > 1 ? " a lot" : "") << ". Respect is now " << (int)pc->get_respect() << ".\n";
	}
	else {
		pc->mod_respect(-mod);
		cout << (int)this->get_name() << " growls" << (mod > 1 ? " a lot" : "") << ". Respect is now " << (int)pc->get_respect() << ".\n";
	}
}
