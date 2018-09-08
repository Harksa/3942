#pragma once
#include "Sprite.h"
#include "SDLGameObject.h"

/**
 * \brief Classe g�rant les balles tir�es
 */
class Bullet : public SDLGameObject {
public:
	Bullet() = default;
	~Bullet() = default;

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
	 * \brief D�termine si le Bullet courrant est utilisable ou non
	 * \return Vrai si le Bullet est disponible, faux sinon
	 */
	bool isAvailable() const { return is_available;}

	/**
	 * \brief Permet de mettre � jour la disponibilit� du Bullet
	 * \param value La nouvelle disponibilit� du Bullet
	 */
	void setAvailability(const bool value) {is_available = value;}

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param parameters Les param�tres du Bullet
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Mets � jour le voisin de ce Bullet
	 * \param new_bullet Le nouveau voisin
	 */
	void setNext(Bullet * new_bullet) {next = new_bullet;}

	/**
	 * \brief Retourne le voisin de ce Bullet
	 * \return Le voisin de ce Bullet
	 */
	Bullet * getNext() const {return next;}

private:
	/**
	 * \brief Le voisin de ce Bullet
	 */
	Bullet * next{};

	/**
	 * \brief Le bool�en d�terminant si ce Bullet est disponible ou non.
	 */
	bool is_available{};
};

