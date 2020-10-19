/**
* @author Alejandro Sanchez Gimeno
* @date 21 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief GameMnager that allocates crucial variables.
*/
#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameManager {
public:

    sf::View view_; /**< Global camera that follows the player */
    int w_width_; /**< window width */
    int w_height_; /**< window height */
    int num_scene_; /**< number of the scene */
    bool load_; /**< boolean that checks if the scene is loaded or not */
    sf::Clock dt_clock_; /**< timer that controlls the flux of the game */
    int num_map_; /**< numbre of the map to load from the data base */

    /** @brief Returns an instance of the GameManager.
    *
    * @return GameManager& instance of GameManager.
    */
    static GameManager& Instance();

private:

    /** @brief Default constructor.
    *
    */
    GameManager();
    /** @brief Copy constructor.
    *
    * @param o the object you want to copy from.
    */
    GameManager(const GameManager& o);

};

#endif