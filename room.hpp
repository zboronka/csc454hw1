#ifndef ROOM_HPP
#define ROOM_HPP

#include "character.hpp"

#define MAX_OCCUPANTS 10
#define CARDINALS 4
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

class Room {
	private:
		char name, cleanliness;
		Room * neighbors [CARDINALS];
		Character * occupants [MAX_OCCUPANTS];
	public:
		Room (char, char, Room*, Room*, Room*, Room*);
		char get_cleanliness () { return cleanliness; }
		char get_name () { return name; }
};

#endif
