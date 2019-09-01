#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "character.hpp"

class Player : public Character {
	private:
		char respect;

	public:
		Player(Room *);
		Player();
		char get_respect();
};

#endif
