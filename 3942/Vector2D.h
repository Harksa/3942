#pragma once
#include <cmath>
#include <ostream>

/**
 * \brief Gére les vecteurs ainsi que les calculs qui y sont liés
 */
class Vector2D {
public:
	Vector2D(float x, float y) : x{x}, y{y} {}
	Vector2D() : x{0}, y{0} {}
	~Vector2D() = default;

	/**
	 * \brief Retourne la taille du vecteur
	 * \return La taille du vecteur
	 */
	float length() const { return sqrt(x * x + y * y); }

	/**
	 * \brief Normalise le vecteur
	 */
	void normalize() {
		const float l = length();
		if(l > 0) {
			(*this) *= 1 / l;
		}
	}


	Vector2D operator + (const Vector2D &v2) const {
		return {x + v2.x, y + v2.y};
	}

	friend Vector2D & operator += (Vector2D& v1, Vector2D& v2) {
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	Vector2D operator * (float scalar) const {
		return {x * scalar, y *scalar};
	}

	Vector2D operator *= (float scalar) {
		x *= scalar, y *= scalar;
		return *this;
	}

	Vector2D operator - (const Vector2D & v2) const {
		return {x - v2.x, y - v2.y};
	}

	friend Vector2D& operator -= (Vector2D &v1, const Vector2D v2) {
		v1.x -= v2.x;
		v1.y -= v2.y;

		return v1;
	}

	Vector2D operator/ (float scalar) const {
		return Vector2D(x / scalar, y / scalar);
	}

	Vector2D& operator/= (float scalar) {
		x /= scalar;
		y /= scalar;

		return *this;
	}
	
	/**
	 * \brief La valeur en X du vecteur
	 */
	float x;

	/**
	 * \brief La valeur en Y du vecteur
	 */
	float y;		
};

std::ostream& operator<<(std::ostream& stream, Vector2D& vector2D);


