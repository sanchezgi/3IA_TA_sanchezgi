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

    for (int i = 0; i < 10; ++i)
    {
        player_[i].init(16.0f,
            { 00.0f,0.0f }, { 0.0f,0.0f }, "../../../data/gfx/agents/allied_soldier.bmp");
        
        player_[i].index = board_.randomWalkableTile();
        board_.index2rowcol(player_[i].row_, player_[i].col_, player_[i].index);
        player_[i].setPosition(sf::Vector2f(player_[i].col_[0] * 16, player_[i].row_[0] * 16));
        board_.units_[player_[i].index] = 1;
    }
     
    texture.loadFromFile("../../../data/gfx/maps/map_03_960x704_cost.png");
    sprite.setTexture(texture);
    sprite.setScale(1.0f, 1.0f);
}

void TitleScene::update(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window) {
	
	system("cls");
	
	for (int i = 0; i < 10; ++i)
	{
		player_[i].update(deltaTime, myinput, &board_);	
	}
	board_.debugPrint();
	
    //printf("X:%f                Y:%f          Index:%d\n", player_.position_.x, player_.position_.y,player_.index);
}

void TitleScene::draw(sf::RenderWindow& window) {
	
    window.draw(sprite);
	
    for (int i = 0; i < 10; ++i)
    {
		player_[i].draw(window);
    }
}

TitleScene::~TitleScene() {
   
}
