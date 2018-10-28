#pragma once
#include <string>
#include <utility>

/**
 * \brief La classe donnant les paramètres aux GameObjects
 */
class LoadParameters {
public:
	
	/**
	 * \brief Constructeur de la classe LoadParameters
	 * \param pX La position x du GameObject
	 * \param pY La position en y du GameObject
	 * \param pTextureId 
	 * \param pCallbackId 
	 */
	LoadParameters(float pX, float pY, std::string pTextureId, int pCallbackId = 0);

	float getX() const;
	float getY() const;
	std::string getTextureID() const;
	int getCallbackID() const;

	~LoadParameters() = default;

private:
	/**
	 *\brief La position en X de départ du GameObject.
	 */
	float x;

	/**
	 * \brief La position en Y de départ du GameObject.
	 */
	float y;

	/**
	 * \brief Le nom de la texture du GameObject.
	 */
	std::string texture_id;

	/**
	 * \brief La réference à la fonction associé au GameObject, s'il en possède un.
	 */
	int callback_id;

};

inline LoadParameters::LoadParameters(float x, float y, std::string textureID, int callbackId): 
	x{x}, y{y}, texture_id{ std::move(textureID) }, callback_id{ callbackId} {}

inline float LoadParameters::getX() const { return x; }

inline float LoadParameters::getY() const { return y; }

inline std::string LoadParameters::getTextureID() const { return texture_id; }

inline int LoadParameters::getCallbackID() const { return callback_id; }
