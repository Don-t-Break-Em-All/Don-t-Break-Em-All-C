#include "collision.h"

int collidesBottom(Vector2 object1, Vector2 object2) {
	return object1.x + 8 >= object2.x && object1.y + 8 >= object2.y;
}

int collidesRight(Vector2 object1, Vector2 object2) {
	return object1.x + 8 >= object2.x;
}