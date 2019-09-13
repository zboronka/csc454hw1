#include<cstddef>
#include<iostream>
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
		cout << "Room full.\n";
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

bool Room::clean(bool pc) {
	if(cleanliness > CLEAN) {
		cleanliness--;
		for(auto o = occupants.begin(); o != occupants.end(); ) {
			if(pc) {
				(*o)->interact(this->get_pc(), CLEAN);
			}

			(*o)->react(cleanliness);
		}

		return true;
	}

	return false;
}

bool Room::dirty(bool pc) {
	if(cleanliness < DIRTY) {
		cleanliness++;
		for(auto o = occupants.begin(); o != occupants.end(); ) {
			if(pc) {
				(*o)->interact(this->get_pc(), DIRTY);
			}

			(*o)->react(cleanliness);
		}
		
		return true;
	}

	return false;
}

Character * Room::get_pc() {
	for(auto o = occupants.begin(); o != occupants.end(); ) {
		if((*o)->get_type() == PC) {
			return *o;
		}
	}

	return NULL;
}
