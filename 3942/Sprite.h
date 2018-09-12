#pragma once
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"

/**
 * \brief G�re le sprite des SDLGameObjects
 */
class Sprite {
public:
	/**
	 * \brief Cr�er un sprite en fonction de l'ID rentr� en param�tre.
	 * Les informations sont cherch�s dans le texture manager gr�ce � ce dernier.
	 * \param textureID L'ID de la texture
	 */
	Sprite(const std::string& textureID) : _textureID(textureID){
		texture_informations * texture = TextureManager::Instance()->getTextureInformationsFromID(textureID);
		_width = texture->width;
		_height = texture->height;
		_numFrames = texture->numFrames;
		_animSpeed = texture->animSpeed;
		_currentFrame = 0;
		_currentRow = 0;
		_angle = 0;
	}

	/**
	 * \brief D�finie la largeur du sprite, en pixel
	 */
	void setWidth(int width) { _width = width; }

	/**
	 * \brief Retourne la largeur du sprite
	 * \return La largeur du sprite
	 */
	int getWidth() const {return _width;}

	/**
	 * \brief D�finie la hauteur du sprite, en pixel
	 */
	void setHeight(int height) { _height = height;}

	/**
	 * \brief Retourne la hauteur du sprite
	 * \return La hauteur du sprite
	 */
	int getHeight() const {return _height;}

	/**
	 * \brief D�finie l'angle du sprite
	 * \param angle Le nouvel angle
	 */
	void setAngle(float angle) { _angle = angle;}

	/**
	 * \brief Retourne l'angle du sprite.
	 * \return L'angle du sprite
	 */
	float getAngle() const { return _angle;}

	/**
	 * \brief D�finie le nombre de frames du sprite
	 * \param numFrames Le nouveau nombre de frames
	 */
	void setNumFrames(int numFrames) {_numFrames = numFrames;}

	/**
	 * \brief Retourne le nombre de frame du sprite
	 * \return Le nombre de frames du sprite
	 */
	int getNumFrames() const {return _numFrames;}

	/**
	 * \brief D�finie la frame actuelle du sprite
	 * \param frame Le nouveau frame
	 */
	void setCurrentFrame(int frame) {_currentFrame = frame;}

	/**
	 * \brief Retourne la frame actuelle du sprite
	 * \return La frame actuelle du sprite
	 */
	int getCurrentFrame() const {return _currentFrame;}

	/**
	 * \brief D�finie l'ID de la texture du frame.
	 * \param textureID L'ID de la nouvelle texture
	 */
	void setTextureID(const std::string& textureID) {
		_textureID = textureID;
		texture_informations * texture = TextureManager::Instance()->getTextureInformationsFromID(_textureID);
		_width = texture->width;
		_height = texture->height;
		_numFrames = texture->numFrames;
		_animSpeed = texture->animSpeed;
		_currentFrame = 0;
		_currentRow = 0;
	}

	/**
	 * \brief Retourne l'ID de la texture du sprite
	 * \return L'ID de la texture du sprite
	 */
	std::string getTextureID() const {return _textureID;}

	/**
	 * \brief Affiche le sprite dans la fen�tre SDL
	 * \param position La position du sprite � l'�cran
	 * \param velocity La v�locit� du GameObject associ�, pour d�terminer si l'on doit retourner la texture ou non
	 */
	void draw(Vector2D position, Vector2D velocity) const;

	/**
	 * \brief Mets � jour le sprite
	 */
	void update();
private:
	
	int _width;
	int _height;

	float _angle;
	
	int _currentFrame;
	int _currentRow;
	int _numFrames;

	int _animSpeed;
	
	std::string _textureID;
};

