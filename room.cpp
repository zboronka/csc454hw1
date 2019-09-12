#include<cstddef>
#include "room.hpp"

Room::Room (char i, char c) {
	name = i;
	cleanliness = c;
	neighbors[NORTH] = NULL;
	neighbors[SOUTH] = NULL;
	neighbors[EAST] = NULL;
	neighbors[WEST] = NULL;
}

bool Room::remove(Character * c) {
	for (int i = 0; i < MAX_OCCUPANTS; i++) {
		if(occupants[i]==c) {
			occupants[i]=NULL;
			return true;
		}
	}
	return false;
}
