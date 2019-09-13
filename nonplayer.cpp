#include <stdlib.h>
#include "room.hpp"
#include "nonplayer.hpp"

using namespace std;

NonPlayer::NonPlayer (Room * r) {
	location = r;
	type = 1;
}

bool NonPlayer::move (char direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor->add_occupant(this)) {
		if(neighbor->get_cleanliness() > 1) {
			neighbor->dirty();
		}

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
					location->dirty();
				}

				return;
			}
		}

		delete this;
	}
}
