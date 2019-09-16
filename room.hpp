#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <string>

#include "character.hpp"

#define MAX_OCCUPANTS 10

#define CARDINALS 4
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

#define CLEAN 0
#define HALFCLEAN 1
#define DIRTY 2

using namespace std;

class Room {
	private:
		char name, cleanliness;
		Room * neighbors [CARDINALS];
		vector<Character*> occupants;
		string types[3] = { "PC", "animal", "human" };

	public:
		Room (char, char);
		Room (char);
		~Room();

		char get_cleanliness () { return cleanliness; }
		void set_cleanliness (char c) { cleanliness = c; }
		char get_name () { return name; }

		Room * get_neighbor(char direction) { return neighbors[direction]; }
		void set_neighbor(char direction, Room * location) { neighbors[direction] = location; }

		bool add_occupant(Character *);
		bool remove_occupant(Character *);

		bool clean(bool);
		bool dirty(bool);

		Character * get_pc();

		string get_occupants();
};

#endif
