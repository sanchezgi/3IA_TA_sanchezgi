/**
* @author Alejandro Sanchez Gimeno
* @date 21 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief GameMnager that allocates crucial variables.
*/

#include "gamemanager.h"

GameManager::GameManager() {

    w_width_ = 0;
    w_height_ = 0;
}

GameManager::GameManager(const GameManager& o) {}

GameManager& GameManager::Instance() {
    static GameManager* inst = nullptr;
    if (inst == nullptr) {
        inst = new GameManager();
    }
    return *inst;
}