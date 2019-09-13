#include "player.hpp"

Player::Player (Room * r) {
	type = PC;
	respect = 40;
	location = r;
}
