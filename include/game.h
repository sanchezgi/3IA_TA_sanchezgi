/**
* @author Alejandro Sanchez Gimeno
* @date 2020 - 2021
* @copyright 2020 Alejandro Sanchez Gimeno
* @brief Game class that manages all the scenes.
*/

#ifndef __GAME_H__
#define __GAME_H__ 1


#include "window.h"
#include "scene.h"
#include "input.h"

class Game
{
public:

    /** @brief Initialize the setting, the data base,the IMGUI and the scene.
  *
  */
    void init();
    /** @brief Loop that repeats the input, update and draw of the current scene.
    *
    */
    void mainLoop(Input& input);
    /** @brief destroy all object before exit the program.
    *
    */
    void finish();
    /** @brief Function that initializes all the variables with certain parameters.
    *
    * @return Scene* Scene pointer.
    * @param scene A pointer to the current scene.
	*/

    Scene* newScene(Scene* scene);
	
    Window window_; /**< window that renders and raw the objects */
    Input input_; /**< class that manges the input */

protected:

    /** @brief Manages all the user input.
    *
    */
    void input(Input& input);
    /** @brief Updates the current scene.
    *
    */
    void update(sf::Time deltaTime);
    /** @brief Updates the current scene.
    *
    */
    void processEvent(Input& input);
    void fixedUpdate(sf::Time deltaTIme);
    void fixedUpdateRandom(sf::Time deltaTIme);
    void fixedUpdateDeterminist(sf::Time deltaTIme);
    void fixedUpdatePattern(sf::Time deltaTIme);
    void fixedUpdatePacMan(sf::Time deltaTIme);
    /** @brief Draw the current scene.
    *
    */
    void draw();
    /** @brief Check and loads the scenes.
    *
    */
    void checkScene();

    Scene* current_scene_; /**< pointer to the current scene */
	
};

#endif

