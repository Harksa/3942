#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief Représente un objet possédant une animation mais n'interaggissant pas avec le joueur.
 */
class AnimatedGraphic :
	public GameObject {
public:
	AnimatedGraphic() {}

	/**
	 * \brief Mets à jour l'animatedGraphic
	 */
	void update() override;

	/**
	 * \brief Affiche l'AnimatedGraphic
	 */
	void draw() override;

	/**
	 * \brief Charge les informations de l'AnimatedGraphic
	 * \param parameters Les paramètres de l'AnimatedGraphic
	 */
	void load(const LoadParameters* parameters) override;

	void onCollision() override {}

	void clean() override {};

private:
	/**
	 * \brief La vitesse d'animation
	 */
	int animSpeed;
};

/**
 * \brief Le créateur de L'AnimatedGraphic
 */
class AnimatedGraphicCreator : public BaseCreator {
	/**
	 * \brief Créer un animatedGraphic
	 * \return un AnimatedGraphic
	 */
	GameObject* createGameObject() const override {
		return new AnimatedGraphic();
	}
};