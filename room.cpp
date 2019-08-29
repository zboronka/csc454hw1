#include "room.hpp"

Room::Room () {
	cleanliness = 0;
	north = 0;
	south = 0;
	east = 0;
	west = 0;
}

Room::Room (int c, Room * n, Room * s, Room * e, Room * w) {
	cleanliness = c;
	north = n;
	south = s;
	east = e;
	west = w;
}

int Room::get_cleanliness () {
	return cleanliness;
}
