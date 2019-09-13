#include "game.hpp"

#include <iostream>

using namespace std;

Game::~Game() {
	if(!rooms.empty()) {
		for ( auto r = rooms.begin(); r != rooms.end(); ) {
			delete *r;
			rooms.erase(r);
		}
	}
}

bool Game::init(int argc, char** argv) {
	if(argc > 1) {
		for(int i = 0; i < atoi(argv[1]); i++) {
			rooms.push_back(new Room(i, atoi(argv[2+(i*5)])));
		}
		
		int n, s, e, w;

		for(int i = 0; i < atoi(argv[1]); i++) {
			n = atoi(argv[3+(i*5)]);
			s = atoi(argv[4+(i*5)]);
			e = atoi(argv[5+(i*5)]);
			w = atoi(argv[6+(i*5)]);
			rooms.at(i)->set_neighbor(NORTH, n>=0 ? rooms.at(n) : NULL);
			cout << (int)rooms.at(i)->get_neighbor(NORTH)->get_cleanliness() << "\n";
		}
	}

	return true;
}
