#include "room.hpp"

Room::Room (int c, Room * n, Room * s, Room * e, Room * w) {
	cleanliness = c;
	north = n;
	south = s;
	east = e;
	west = w;
}
