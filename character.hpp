#ifndef CHARACTER_HPP 
#define CHARACTER_HPP

#include "room.hpp"

class Character {
	protected:
		char type;
		Room * location;
	public:
		char get_type();
};

#endif
