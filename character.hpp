#ifndef CHARACTER_HPP 
#define CHARACTER_HPP

#define PC 0
#define NPC 1
#define ANIMAL 2

class Room;
class Character {
	protected:
		char type;
		Room * location;
	public:
		char get_type() { return type; }
		Room * get_location() { return location; }

		virtual bool move (char);
		virtual void react(char) { return; }
		virtual void interact(Character *, char) { return; }
};

#endif
