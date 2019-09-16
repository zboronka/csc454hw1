#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "character.hpp"

class Player : public Character {
	private:
		char respect;

	public:
		Player(char, Room *);
		char get_respect() { return respect; }
		void mod_respect(char m) { respect += m; }
};

#endif
