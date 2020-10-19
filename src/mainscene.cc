/**
* @author Alejandro Sanchez Gimeno
* @date 5 Dec 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Enemy class.
*/
#include "mainscene.h"
#include "gamemanager.h"


TitleScene::TitleScene() {

}

void TitleScene::init() {

    player_.init(10, 10.0f, 10.0f, 2.0f,
        { 100.0f,100.0f }, { 0.0f,0.0f }, "../../../data/gfx/agents/player_ship.bmp");
    player_.setPosition({ 600.0f,500.0f });

    GameManager::Instance().view_.setSize(GameManager::Instance().w_width_, GameManager::Instance().w_height_);

}

void TitleScene::update(float dt, Input& myinput, sf::RenderWindow& window) {
    
    timer_ = clock_.getElapsedTime();

    player_.update(myinput);
	
}

void TitleScene::draw(sf::RenderWindow& window) {
    window.setView(GameManager::Instance().view_);
  
    player_.draw(window);
}

TitleScene::~TitleScene() {
   
}
