#pragma once
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"

/**
 * \brief Gère le sprite des SDLGameObjects
 */
class Sprite {
public:
	/**
	 * \brief Créer un sprite en fonction de l'ID rentré en paramètre.
	 * Les informations sont cherchés dans le texture manager grâce à ce dernier.
	 * \param pTextureId L'ID de la texture
	 */
	Sprite(const std::string& pTextureId);

	~Sprite() = default;

	/**
	 * \brief Définie la largeur du sprite, en pixel
	 */
	void setWidth(int pWidth);

	/**
	 * \brief Retourne la largeur du sprite
	 * \return La largeur du sprite
	 */
	int getWidth() const;

	/**
	 * \brief Définie la hauteur du sprite, en pixel
	 */
	void setHeight(int pHeight);

	/**
	 * \brief Retourne la hauteur du sprite
	 * \return La hauteur du sprite
	 */
	int getHeight() const;

	/**
	 * \brief Définie l'angle du sprite
	 * \param pAngle Le nouvel angle
	 */
	void setAngle(float pAngle);

	/**
	 * \brief Retourne l'angle du sprite.
	 * \return L'angle du sprite
	 */
	float getAngle() const;

	/**
	 * \brief Définie le nombre de frames du sprite
	 * \param pNumFrames Le nouveau nombre de frames
	 */
	void setNumFrames(int pNumFrames);

	/**
	 * \brief Retourne le nombre de frame du sprite
	 * \return Le nombre de frames du sprite
	 */
	int getNumFrames() const;

	/**
	 * \brief Définie la frame actuelle du sprite
	 * \param pFrame Le nouveau frame
	 */
	void setCurrentFrame(int pFrame);

	/**
	 * \brief Retourne la frame actuelle du sprite
	 * \return La frame actuelle du sprite
	 */
	int getCurrentFrame() const;

	/**
	 * \brief Définie si le sprite est visible ou non
	 * \param pIsVisible Vrai si le sprite doit être visible, faux sinon
	 */
	void setVisibility(bool pIsVisible);

	/**
	 * \brief Permet de savoir si le sprite est visible ou non
	 * \return Vrai si le sprite est visible, faux sinon
	 */
	bool getVisibility() const;

	/**
	 * \brief Définie l'ID de la nouvelle texture du sprite
	 * \param pTextureId L'ID de la nouvelle texture
	 */
	void changeTextureID(const std::string& pTextureId);

	/**
	 * \brief Retourne l'ID de la texture du sprite
	 * \return L'ID de la texture du sprite
	 */
	std::string getTextureID() const;

	/**
	 * \brief Permet de savoir si le sprite joue sa dernière frame
	 * \return Vrai s'il joue sa dernière frame, faux sinon
	 */
	bool isPlayingLastFrame() const;

	/**
	 * \brief Affiche le sprite dans la fenêtre SDL
	 * \param pPosition La position du sprite à l'écran
	 * \param pVelocity La vélocité du GameObject associé, pour déterminer si l'on doit retourner la texture ou non
	 */
	void draw(Vector2D pPosition, Vector2D pVelocity) const;

	/**
	 * \brief Mets à jour le sprite
	 */
	void update();

private:

	/**
	 * \brief Booléen déterminant si le sprite est affiché ou non
	 */
	bool is_visible{true};

	/**
	 * \brief La largeur d'un frame du sprite
	 */
	int width;

	/**
	 * \brief La hauteur d'un frame du sprite
	 */
	int height;

	/**
	 * \brief L'angle à laquel le sprite est dessiné
	 */
	float angle;

	/**
	 * \brief Le frame courrament dessiné
	 */
	int current_frame{0};

	/**
	 * \brief La colonne actuelle où est situé le frame dessiné
	 */
	int current_row{0};

	/**
	 * \brief Le total de frames que possède cet animation
	 */
	int total_num_frames;

	/**
	 * \brief La vitesse d'animation du sprite
	 */
	int anim_speed;

	/**
	 * \brief La textureID associé à ce sprite
	 */
	std::string texture_id;

	/**
	 * \brief Utilisé pour que les frames soient remis à 0 lors d'un changement de texture
	 */
	Uint32 time_reseter{0};
};

