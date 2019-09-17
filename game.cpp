#include "game.hpp"

#include "player.hpp"
#include "nonplayer.hpp"
#include "animal.hpp"

#include <iostream>

using namespace std;

Game::~Game() {
	if(!rooms.empty()) {
		for ( auto r = rooms.begin(); r < rooms.end(); r++) {
			delete *r;
		}
	}
}

bool Game::init(int argc, char** argv) {
	int n, s, e, w, i, j, rcount, ccount, rindex, type;
	Character * newchar;
	Room * loc;

	if(argc > 1) {
		rcount = atoi(argv[1]);

		for(i = 0; i < rcount; i++) {
			rooms.push_back(new Room(i, atoi(argv[2+(i*5)])));
		}

		for(i = 0; i < rcount; i++) {
			if(6+i*5 >= argc) {
				cout << "Not enough neighbors for room " << i << "\n";
				return false;
			}

			n = atoi(argv[3+i*5]);
			s = atoi(argv[4+i*5]);
			e = atoi(argv[5+i*5]);
			w = atoi(argv[6+i*5]);

			rooms.at(i)->set_neighbor(NORTH, n>=0 ? rooms.at(n) : NULL);
			rooms.at(i)->set_neighbor(SOUTH, s>=0 ? rooms.at(s) : NULL);
			rooms.at(i)->set_neighbor(EAST, e>=0 ? rooms.at(e) : NULL);
			rooms.at(i)->set_neighbor(WEST, w>=0 ? rooms.at(w) : NULL);
		}

		for(j = 0; j < atoi(argv[2+i*5]); j++) {
			if(4+i*5+j*2 >= argc) {
				cout << "Not enough character parameters for " << j << "\n";
				return false;
			}

			type = atoi(argv[3+i*5+j*2]);
			rindex = atoi(argv[4+i*5+j*2]);
			loc = rooms.at(rindex);

			if(type == PC) {
				newchar = new Player(j, loc);
				pc = (Player *)newchar;
			}
			else if(type == NPC) {
				newchar = new NonPlayer(j, loc);
			}
			else if(type == ANIMAL) {
				newchar = new Animal(j, loc);
			}
			else {
				cout << "Character " << j+1 << " is of invalid type " << type << "\n";
				newchar = NULL;
				continue;
			}

			rooms.at(rindex)->add_occupant(newchar);
		}
	}
	else {
		int clean;
		cin >> rcount;

		for(i = 0; i < rcount; i++) {
			rooms.push_back(new Room(i));
		}
		for(i = 0; i < rcount; i++) {
			cin >> clean >> n >> s >> e >> w;
			
			rooms.at(i)->set_cleanliness(clean);
			rooms.at(i)->set_neighbor(NORTH, n>=0 ? rooms.at(n) : NULL);
			rooms.at(i)->set_neighbor(SOUTH, s>=0 ? rooms.at(s) : NULL);
			rooms.at(i)->set_neighbor(EAST, e>=0 ? rooms.at(e) : NULL);
			rooms.at(i)->set_neighbor(WEST, w>=0 ? rooms.at(w) : NULL);
		}
		
		cin >> ccount;

		for(i = 0; i < ccount; i++) {
			cin >> type >> rindex;
			loc = rooms.at(rindex);
			
			if(type == PC) {
				newchar = new Player(i, loc);
				pc = (Player *)newchar;
			}
			else if(type == NPC) {
				newchar = new NonPlayer(i, loc);
			}
			else if(type == ANIMAL) {
				newchar = new Animal(i, loc);
			}
			else {
				cout << "Character " << i << " is of invalid type " << type << "\n";
				newchar = NULL;
				continue;
			}

			rooms.at(rindex)->add_occupant(newchar);
		}
	}

	return true;
}

void Game::play () {
	for(string command; command != "exit"; cin >> command) {
		if(command == "look") {
			Room * location = pc->get_location();
			cout << "Room " << (int)location->get_name() << ", " << state[location->get_cleanliness()] << ", neighbors";
			for(int i = 0; i < CARDINALS; i++) {
				if(Room * r = location->get_neighbor(i)) {
					cout << " " << (int)r->get_name() << " to the " << cardinals[i];
				}
			}
			cout << ", contains:\n";

			cout << location->get_occupants();
		}
		if(command == "north") {
			cout << (pc->move(NORTH) ? "You leave towards the north.\n" : "You can't go north.\n");
		}
		if(command == "south") {
			cout << (pc->move(SOUTH) ? "You leave towards the south.\n" : "You can't go south.\n");
		}
		if(command == "east") {
			cout << (pc->move(EAST) ? "You leave towards the east.\n" : "You can't go east.\n");
		}
		if(command == "west") {
			cout << (pc->move(WEST) ? "You leave towards the west.\n" : "You can't go west.\n");
		}
		if(command == "clean") {
			if(!pc->get_location()->clean(true, pc->get_name())) {
				cout << "Room is already clean.\n";
			}
		}
		if(command == "dirty") {
			if(!pc->get_location()->dirty(true, pc->get_name())) {
				cout << "Room is already dirty.\n";
			}
		}
		int name;
		char cmd[20] = "";
		if(sscanf(command.c_str(), "%d:%s", &name, cmd)) {
			command = string(cmd);
			Character * target = pc->get_location()->get_occupant(name);
			if(target) { 	
				if(command == "clean") {
					if(!pc->get_location()->clean(3, name)) {
						cout << "Room is already clean.\n";
					}
				}
				if(command == "dirty") {
					if(!pc->get_location()->dirty(3, name)) {
						cout << "Room is already dirty.\n";
					}
				}
				if(command == "north") {
					cout << (int)target->get_name() << (target->move(NORTH) ? " leaves towards the north.\n" : " can't go north.\n");
				}
				if(command == "south") {
					cout << (int)target->get_name() << (target->move(SOUTH) ? " leaves towards the south.\n" : " can't go south.\n");
				}
				if(command == "east") {
					cout << (int)target->get_name() << (target->move(EAST) ? " leaves towards the east.\n" : " can't go east.\n");
				}
				if(command == "west") {
					cout << (int)target->get_name() << (target->move(WEST) ? " leaves towards the west.\n" : " can't go west.\n");
				}
			}
		}
		if(command == "help") {
			cout << "look               -- display information about the current room\n"
				 << "north              -- go to the north\n"
				 << "south              -- go to the south\n"
				 << "east               -- go to the east\n"
				 << "west               -- go to the west\n"
				 << "clean              -- clean the room\n"
				 << "dirty              -- dirty the room\n"
				 << "exit               -- exit the game\n"
				 << "<name>:<command>   -- make name do command\n";
		}
		if(pc->get_respect() >= WIN) {
			cout << "You win.\n";
			break;
		}
		if(pc->get_respect() <= LOSE) {
			cout << "You lose.\n";
			break;
		}
	}
}
