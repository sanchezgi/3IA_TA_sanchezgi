/**
* @author Alejandro Sanchez Gimeno
* @date 25 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Agent class.
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__ 1

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "input.h"

class Board;

enum MovementType
{
    kRandomMovement = 0,
    kPathFinding,
    kPattern,
    kDeterministMovement,
	  kTrackingMovement,
    kInputMovement,
    kNone,
};

enum PatternsCommands
{
	kGoForward = 0,
	kTurnLeft,
	kTurnRight,
	kStop,
	kBackwards,	
};

enum Direction
{
    kUp = 0,
	kLeft,
	kDown,
	kRight,
	kDirectionNone,
};

class Agent {
public:

    /** @brief Default constructor.
    *
    */
    Agent();
    /** @brief Copy constructor.
    *
    * @param o the object you want to copy from.
    */
    Agent(const Agent& o);
    /** @brief Default destructor.
    *
    */
    ~Agent();
    /** @brief Function that initializes to zero all the class variables.
    *
    */
    void init();
    /** @brief Function that initializes all the variables with certain parameters.
    *
    * @param moveSpeed The speed of the player's movement.
    * @param position The position of the player.
    * @param velocity The vector of the player's movement.
    * @param file_name The file of the spritesheet.
    */
    void init(int moveSpeed, sf::Vector2f position,
        sf::Vector2f velocity,MovementType type, const char* file_name);
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
    void move(sf::Time deltaTime, Input& input,Board* Board, int dest);
    /** @brief Updates the player
    *
    * @param input The input of the player.
    * @param collision1 The first point to detect the collision and decides if the player updates or not.
    * @param collision2 The second point to detect the collision and decides if the player updates or not.
    */
    void update(sf::Time deltaTime, Input& input,Board* board, int dest);
    /** @brief Draw the player
    *
    * @param window The window that renders and paint the objects.
    */
    void draw(sf::RenderWindow& window);

    void randomMovement(sf::Time deltaTime, Input& input, Board* Board);
    void deterministMovement(sf::Time deltaTime, Input& input, Board* Board);
    void patternMovement(sf::Time deltaTime, Input& input, Board* Board);
    void trackingMovement(sf::Time deltaTime, Input& input, Board* Board,int dest);
    void inputMovement(sf::Time deltaTime, Input& input, Board* Board,int dest);

    int moveSpeed_;
    int row_[1];
    int col_[1];
    int index;
    int typeMovement;
    bool pathChosen;
    int direction;
    std::vector<int> patternsArray;
    unsigned int step;
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    sf::Sprite* sprite_; /**< pointer to the player sprite */
    sf::Texture* texture_; /**< pointer to the sprite texture */
};

#endif
