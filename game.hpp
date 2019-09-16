#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

#include "room.hpp"
#include "player.hpp"

class Game {
	private:
		vector<Room*> rooms;
		Player * pc;
		string state[3] = { "clean", "half-dirty", "dirty" };
		string cardinals[4] = { "north", "south", "east", "west" };

	public:
		~Game();

		bool init(int, char**);
		void play();
};

#endif
