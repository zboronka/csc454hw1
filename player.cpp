#include "player.hpp"

Player::Player () {
	type = 0;
	respect = 40;
}

Player::Player (Room * r) {
	type = 0;
	respect = 40;
	location = r;
}

char Player::get_respect() {
	return respect;
}
