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
	 * \param x La position x du GameObject
	 * \param y La position en y du GameObject
	 * \param textureID 
	 * \param callbackId 
	 */
	LoadParameters(float x, float y, std::string textureID, int callbackId = 0);

	float getX() const;
	float getY() const;
	std::string getTextureID() const;
	int getCallbackID() const;

	~LoadParameters() = default;

private:
	/**
	 *\brief La position en X de départ du GameObject.
	 */
	float _x;

	/**
	 * \brief La position en Y de départ du GameObject.
	 */
	float _y;

	/**
	 * \brief Le nom de la texture du GameObject.
	 */
	std::string _textureID;

	/**
	 * \brief La réference à la fonction associé au GameObject, s'il en possède un.
	 */
	int callbackID;

};

inline LoadParameters::LoadParameters(float x, float y, std::string textureID, int callbackId): 
	_x{x}, _y{y}, _textureID{ std::move(textureID) }, callbackID{ callbackId} {}

inline float LoadParameters::getX() const { return _x; }

inline float LoadParameters::getY() const { return _y; }

inline std::string LoadParameters::getTextureID() const { return _textureID; }

inline int LoadParameters::getCallbackID() const { return callbackID; }
