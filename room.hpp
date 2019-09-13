#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include "character.hpp"

#define MAX_OCCUPANTS 10
#define CARDINALS 4
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

using namespace std;

class Room {
	private:
		char name, cleanliness;
		Room * neighbors [CARDINALS];
		vector<Character*> occupants;
	public:
		Room (char, char);
		char get_cleanliness () { return cleanliness; }
		char get_name () { return name; }

		Room * get_neighbor(int direction) { return neighbors[direction]; }
		void set_neighbor(int direction, Room * location) { neighbors[direction] = location; }

		bool add_occupant(Character * c);
		bool remove_occupant(Character *);
};

#endif
