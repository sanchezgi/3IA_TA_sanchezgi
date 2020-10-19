/**
* @author Alejandro Sanchez Gimeno
* @date 10 Nov 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Window class.
*/

 #ifndef __MY_WINDOW_H__
 #define __MY_WINDOW_H__ 1

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Window {
public:

  /** @brief Function that initializes all the variables with certain parameters.
  *
  * @param width The screen width.
  * @param height The screen height.
  */
  void init(unsigned int width , unsigned int height);
  /** @brief Set the window frames.
  *
  * @param frames The frames the window will run with.
  */
  void frame(int frames);
  /** @brief Destroy the window.
  *
  */
  void destroy();
  /** @brief Chechs if the window is opened or not.
  *
  * @return bool true if the window is opened, false if it's not.
  */
  bool isOpened();
  /** @brief Set the window size.
  *
  * @param size width and height of the window.
  */
  void setSize(sf::Vector2u size);
  /** @brief Returns the window size.
  *
  * @return sf::Vector2f The window size.
  */
  sf::Vector2u getSize();
  /** @brief Set the mouse visibility.
  *
  * @param visible Boolean if true the visibility is on.
  */
  void setMouseCursorVisible(bool visible);
  /** @brief Display the window.
  *
  */
  void display();
  /** @brief Clear the window.
  *
  */
  void clear();

  sf::RenderWindow window_; /**< The window that renders and paint the objects */
};

#endif