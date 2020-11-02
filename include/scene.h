/**
* @author Alejandro Sanchez Gimeno
* @date 2020 - 2021
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Scene class. It's abstract
*/

#ifndef __SCENE_H__
#define __SCENE_H__ 1

#include "window.h"
#include "input.h"

class Scene {
public:

    /** @brief Function that initializes all the objects.
    *
    */
    virtual void init() = 0;
    /** @brief Function that updates all the objects.
    *
    * @param dt Delta Time.
    * @param myinput user input.
    * @param window The window that renders and paint the object.
    */
    virtual void update(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) = 0;
    /** @brief Function that draws all the objects.
    *
    * @param window The window that renders and paint the object.
    */
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif