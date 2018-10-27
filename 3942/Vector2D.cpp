#include "Vector2D.h"

Vector2D::Vector2D(float x, float y): x{x}, y{y} {}

Vector2D::Vector2D(): x{0}, y{0} {}

float Vector2D::length() const { return sqrt(x * x + y * y); }

void Vector2D::normalize() {
	const float l = length();
	if (l > 0) {
		(*this) *= 1 / l;
	}
}

Vector2D Vector2D::operator+(const Vector2D& v2) const {
	return {x + v2.x, y + v2.y};
}

Vector2D& operator+=(Vector2D& v1, Vector2D& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

Vector2D Vector2D::operator*(float scalar) const {
	return {x * scalar, y * scalar};
}

Vector2D Vector2D::operator*=(float scalar) {
	x *= scalar, y *= scalar;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const {
	return {x - v2.x, y - v2.y};
}

Vector2D& operator-=(Vector2D& v1, const Vector2D v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;

	return v1;
}

Vector2D Vector2D::operator/(float scalar) const {
	return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;

	return *this;
}

std::ostream& operator<<(std::ostream& stream, Vector2D& vector2D) {
	stream << "Vector2D (" << vector2D.x << "," << vector2D.y << ")";
	return stream;
}
