#include <stdlib.h>
#include "room.hpp"
#include "nonplayer.hpp"

using namespace std;

NonPlayer::NonPlayer (char n, Room * r) {
	name = n;
	location = r;
	type = NPC;
}

bool NonPlayer::move (char direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor && neighbor->add_occupant(this)) {
		if(neighbor->get_cleanliness() > 1) {
			neighbor->dirty(neighbor->get_pc());
		}

		location->remove_occupant(this);
		location = neighbor;
		return true;
	}

	return false;
}

void NonPlayer::react (char cleanliness) {
	if(cleanliness < 1) {
		char direction = rand() % 4;
		for( char i = 0; i < 4; i++) {
			if(this->move((direction + i) % 4)) {
				if (location->get_cleanliness() < 1) {
					location->dirty(location->get_pc());
				}

				return;
			}
		}

		delete this;
	}
}

void NonPlayer::interact (Player * pc, char action) {
	if(action == DIRTY) {
		pc->mod_respect(1);
	}
	else {
		pc->mod_respect(-1);
	}
}
