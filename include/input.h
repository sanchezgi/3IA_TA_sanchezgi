/**
* @author Alejandro Sanchez Gimeno
* @date 202 - 2021
* @copyright 2020  Alejandro Sanchez Gimeno
* @brief 
*/


#ifndef __INPUT_H__
#define __INPUT_H__ 1

#include "SFML/Window.hpp"

class Input
{
public:

  Input();
  ~Input();
    bool IsMovingUp;
    bool IsMovingDown;
    bool IsMovingLeft;
    bool IsMovingRight;
   
};
#endif
