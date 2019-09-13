#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "character.hpp"
#include "player.hpp"

class Animal : public Character {
	public:
		Animal(Room *);
		bool move(char);
		void react(char);
		void interact(Player *, char);
};

#endif
