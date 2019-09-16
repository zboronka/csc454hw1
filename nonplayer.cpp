#include <stdlib.h>
#include <iostream>

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
			neighbor->dirty(false, -1);
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
				cout << (int)this->get_name() << " leaves towards the " << cardinals[(direction + i) % 4] << ".\n";
				if (location->get_cleanliness() < 1) {
					location->dirty(false, -1);
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

void NonPlayer::interact (Player * pc, char mod, char action) {
	if(action == DIRTY) {
		pc->mod_respect(mod);
		cout << (int)this->get_name() << " smiles" << (mod > 1 ? " a lot" : "") << ". Respect is now " << (int)pc->get_respect() << ".\n";
	}
	else {
		pc->mod_respect(-mod);
		cout << (int)this->get_name() << " grumbles" << (mod > 1 ? " a lot" : "") << ". Respect is now " << (int)pc->get_respect() << ".\n";
	}
}
