#pragma once
#include "GameObject.h"

/**
 * \brief Classe g�rant les balles tir�es
 */
class Bullet : public GameObject {
public:
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
	virtual void onCollision();

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param pParameters Les param�tres du Bullet
	 */
	void load(const LoadParameters* pParameters) override;

	/**
	 * \brief D�termine si le Bullet courrant est utilisable ou non
	 * \return Vrai si le Bullet est disponible, faux sinon
	 */
	bool isAvailable() const;

	/**
	 * \brief Permet de mettre � jour la disponibilit� du Bullet
	 * \param pValue La nouvelle disponibilit� du Bullet
	 */
	void setAvailability(bool pValue);

	/**
	 * \brief Permet de d�terminer si le Bullet a besoin de changer de voisin ou non.
	 * \return vrai si il y a besoin, faux sinon.
	 */
	bool needChangeNext() const;

	/**
	 * \brief D�termine si le Bullet � besoin de changer de voisin ou non
	 * \param pValue La nouvelle valeur
	 */
	void setChangeNext(bool pValue);

	Bullet() = default;
	~Bullet();

	private:
	/**
	 * \brief Le bool�en d�terminant si ce Bullet est disponible ou non.
	 */
	bool is_available{false};

	/**
	 * \brief Bool�en d�terminant si ce Bullet a besoin de changer de voisin ou non
	 */
	bool need_change_next{false};
};

