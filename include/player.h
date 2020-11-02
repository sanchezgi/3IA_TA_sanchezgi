/**
* @author Alejandro Sanchez Gimeno
* @date 25 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Player class.
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__ 1

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "input.h"

class Board;

class Player {
public:

    /** @brief Default constructor.
    *
    */
    Player();
    /** @brief Copy constructor.
    *
    * @param o the object you want to copy from.
    */
    Player(const Player& o);
    /** @brief Default destructor.
    *
    */
    ~Player();
    /** @brief Function that initializes to zero all the class variables.
    *
    */
    void init();
    /** @brief Function that initializes all the variables with certain parameters.
    *
    * @param life The life of the player.
    * @param gravity The force of the gravity that affect the player.
    * @param jumpSpeed The force of the player's jump.
    * @param moveSpeed The speed of the player's movement.
    * @param position The position of the player.
    * @param velocity The vector of the player's movement.
    * @param file_name The file of the spritesheet.
    */
    void init(int life, int gravity, int jumpSpeed, int moveSpeed, sf::Vector2f position,
        sf::Vector2f velocity, const char* file_name);
    /** @brief Sets the position of the player.
    *
    * @param pos The position the player will set.
    */
    void setPosition(sf::Vector2f pos);
    /** @brief Returns the player's position.
    *
    * @return sf::Vector2f The player's position.
    */
    sf::Vector2f getPosition();
    /** @brief move position of the player.
    *
    * @param pos The position the player will move.
    */
    void movePosition(sf::Vector2f pos);
    
    /** @brief Applies the gravity and make the player's movement.
    *
    * @param input The input of the player.
    * @param collision1 The first point to detect the collision and decides if the player moves or not.
    * @param collision2 The second point to detect the collision and decides if the player moves or not.
    */
    void move(sf::Time deltaTime, Input& input,Board* Board);
    /** @brief Updates the player
    *
    * @param input The input of the player.
    * @param collision1 The first point to detect the collision and decides if the player updates or not.
    * @param collision2 The second point to detect the collision and decides if the player updates or not.
    */
    void update(sf::Time deltaTime, Input& input,Board* board);
    /** @brief Draw the player
    *
    * @param window The window that renders and paint the objects.
    */
    void draw(sf::RenderWindow& window);

    int life_;
    int gravity_;
    int jumpSpeed_;
    int moveSpeed_;
    int row_[1];
    int col_[1];
    int index;
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    sf::Sprite* sprite_; /**< pointer to the player sprite */
    sf::Texture* texture_; /**< pointer to the sprite texture */
    sf::Time elapsed_; /**< timer that controlls the player animations */
    sf::Clock clock_; /**< timer that controlls the player animations */
};

#endif
