/**
* @file 
* @author Alejandro Sanchez Gimeno 
* @date 2020 - 2021
* @copyright 2020 Alejandro Sanchez Gimeno 
* @brief
*/

#include "game.h"
#include "input.h"

int main(int argc, char const* argv[]) {

    Game g;
    Input i;
	
    g.init();
    g.mainLoop(i);
    g.finish();
    
    return 0;
}