#ifndef CHARACTER_HPP 
#define CHARACTER_HPP

class Room;
class Character {
	protected:
		char type;
		Room * location;
	public:
		char get_type() { return type; }
		Room * get_location() { return location; }
		bool move (int);
};

#endif
