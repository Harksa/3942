#pragma once
#include <ostream>

/**
 * \brief Gére les vecteurs ainsi que les calculs qui y sont liés
 */
class Vector2D {
public:
	Vector2D(float x, float y);
	Vector2D();
	~Vector2D() = default;

	/**
	 * \brief Retourne la taille du vecteur
	 * \return La taille du vecteur
	 */
	float length() const;

	/**
	 * \brief Normalise le vecteur
	 */
	void normalize();


	Vector2D operator +(const Vector2D& v2) const;

	friend Vector2D& operator +=(Vector2D& v1, Vector2D& v2);

	Vector2D operator *(float scalar) const;

	Vector2D operator *=(float scalar);

	Vector2D operator -(const Vector2D& v2) const;

	friend Vector2D& operator -=(Vector2D& v1, const Vector2D v2);

	Vector2D operator/(float scalar) const;

	Vector2D& operator/=(float scalar);

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


