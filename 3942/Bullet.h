#pragma once
#include "Sprite.h"
#include "GameObject.h"

/**
 * \brief Classe g�rant les balles tir�es
 */
class Bullet : public GameObject {
public:
	Bullet() = default;
	~Bullet();

	/**
	 * \brief Affiche le Bullet � l'�cran
	 */
	void draw() override;

	/**
	 * \brief Mets � jour le Bullet
	 */
	void update() override;

	/**
	 * \brief Nettoie le Bullet de la m�moire
	 */
	void clean() override;

	/**
	 * \brief Actions effecttu�es lorsque le Bullet rentre en collision avec un autre objet.
	 */
	void onCollision() override;

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param parameters Les param�tres du Bullet
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief D�termine si le Bullet courrant est utilisable ou non
	 * \return Vrai si le Bullet est disponible, faux sinon
	 */
	bool isAvailable() const { return is_available;}

	/**
	 * \brief Permet de mettre � jour la disponibilit� du Bullet
	 * \param value La nouvelle disponibilit� du Bullet
	 */
	void setAvailability(const bool value) {is_available = value;}

private:
	/**
	 * \brief Le bool�en d�terminant si ce Bullet est disponible ou non.
	 */
	bool is_available{false};
};

