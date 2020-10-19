/**
* @author Alejandro Sanchez Gimeno
* @date 202 - 2021
* @copyright 2020  Alejandro Sanchez Gimeno
* @brief
*/

#include <input.h>

void InitInput(Input& input) {
    input.mouse_input = kNothing;
    input.keyboard_input_1 = kNothing;
    input.mouse_is_draggin = false;
}
void CheckInput(Input& input, sf::Event& event) {
    input.keyboard_input_1 = kNothing;
    /*Mouse*/
    if (event.type == sf::Event::MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left) {
        input.mouse_input = kMouseLeftPressed;
        input.mouse_is_draggin = true;
    }
    if (event.type == sf::Event::MouseMoved) {
        input.mouse_input = kMouseDrag;
    }
    if (event.type == sf::Event::MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left) {
        input.mouse_input = kMouseLeftReleased;
        input.mouse_is_draggin = false;
    }
    if (event.type == sf::Event::MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Right) {
        input.mouse_input = kMouseRightPressed;
        input.mouse_is_draggin = true;
    }
    if (event.type == sf::Event::MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Right) {
        input.mouse_input = kMouseRightReleased;
        input.mouse_is_draggin = false;
    }
    /*KEYBOARD*/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        input.keyboard_input_1 = kRightPressed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        input.keyboard_input_1 = kLeftPressed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        input.keyboard_input_1 = kSpacePressed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        input.keyboard_input_1 = kEscPressed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        input.keyboard_input_1 = kEnterPressed;
    }




    if (event.type == sf::Event::KeyReleased
        && event.key.code == sf::Keyboard::P) {
        input.keyboard_input_1 = kPauseReleased;
    }
    
}