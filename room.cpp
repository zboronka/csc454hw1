#include "room.hpp"

Room::Room (int i, int c, Room * n, Room * s, Room * e, Room * w) {
	name = i;
	cleanliness = c;
	north = n;
	south = s;
	east = e;
	west = w;
}

int Room::get_cleanliness () {
	return cleanliness;
}
