#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief Repr�sente un objet poss�dant une animation mais n'interaggissant pas avec le joueur.
 */
class AnimatedGraphic :
	public GameObject {
public:
	/**
	 * \brief Mets � jour l'animatedGraphic
	 */
	void update() override;

	/**
	 * \brief Affiche l'AnimatedGraphic
	 */
	void draw() override;

	/**
	 * \brief Charge les informations de l'AnimatedGraphic
	 * \param parameters Les param�tres de l'AnimatedGraphic
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Nettoie l'AnimatedGraphic
	 */
	void clean() override;

	AnimatedGraphic() = default;
	~AnimatedGraphic() = default;
};

/**
 * \brief Le cr�ateur de L'AnimatedGraphic
 */
class AnimatedGraphicCreator : public BaseCreator {
	/**
	 * \brief Cr�er un animatedGraphic
	 * \return un AnimatedGraphic
	 */
	GameObject* createGameObject() const override {
		return new AnimatedGraphic();
	}
};