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
	 * \param pTextureId L'ID de la texture
	 */
	Sprite(const std::string& pTextureId);

	~Sprite() = default;

	/**
	 * \brief D�finie la largeur du sprite, en pixel
	 */
	void setWidth(int pWidth);

	/**
	 * \brief Retourne la largeur du sprite
	 * \return La largeur du sprite
	 */
	int getWidth() const;

	/**
	 * \brief D�finie la hauteur du sprite, en pixel
	 */
	void setHeight(int pHeight);

	/**
	 * \brief Retourne la hauteur du sprite
	 * \return La hauteur du sprite
	 */
	int getHeight() const;

	/**
	 * \brief D�finie l'angle du sprite
	 * \param pAngle Le nouvel angle
	 */
	void setAngle(float pAngle);

	/**
	 * \brief Retourne l'angle du sprite.
	 * \return L'angle du sprite
	 */
	float getAngle() const;

	/**
	 * \brief D�finie le nombre de frames du sprite
	 * \param pNumFrames Le nouveau nombre de frames
	 */
	void setNumFrames(int pNumFrames);

	/**
	 * \brief Retourne le nombre de frame du sprite
	 * \return Le nombre de frames du sprite
	 */
	int getNumFrames() const;

	/**
	 * \brief D�finie la frame actuelle du sprite
	 * \param pFrame Le nouveau frame
	 */
	void setCurrentFrame(int pFrame);

	/**
	 * \brief Retourne la frame actuelle du sprite
	 * \return La frame actuelle du sprite
	 */
	int getCurrentFrame() const;

	/**
	 * \brief D�finie si le sprite est visible ou non
	 * \param pIsVisible Vrai si le sprite doit �tre visible, faux sinon
	 */
	void setVisibility(bool pIsVisible);

	/**
	 * \brief Permet de savoir si le sprite est visible ou non
	 * \return Vrai si le sprite est visible, faux sinon
	 */
	bool getVisibility() const;

	/**
	 * \brief D�finie l'ID de la nouvelle texture du sprite
	 * \param pTextureId L'ID de la nouvelle texture
	 */
	void changeTextureID(const std::string& pTextureId);

	/**
	 * \brief Retourne l'ID de la texture du sprite
	 * \return L'ID de la texture du sprite
	 */
	std::string getTextureID() const;

	/**
	 * \brief Affiche le sprite dans la fen�tre SDL
	 * \param pPosition La position du sprite � l'�cran
	 * \param pVelocity La v�locit� du GameObject associ�, pour d�terminer si l'on doit retourner la texture ou non
	 */
	void draw(Vector2D pPosition, Vector2D pVelocity) const;

	/**
	 * \brief Mets � jour le sprite
	 */
	void update();

private:

	bool is_visible{true};
	
	int width;
	int height;

	float angle;
	
	int current_frame;
	int current_row;
	int num_frames;

	int anim_speed;
	
	std::string texture_id;
};

