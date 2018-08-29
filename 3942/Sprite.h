#pragma once
#include <string>
#include <utility>
#include "TextureManager.h"
#include "Vector2D.h"
#include "Game.h"

/**
 * \brief Gère le sprite des SDLGameObjects
 */
class Sprite {
public:
	Sprite(int width, int height, int numFrames, std::string textureID) : _width(width), _height(height), _numFrames(numFrames), _textureID(std::move(textureID)) {
		_currentFrame = 0;
		_currentRow = 0;
		_angle = 0;
	};

	/**
	 * \brief Définie la largeur du sprite, en pixel
	 */
	void setWidth(int width) { _width = width; }

	/**
	 * \brief Retourne la largeur du sprite
	 * \return La largeur du sprite
	 */
	int getWidth() const {return _width;}

	/**
	 * \brief Définie la hauteur du sprite, en pixel
	 */
	void setHeight(int height) { _height = height;}

	/**
	 * \brief Retourne la hauteur du sprite
	 * \return La hauteur du sprite
	 */
	int getHeight() const {return _height;}

	/**
	 * \brief Définie l'angle du sprite
	 */
	void setAngle(int angle) { _angle = angle;}
	int getAngle() const { return _angle;}

	void setNumFrames(int numFrames) {_numFrames = numFrames;}
	int getNumFrames() const {return _numFrames;}

	void setCurrentFrame(int frame) {_currentFrame = frame;}
	int getCurrentFrame() const {return _currentFrame;}

	void setTextureID(std::string textureID) {_textureID = textureID;}
	std::string getTextureID() const {return _textureID;}

	/**
	 * \brief Affiche le sprite dans la fenêtre SDL
	 */
	void draw(Vector2D position, Vector2D velocity);
private:
	
	int _width;
	int _height;

	int _angle;
	
	int _currentFrame;
	int _currentRow;
	int _numFrames;
	
	std::string _textureID;
};

