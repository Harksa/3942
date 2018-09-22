#pragma once

/**
 * \brief gère le score du joueur
 */
class ScoreManager {
public:

	/**
	 * \brief Retourne l'instance du ScoreManager
	 */
	static ScoreManager * Instance() {
		if(instance == nullptr)
			instance = new ScoreManager();

		return  instance;
	}

	/**
	 * \brief Ajoute des points au score du joueur
	 * \param points Les points à ajouter
	 */
	void addPoints(unsigned int points);

	/**
	 * \brief Retourne le score actuel du joueur
	 * \param Le score actuel du joueur
	 */
	unsigned int getScore() const { return score; }

	~ScoreManager() = default;
private:

	ScoreManager() = default;

	/**
	 * \brief L'instance du ScoreManager
	 */
	static ScoreManager * instance;

	/**
	 * \brief Le score actuel du joueur
	 */
	unsigned int score{0};

};
