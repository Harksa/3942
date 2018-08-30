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
	LoadParameters(float x, float y, std::string textureID, int callbackId = 0) :_x(x), _y(y), _textureID(std::move(textureID)), callbackID(callbackId) {}

	float getX() const {return _x;}
	float getY() const {return _y;}
	std::string getTextureID() const {return _textureID;}
	int getCallbackID() const {return callbackID;}

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

