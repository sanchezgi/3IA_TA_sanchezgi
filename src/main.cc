/**
* @file 
* @author Alejandro Sanchez Gimeno 
* @date 2020 - 2021
* @copyright 2020 Alejandro Sanchez Gimeno 
* @brief
*/

#include "game.h"

int main(int argc, char const* argv[]) {

    Game g;
	
    g.init();
    g.mainLoop();
    g.finish();
    
    return 0;
}