#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "room.hpp"

class Game {
	private:
		vector<Room*> rooms;
	public:
		~Game();

		bool init(int, char**);
};

#endif
