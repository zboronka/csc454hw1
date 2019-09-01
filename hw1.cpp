#include<iostream>
#include<string>

#include "room.hpp"
#include "player.hpp"
#include "nonplayer.hpp"

using namespace std;

int main(int argc, char** argv) {
	Room * r;
	Player * pc;
	r = new Room();
	pc = new Player(r);
	
	printf("%d\n", pc->get_respect());
//	cout << r->get_cleanliness() << "\n";
//
//	// Process command line arguments
//	if(argc > 1) {
//		for(int i = 0; i < atoi(argv[1]); i++) {
//			cout << atoi(argv[1]) << "\n";
//		}
//	}

	delete r;
	delete pc;

	return 0; 
}
