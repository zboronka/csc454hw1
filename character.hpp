#ifndef CHARACTER_HPP 
#define CHARACTER_HPP

#define PC 0
#define ANIMAL 1
#define NPC 2

#include <string>

class Room;
class Player;
class Character {
	protected:
		char type;
		Room * location;
		char name;
		std::string cardinals[4] = { "north", "south", "east", "west" };

	public:
		char get_type() { return type; }
		Room * get_location() { return location; }

		char get_name() { return name; }

		virtual bool move (char);
		virtual void react(char) { return; }
		virtual void interact(Player *, char, char) { return; }
};

#endif
