#include<iostream>
#include<string>

#include "room.hpp"
#include "player.hpp"
#include "nonplayer.hpp"
#include "animal.hpp"
#include "game.hpp"

using namespace std;

int main(int argc, char** argv) {
	//vector<Room *> r;
	//r.push_back(new Room(0,0));
	Game* game = new Game();
	game->init(argc, argv);
	game->play();
	//Room * r, * n;
	//n = new Room(1,3);
	//r = new Room(0,1);
	//r->set_neighbor(NORTH, n);
	//r->add_occupant(new Player(r));
//	
//	cout << pc->move(NORTH) << "\n";
	//pc->get_location()->add_occupant(pc);
//	cout << r->get_cleanliness() << "\n";
//
//	// Process command line arguments
//	if(argc > 1) {
//		for(int i = 0; i < atoi(argv[1]); i++) {
//			cout << atoi(argv[1]) << "\n";
//		}
//	}

	delete game;
	//delete r;
	//delete n;

	return 0; 
}
