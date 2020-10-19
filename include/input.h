/**
* @author Alejandro Sanchez Gimeno
* @date 202 - 2021
* @copyright 2020  Alejandro Sanchez Gimeno
* @brief 
*/


#ifndef __INPUT_H__
#define __INPUT_H__ 1

#include "SFML/Window.hpp"
/**
* @brief Enum for classify the input player
*/

enum MouseInput {
    kNothing,
    kMouseLeftPressed,
    kMouseLeftReleased,
    kMouseRightPressed,
    kMouseRightReleased,
    kMouseDrag,
    kLeftPressed,
    kLeftReleased,
    kUpPressed,
    kDownPressed,
    kRightPressed,
    kRightReleased,
    kSpacePressed,
    kSpaceReleased,
    kPausePressed,
    kPauseReleased,
    kEscPressed,
    kEscReleased,
    kEnterPressed
};
/**
* @brief struct for the input in game
*/

struct Input {
    int mouse_input;
    bool mouse_is_draggin;
    bool is_pressed;
    int keyboard_input_1;
};
/**
* @brief function for initialice the input
* @param input the input for init
*/

void InitInput(Input& input);
/**
* @brief function for check the input with events of sfml
* @param input the input for check
* @param event the event of game
*/
void CheckInput(Input& input, sf::Event& event);



#endif
