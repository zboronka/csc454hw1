#ifndef ROOM_HPP
#define ROOM_HPP

class Room {
	private:
		int cleanliness;
		Room * north, * south, * east, * west;
	public:
		Room (int, Room*, Room*, Room*, Room*);
		int get_cleanliness () { return cleanliness; }
};

#endif
