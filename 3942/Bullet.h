#pragma once
#include "GameObject.h"

/**
 * \brief Classe gérant les balles tirées
 */
class Bullet : public GameObject {
public:
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
	virtual void onCollision();

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param parameters Les paramètres du Bullet
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Détermine si le Bullet courrant est utilisable ou non
	 * \return Vrai si le Bullet est disponible, faux sinon
	 */
	bool isAvailable() const;

	/**
	 * \brief Permet de mettre à jour la disponibilité du Bullet
	 * \param value La nouvelle disponibilité du Bullet
	 */
	void setAvailability(const bool value);

	/**
	 * \brief Permet de déterminer si le Bullet a besoin de changer de voisin ou non.
	 * \return vrai si il y a besoin, faux sinon.
	 */
	bool needChangeNext() const;

	/**
	 * \brief Détermine si le Bullet à besoin de changer de voisin ou non
	 * \param value La nouvelle valeur
	 */
	void setChangeNext(bool value);

	Bullet() = default;
	~Bullet();

	private:
	/**
	 * \brief Le booléen déterminant si ce Bullet est disponible ou non.
	 */
	bool is_available{false};

	/**
	 * \brief Booléen déterminant si ce Bullet a besoin de changer de voisin ou non
	 */
	bool need_change_next{false};
};

