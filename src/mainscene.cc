/**
* @author Alejandro Sanchez Gimeno
* @date 5 Dec 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Enemy class.
*/
#include "mainscene.h"
#include "gamemanager.h"
#include "boardloader.h"

sf::Texture texture;
sf::Sprite sprite;

TitleScene::TitleScene() {

}

void TitleScene::init() {

    board_.init(60, 44);
    BoardFromImage(&board_, "../../../data/gfx/maps/map_03_60x44_cost.png");
    board_.debugPrint();
	
    player_.init(10, 10.0f, 10.0f, 16.0f,
        { 00.0f,0.0f }, { 0.0f,0.0f }, "../../../data/gfx/agents/allied_soldier.bmp"); 
	
    player_.index = rand() % board_.width_ * board_.height_;
    board_.index2rowcol(player_.row_, player_.col_, player_.index);
	

	player_.setPosition(sf::Vector2f(player_.col_[0] * 16.0f,player_.row_[0] * 16.0f));
   
    texture.loadFromFile("../../../data/gfx/maps/map_03_960x704_cost.png");
    sprite.setTexture(texture);
    sprite.setScale(1.0f, 1.0f);
}

void TitleScene::update(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) {
	system("cls");
	board_.debugPrint();
    player_.update(deltaTime, myinput, &board_);
    //printf("X:%f                Y:%f          Index:%d\n", player_.position_.x, player_.position_.y,player_.index);
}

void TitleScene::draw(sf::RenderWindow& window) {
	
    window.draw(sprite);
    player_.draw(window);
}

TitleScene::~TitleScene() {
   
}
