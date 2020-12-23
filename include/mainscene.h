/**
* @author Alejandro Sanchez Gimeno
* @date  2020
* @copyright 2020 Alejandro Sanchez Gimeno
* @brief Title scene class.Inherits from scene.
*/

#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__ 1

#include "board.h"
#include "input.h"

#include "scene.h"
#include "Agent.h"


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
    void update(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window,int dest) override;

    void updateRandomMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) override;
    void updateDeterministMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) override;
    void updatePatronMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) override;
    void updatePacManMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window,int dest) override;
    void updateInputMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window,int dest) override;

    /** @brief Function that draws all the objects.
    *
    * @param window The window that renders and paint the object.
    */
    void draw(sf::RenderWindow& window) override;

   
    Agent agent_[4];
    Agent player_;
    Board board_;
   
    bool build_;
    const int max_enemies = 20;

    int number_build_tiles_;
    int number_dec_tiles_;
    int number_erase_tiles_;
    sf::Time timer_;
    sf::Clock clock_;

private:

    /** @brief Copy constructor.
    *
    * @param o the object you want to copy from.
    */
    TitleScene(const TitleScene& o);
};
#endif