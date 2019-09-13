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

bool Room::add_occupant(Character * c) {
	if(occupants.size() == MAX_OCCUPANTS) {
		return false;
	}

	for(auto o = occupants.begin(); o != occupants.end(); ) {
		if(*o ==c) {
			return false;
		}
	}

	occupants.push_back(c);
	return true;
}

bool Room::remove_occupant(Character * c) {
	for(auto o = occupants.begin(); o != occupants.end(); ) {
		if(*o == c) {
			occupants.erase(o);
			return true;
		}
	}

	return false;
}
