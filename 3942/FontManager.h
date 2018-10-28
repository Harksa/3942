#pragma once
#include <map>
#include "FontCache/SDL_FontCache.h"

/**
 * \brief Gère les polices d'écritures et leur affichage
 */
class FontManager {
public:
	/**
	 * \brief Retourne l'instance de FontManager
	 * \return L'instance de FontManager
	 */
	static FontManager* Instance();

	/**
	 * \brief Créer une police de caractère
	 * \param pFontName Le nom de la police
	 * \param pFileName L'endroit où se situe la police
	 * \param pSize La taille de la police
	 * \param pColor La couleur de la police
	 * \param pStyle Le style de la police
	 */
	void createFont(std::string pFontName, const std::string& pFileName, unsigned int pSize, SDL_Color pColor, int pStyle = TTF_STYLE_NORMAL);

	/**
	 * \brief Dessine un message à l'écran
	 * \param pFontName La police utilisée pour dessiner le message
	 * \param pPosx La position en X du message
	 * \param pPosY La position en Y du message
	 * \param pText Le texte à afficher
	 */
	void draw(const std::string& pFontName, unsigned pPosx, unsigned pPosY, const std::string& pText) const;

	/**
	 * \brief Dessine un message à l'écran avec un alignement
	 * \param pFontName La police utilisée pour dessiner le message
	 * \param pPosx La position en X du message
	 * \param pPosY La position en Y du message
	 * \param pAlign L'alignement souhaité du message
	 * \param pText Le texte à afficher
	 */
	void drawAlign(const std::string& pFontName, unsigned int pPosx, unsigned int pPosY, FC_AlignEnum pAlign, const std::string& pText) const;

	/**
	 * \brief Dessine un message à l'écran, contenu dans un rectangle et avec un alignement
	 * \param pFontName La police utilisée pour dessiner le message
	 * \param pRect Le SDL_Rect à l'intérieur duquel se trouve le message
	 * \param pAlign L'alignement souhaité du message
	 * \param pText Le texte à afficher
	 */
	void drawBoxAlign(const std::string& pFontName, SDL_Rect pRect, FC_AlignEnum pAlign, const std::string& pText) const;

	/**
	 * \brief Nettoie la liste des polices du FontManager
	 */
	void clear();

private:
	
	FontManager() = default;
	~FontManager() = default;

	/**
	 * \brief La map comprenant les polices de caractères utilisées
	 */
	std::map<std::string, FC_Font *> fonts;

	/**
	 * \brief L'instance de FontManager
	 */
	static FontManager * instance;
};

