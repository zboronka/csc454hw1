#include "player.hpp"

Player::Player () {
	type = 0;
	respect = 40;
}

char Player::get_respect() {
	return respect;
}
