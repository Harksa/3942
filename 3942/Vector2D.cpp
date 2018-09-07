#include "Vector2D.h"

std::ostream& operator<<(std::ostream& stream, Vector2D& vector2D) {
	stream << "Vector2D (" << vector2D.x << "," << vector2D.y << ")";
	return stream;
}