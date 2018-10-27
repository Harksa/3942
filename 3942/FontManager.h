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
	 * \param font_name Le nom de la police
	 * \param file_name L'endroit où se situe la police
	 * \param size La taille de la police
	 * \param color La couleur de la police
	 * \param style Le style de la police
	 */
	void createFont(std::string font_name, const std::string& file_name, unsigned int size, SDL_Color color, int style = TTF_STYLE_NORMAL);

	/**
	 * \brief Dessine un message à l'écran
	 * \param font_name La police utilisée pour dessiner le message
	 * \param pos_x La position en X du message
	 * \param pos_y La position en Y du message
	 * \param text Le texte à afficher
	 */
	void draw(const std::string& font_name, unsigned pos_x, unsigned pos_y, const std::string& text) const;

	/**
	 * \brief Dessine un message à l'écran avec un alignement
	 * \param font_name La police utilisée pour dessiner le message
	 * \param pos_x La position en X du message
	 * \param pos_y La position en Y du message
	 * \param align L'alignement souhaité du message
	 * \param text Le texte à afficher
	 */
	void drawAlign(const std::string& font_name, unsigned int pos_x, unsigned int pos_y, FC_AlignEnum align, const std::string& text) const;

	/**
	 * \brief Dessine un message à l'écran, contenu dans un rectangle et avec un alignement
	 * \param font_name La police utilisée pour dessiner le message
	 * \param rect Le SDL_Rect à l'intérieur duquel se trouve le message
	 * \param align L'alignement souhaité du message
	 * \param text Le texte à afficher
	 */
	void drawBoxAlign(const std::string& font_name, SDL_Rect rect, FC_AlignEnum align, const std::string& text) const;

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

