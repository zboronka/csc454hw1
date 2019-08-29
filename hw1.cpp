#include<iostream>
#include<string>

#include "room.hpp"
#include "player.hpp"
#include "nonplayer.hpp"

using namespace std;

int main(int argc, char** argv) {
	Room * r;
	NonPlayer * npc;
	r = new Room();
	npc = new NonPlayer();
	
	printf("%d\n", npc->get_type());
//	cout << r->get_cleanliness() << "\n";
//
//	// Process command line arguments
//	if(argc > 1) {
//		for(int i = 0; i < atoi(argv[1]); i++) {
//			cout << atoi(argv[1]) << "\n";
//		}
//	}

	delete r;
	delete npc;

	return 0; 
}
