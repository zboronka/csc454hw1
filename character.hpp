#ifndef CHARACTER_HPP 
#define CHARACTER_HPP

#define PC 0
#define ANIMAL 1
#define NPC 2

class Room;
class Character {
	protected:
		char type;
		Room * location;
		char name;

	public:
		char get_type() { return type; }
		Room * get_location() { return location; }

		char get_name() { return name; }

		virtual bool move (char);
		virtual void react(char) { return; }
		virtual void interact(Character *, char) { return; }
};

#endif
