/**
* @author Alejandro Sanchez Gimeno
* @date 5 Dec 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Title scene class.Inherates from scene.
*/

#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__ 1

#include "board.h"
#include "input.h"

#include "scene.h"
#include "player.h"


class TitleScene : public Scene {
public:

    /** @brief Default constructor.
    *
    */
    TitleScene();
    /** @brief Default destructor.
    *
    */
    ~TitleScene();
    /** @brief Function that initializes all the objects.
    *
    */
    void init() override;
    /** @brief Function that updates all the objects.
    *
    * @param dt Delta Time.
    * @param myinput user input.
    * @param window The window that renders and paint the object.
    */
    void update(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) override;
    /** @brief Function that draws all the objects.
    *
    * @param window The window that renders and paint the object.
    */
    void draw(sf::RenderWindow& window) override;

   
    Player player_[10];
    Board board_;
  
private:

    /** @brief Copy constructor.
    *
    * @param o the object you want to copy from.
    */
    TitleScene(const TitleScene& o);
};
#endif