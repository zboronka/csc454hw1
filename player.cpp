#include "player.hpp"

Player::Player (char n, Room * r) {
	name = n;
	type = PC;
	respect = 40;
	location = r;
}
