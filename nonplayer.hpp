#ifndef NONPLAYER_HPP
#define NONPLAYER_HPP

#include "character.hpp"
#include "player.hpp"

class NonPlayer : public Character {
	public:
		NonPlayer(char, Room *);
		bool move(char);
		void react(char);
		void interact(Player *, char, char);
};

#endif
