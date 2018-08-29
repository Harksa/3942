#pragma once
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief Repr�sente un objet poss�dant une animation mais n'interaggissant pas avec le joueur.
 */
class AnimatedGraphic :
	public SDLGameObject {
public:
	AnimatedGraphic() {}

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

private:
	/**
	 * \brief La vitesse d'animation
	 */
	int animSpeed;
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