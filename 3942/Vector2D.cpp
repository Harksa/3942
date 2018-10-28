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

Vector2D Vector2D::operator+(const Vector2D& pV2) const {
	return {x + pV2.x, y + pV2.y};
}

Vector2D& operator+=(Vector2D& pV1, Vector2D& pV2) {
	pV1.x += pV2.x;
	pV1.y += pV2.y;
	return pV1;
}

Vector2D Vector2D::operator*(const float pScalar) const {
	return {x * pScalar, y * pScalar};
}

Vector2D Vector2D::operator*=(const float pScalar) {
	x *= pScalar, y *= pScalar;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& pV2) const {
	return {x - pV2.x, y - pV2.y};
}

Vector2D& operator-=(Vector2D& pV1, const Vector2D pV2) {
	pV1.x -= pV2.x;
	pV1.y -= pV2.y;

	return pV1;
}

Vector2D Vector2D::operator/(const float pScalar) const {
	return Vector2D(x / pScalar, y / pScalar);
}

Vector2D& Vector2D::operator/=(const float pScalar) {
	x /= pScalar;
	y /= pScalar;

	return *this;
}

std::ostream& operator<<(std::ostream& pStream, Vector2D& pVector2D) {
	pStream << "Vector2D (" << pVector2D.x << "," << pVector2D.y << ")";
	return pStream;
}
