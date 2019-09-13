#include "room.hpp"
#include "nonplayer.hpp"

NonPlayer::NonPlayer (Room * r) {
	location = r;
	type = 1;
}

bool NonPlayer::move (int direction) {
	Room * neighbor = location->get_neighbor(direction);

	if(neighbor->get_cleanliness() >= 1 && neighbor->add_occupant(this)) {
		location = neighbor;
		return true;
	}

	return false;
}
