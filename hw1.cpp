#include<iostream>
#include<string>

#include "room.hpp"
#include "player.hpp"
#include "nonplayer.hpp"
#include "animal.hpp"
#include "game.hpp"

using namespace std;

int main(int argc, char** argv) {
	Game* game = new Game();
	game->init(argc, argv);
	game->play();
	delete game;

	return 0; 
}
