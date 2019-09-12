#include<iostream>
#include<string>

#include "room.hpp"
#include "player.hpp"
#include "nonplayer.hpp"

using namespace std;

int main(int argc, char** argv) {
	Room * r, * n;
	Player * pc;
	n = new Room(1,3);
	r = new Room(0,1);
	pc = new Player(r);
	r->set_neighbor(NORTH, n);
	
	printf("%d\n", pc->get_respect());
	pc->move(NORTH);
	cout << "Occupants Begin=" <<  n->get() << "\n";
	pc->get_location()->add(pc);
	cout << "Occupants Begin=" <<  n->get() << "\n";
	pc->get_location()->remove(pc);
	cout << "Occupants Begin=" <<  n->get() << "\n";
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
