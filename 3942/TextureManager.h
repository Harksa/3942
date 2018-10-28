#pragma once
#include <SDL2/SDL.h>
#include <map>

/**
 * \brief Contient les informations des textures, telles que la taille, etc...
 */
struct Texture_Informations {

	Texture_Informations(const int w, const int h, const int numF, const int speed = 0) :  width{w}, height{h}, numFrames{numF}, animSpeed{speed} {}

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

	Texture_Informations() = default;
	~Texture_Informations() = default;
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
	static TextureManager* Instance();

	~TextureManager();

	/**
	 * \brief Charge un fichier image
	 * \param pFileName l'emplacement du fichier image
	 * \param pId l'Id donnée à cette texture
	 * \return vrai si l'image a été correctement chargé, faux sinon
	 */
	bool load(const std::string& pFileName, const std::string& pId);

	/**
	 * \brief Charge un fichier image
	 * \param pFileName l'emplacement du fichier image
	 * \param pId l'Id donnée à cette texture
	 * \param pWidth La largeur de la texture
	 * \param pHeight La hauteur de la texture
	 * \param pNumFrames Le nombres de frames de la texture
	 * \param pSpeed La vitesse d'animations de la texture
	 * \return vrai si l'image a été correctement chargé, faux sinon
	 */
	bool load(const std::string& pFileName, const std::string& pId, int pWidth, int pHeight, int pNumFrames, int pSpeed);

	/**
	 * \brief Dessine un élément à l'écran
	 * \param pId L'ID de la texture à dessiner
	 * \param pX La position en X
	 * \param pY La position en Y
	 * \param pWidth La largeur de la texture
	 * \param pHeight La hauteur de la texture
	 * \param pFlip le paramètre permettant de savoir si la texture est retourné ou non
	 */
	void draw(const std::string& pId, int pX, int pY, int pWidth, int pHeight, SDL_RendererFlip pFlip = SDL_FLIP_NONE);
	
	/**
	 * \brief Dessine la frame d'une texture à l'écran
	 * \param pId L'ID de la texture à dessiner
	 * \param pX La position en X
	 * \param pY La position en Y
	 * \param pWidth La largeur de la texture
	 * \param pHeight La hauteur de la texture
	 * \param pCurrentRow La ligne de la frame dans le fichier image
	 * \param pCurrentFrame La frame que l'on désire afficher
	 * \param pFlip le paramètre permettant de savoir si la texture est retourné ou non
	 */
	void drawFrame(const std::string& pId, int pX, int pY, int pWidth, int pHeight, int pCurrentRow, int pCurrentFrame, SDL_RendererFlip pFlip = SDL_FLIP_NONE);

	/**
	 * \brief Nettoie la texture et les informations ayant l'ID rentré en paramètre
	 * \param pId L'ID de la texture que l'on souhaite effacer
	 */
	void clearFromTextureMapAndInformations(const std::string& pId);

	/**
	 * \brief Nettoie la texture seulement ayant l'ID rentré en paramètre
	 * \param pId L'ID de la texture que l'on souhaite effacer
	 */
	void clearFromTextureMap(const std::string& pId);

	/**
	 * \brief Dessine la frame d'une texture à l'écran
	 * \param id L'ID de la texture à dessiner
	 * \param pMargin L'espace entre deux colonnes
	 * \param pSpacing L'espace entre deux lignes
	 * \param pX La position en X
	 * \param pY La position en Y
	 * \param pWidth La largeur de la texture
	 * \param pHeight La hauteur de la texture
	 * \param pCurrentRow La ligne de la frame dans le fichier image
	 * \param pCurrentFrame La frame que l'on désire afficher
	 */
	void drawTile(const std::string& id, int pMargin, int pSpacing, int pX, int pY, int pWidth,
	              int pHeight, int pCurrentRow, int pCurrentFrame);


	/**
	 * \brief Donne les informations d'une texture à partir de son ID.
	 * \param pId L'ID de la texture dont ont souhaite obtenir les informations
	 * \return Les informations de la texture
	 */
	Texture_Informations getTextureInformationsFromID(const std::string& pId);

private:
	/**
	 * \brief L'instance du TextureManager
	 */
	static TextureManager * instance;

	/**
	 * \brief Les réferences vers les textures
	 */
	std::map<std::string, SDL_Texture*> texture_map;

	/**
	 * \brief Map gérant les informations des textures
	 */
	std::map<std::string, Texture_Informations> texture_informations;

	TextureManager() = default;
};
