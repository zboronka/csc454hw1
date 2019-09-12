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

bool Room::add(Character * c) {
	occupants.push_back(c);
	return true;
}

bool Room::remove(Character * c) {
	for(auto o = occupants.begin(); o != occupants.end(); ) {
		if(*o == c) {
			occupants.erase(o);
			return true;
		}
	}
	return false;
}
