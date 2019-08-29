#include<iostream>
#include<string>

#include "room.hpp"

using namespace std;

int main(int argc, char** argv) {
	Room *r;
	r = new Room();
	
	cout << r->get_cleanliness() << "\n";

	// Process command line arguments
	if(argc > 1) {
		for(int i = 0; i < atoi(argv[1]); i++) {
			cout << atoi(argv[1]) << "\n";
		}
	}

	//while(

	return 0; 
}
