#pragma once
#include <ostream>

/**
 * \brief Gére les vecteurs ainsi que les calculs qui y sont liés
 */
class Vector2D {
public:
	Vector2D(float pX, float pY);

	/**
	 * \brief Retourne la taille du vecteur
	 * \return La taille du vecteur
	 */
	float length() const;

	/**
	 * \brief Normalise le vecteur
	 */
	void normalize();


	Vector2D operator +(const Vector2D& pV2) const;

	friend Vector2D& operator +=(Vector2D& pV1, Vector2D& pV2);

	Vector2D operator *(float pScalar) const;

	Vector2D operator *=(float pScalar);

	Vector2D operator -(const Vector2D& pV2) const;

	friend Vector2D& operator -=(Vector2D& pV1, const Vector2D pV2);

	Vector2D operator/(float pScalar) const;

	Vector2D& operator/=(float pScalar);

	/**
	 * \brief La valeur en X du vecteur
	 */
	float x;

	/**
	 * \brief La valeur en Y du vecteur
	 */
	float y;

	Vector2D();
	~Vector2D() = default;
};

std::ostream& operator<<(std::ostream& pStream, Vector2D& pVector2D);


