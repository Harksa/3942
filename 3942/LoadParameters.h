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
	 * \param width La largeur du GameObject
	 * \param height 
	 * \param textureID 
	 * \param numFrame 
	 * \param callbackId 
	 * \param animSpeed 
	 */
	LoadParameters(float x, float y, int width, int height, std::string textureID, int numFrame = 0, int callbackId = 0, int animSpeed = 0) :_x(x), _y(y), _width(width), _height(height), _textureID(std::move(textureID)), numFrame(numFrame), callbackID(callbackId), animSpeed(animSpeed) {}

	float getX() const {return _x;}
	float getY() const {return _y;}
	int getWidth() const {return _width;}
	int getHeight() const {return _height;}
	std::string getTextureID() const {return _textureID;}
	int getNumFrames() const {return numFrame;}
	int getCallbackID() const {return callbackID;}
	int getAnimSpeed() const {return animSpeed;}

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
	 * \brief La largeur du sprite du GameObject.
	 */
	int _width;

	/**
	 * \brief La hauteur du sprite du GameObject.
	 */
	int _height;

	/**
	 * \brief Le nom de la texture du GameObject.
	 */
	std::string _textureID;

	/**
	 * \brief Le nombre de frames totales du GameObject.
	 */
	int numFrame;

	/**
	 * \brief La réference à la fonction associé au GameObject, s'il en possède un.
	 */
	int callbackID;

	/**
	 * \brief La vitesse d'animation du GameObject, s'il en possède une.
	 */
	int animSpeed;
};

