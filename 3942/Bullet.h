#pragma once
#include "Sprite.h"
#include "SDLGameObject.h"

/**
 * \brief Classe gérant les balles tirées
 */
class Bullet : public SDLGameObject {
public:
	Bullet() = default;
	~Bullet() = default;

	/**
	 * \brief Affiche le Bullet à l'écran
	 */
	void draw() override;

	/**
	 * \brief Mets à jour le Bullet
	 */
	void update() override;

	/**
	 * \brief Nettoie le Bullet de la mémoire
	 */
	void clean() override;

	/**
	 * \brief Détermine si le Bullet courrant est utilisable ou non
	 * \return Vrai si le Bullet est disponible, faux sinon
	 */
	bool isAvailable() const { return is_available;}

	/**
	 * \brief Permet de mettre à jour la disponibilité du Bullet
	 * \param value La nouvelle disponibilité du Bullet
	 */
	void setAvailability(const bool value) {is_available = value;}

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param parameters Les paramètres du Bullet
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Mets à jour le voisin de ce Bullet
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
	 * \brief Le booléen déterminant si ce Bullet est disponible ou non.
	 */
	bool is_available{};
};

