#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "character.hpp"

class Player : public Character {
	private:
		char respect;

	public:
		Player();
		char get_respect();
};

#endif
