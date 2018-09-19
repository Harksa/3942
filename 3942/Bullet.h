#pragma once
#include "Sprite.h"
#include "GameObject.h"

/**
 * \brief Classe gérant les balles tirées
 */
class Bullet : public GameObject {
public:
	Bullet() = default;
	~Bullet();

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
	 * \brief Actions effecttuées lorsque le Bullet rentre en collision avec un autre objet.
	 */
	void onCollision() override;

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param parameters Les paramètres du Bullet
	 */
	void load(const LoadParameters* parameters) override;

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

private:
	/**
	 * \brief Le booléen déterminant si ce Bullet est disponible ou non.
	 */
	bool is_available{false};
};

