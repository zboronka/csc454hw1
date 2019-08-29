#ifndef ROOM_HPP
#define ROOM_HPP

class Room {
	private:
		int cleanliness;
		Room * north, * south, * east, * west;
	public:
		Room ();
		Room (int, Room*, Room*, Room*, Room*);
		int get_cleanliness ();
};

#endif
