/**
* @author Alejandro Sanchez Gimeno
* @date 2020 - 2021
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Window class.
*/

#include "window.h"

void::Window::init(unsigned int width, unsigned int height) {
    window_.create(sf::VideoMode(width, height), "SFML project");
}

void::Window::frame(int frames) {
    window_.setFramerateLimit(frames);
}
void Window::destroy() {
    window_.close();
}
bool Window::isOpened() {
    return window_.isOpen();
}
void Window::setSize(sf::Vector2u size) {
    window_.setSize(size);
}

sf::Vector2u Window::getSize() {
    return window_.getSize();
}

void Window::setMouseCursorVisible(bool visible) {
    window_.setMouseCursorVisible(visible);
}
void Window::display() {
    window_.display();
}
void Window::clear() {
    window_.clear();
}