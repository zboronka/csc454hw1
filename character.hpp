#ifndef CHARACTER_HPP 
#define CHARACTER_HPP

class Room;
class Character {
	protected:
		char type;
		Room * location;
	public:
		char get_type();
		Room * get_location();
};

#endif
