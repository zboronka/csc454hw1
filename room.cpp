#include "room.hpp"

Room::Room (char i, char c, Room * n, Room * s, Room * e, Room * w) {
	name = i;
	cleanliness = c;
	neighbors[NORTH] = n;
	neighbors[SOUTH] = s;
	neighbors[EAST] = e;
	neighbors[WEST] = w;
}
