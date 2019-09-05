#include "nonplayer.hpp"

NonPlayer::NonPlayer () {
	type = 1;
}

NonPlayer::NonPlayer (Room * r, char t) {
	location = r;
	type = t;
}
