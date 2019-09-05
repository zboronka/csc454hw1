#ifndef ROOM_HPP
#define ROOM_HPP

#include "character.hpp"

class Room {
	private:
		int name, cleanliness;
		Room * north, * south, * east, * west;
		Character occupants [10];
	public:
		Room (int, int, Room*, Room*, Room*, Room*);
		int get_cleanliness ();
};

#endif
