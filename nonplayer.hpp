#ifndef NONPLAYER_HPP
#define NONPLAYER_HPP

#include "character.hpp"

class NonPlayer : public Character {
	public:
		NonPlayer(Room *);
		bool move(int);
};

#endif
