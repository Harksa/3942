#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <map>

/**
 * \brief Contient les informations des textures, telles que la taille, etc...
 */
struct texture_informations {
	/**
	 * \brief La largeur de la texture
	 */
	int width;

	/**
	 * \brief La hauteur de la texture
	 */
	int height;

	/**
	 * \brief Le nombre de frames comprit dans la texture
	 */
	int numFrames;

	/**
	 * \brief La vitesse d'animations de la texture
	 */
	int animSpeed;

	texture_informations(const int w, const int h, const int numF, const int speed = 0) :  width(w), height(h), numFrames(numF), animSpeed(speed) {}
};

/**
 * \brief Gère l'ensemble des textures du jeu
 */
class TextureManager {

public:
	/**
	 * \brief Retourne l'instance de TextureManager
	 * \return L'instance du TextureManager
	 */
	static TextureManager * Instance() {
		if(instance == nullptr) {
			instance = new TextureManager();
		}

		return instance;
	}

	~TextureManager();

	/**
	 * \brief Charge un fichier image
	 * \param fileName l'emplacement du fichier image
	 * \param id l'Id donnée à cette texture
	 * \param pRenderer le SDL_Renderer utilisé pour le jeu
	 * \return vrai si l'image a été correctement chargé, faux sinon
	 */
	bool load(const std::string& fileName, const std::string& id, SDL_Renderer* pRenderer);

	/**
	 * \brief Charge un fichier image
	 * \param fileName l'emplacement du fichier image
	 * \param id l'Id donnée à cette texture
	 * \param width La largeur de la texture
	 * \param height La hauteur de la texture
	 * \param numFrames Le nombres de frames de la texture
	 * \param speed La vitesse d'animations de la texture
	 * \param renderer le SDL_Renderer utilisé pour le jeu
	 * \return vrai si l'image a été correctement chargé, faux sinon
	 */
	bool load(const std::string & fileName, const std::string & id, const int width, const int height, const int numFrames, const int speed, SDL_Renderer * renderer);

	/**
	 * \brief Dessine un élément à l'écran
	 * \param id L'ID de la texture à dessiner
	 * \param x La position en X
	 * \param y La position en Y
	 * \param width La largeur de la texture
	 * \param height La hauteur de la texture
	 * \param renderer Le renderer
	 * \param flip le paramètre permettant de savoir si la texture est retourné ou non
	 */
	void draw(const std::string& id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/**
	 * \brief Dessine la frame d'une texture à l'écran
	 * \param id L'ID de la texture à dessiner
	 * \param x La position en X
	 * \param y La position en Y
	 * \param width La largeur de la texture
	 * \param height La hauteur de la texture
	 * \param currentRow La ligne de la frame dans le fichier image
	 * \param currentFrame La frame que l'on désire afficher
	 * \param renderer Le renderer
	 * \param flip le paramètre permettant de savoir si la texture est retourné ou non
	 */
	void drawFrame(const std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	/**
	 * \brief Nettoie l'élement rentré en paramètre de la texture map
	 * \param id L'ID de la texture que l'on souhaite effacer
	 */
	void clearFromTextureMap(const std::string& id);

	/**
	 * \brief Dessine la frame d'une texture à l'écran
	 * \param id L'ID de la texture à dessiner
	 * \param margin L'espace entre deux colonnes
	 * \param spacing L'espace entre deux lignes
	 * \param x La position en X
	 * \param y La position en Y
	 * \param width La largeur de la texture
	 * \param height La hauteur de la texture
	 * \param currentRow La ligne de la frame dans le fichier image
	 * \param currentFrame La frame que l'on désire afficher
	 * \param renderer Le renderer
	 */
	void drawTile(const std::string& id, int margin, int spacing, int x, int y, int width, 
	             int height, int currentRow, int currentFrame, SDL_Renderer* renderer);

	texture_informations * getTextureInformationsFromID(const std::string& id) {return _textureInformations[id];}

private:
	/**
	 * \brief L'instance du TextureManager
	 */
	static TextureManager *instance;

	/**
	 * \brief Les réferences vers les textures
	 */
	std::map<std::string, SDL_Texture*> _textureMap;

	std::map<std::string, texture_informations *> _textureInformations;

	TextureManager() = default;
};
