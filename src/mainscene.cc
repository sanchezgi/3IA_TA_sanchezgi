/**
* @author Alejandro Sanchez Gimeno
* @date 2020 - 2021
* @copyright 2020 Alejandro Sanchez Gimeno
* @brief Main Scene class.
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

    // Random Agent
    agent_[0].init(16.0f,
      { 00.0f,0.0f }, { 0.0f,0.0f },kRandomMovement, "../../../data/gfx/agents/allied_soldier.bmp");
    agent_[0].index = board_.randomWalkableTile();
    board_.index2rowcol(agent_[0].row_, agent_[0].col_, agent_[0].index);
    agent_[0].setPosition(sf::Vector2f(agent_[0].col_[0] * 16, agent_[0].row_[0] * 16));
    board_.units_[agent_[0].index] = 1;

    // Determinist Agent
    agent_[1].init(16.0f,
      { 00.0f,0.0f }, { 0.0f,0.0f }, kDeterministMovement, "../../../data/gfx/agents/allied_engineer.bmp");
    agent_[1].index = board_.randomWalkablePatternTile(&agent_[1]);
    board_.index2rowcol(agent_[1].row_, agent_[1].col_, agent_[1].index);
    agent_[1].setPosition(sf::Vector2f(agent_[1].col_[0] * 16, agent_[1].row_[0] * 16));
    board_.units_[agent_[1].index] = 1;

    // Patron Agent
    agent_[2].init(16.0f,
      { 00.0f,0.0f }, { 0.0f,0.0f }, kPattern, "../../../data/gfx/agents/allied_medic.bmp");
    agent_[2].index = board_.randomWalkablePatternTile(&agent_[2]);
    board_.index2rowcol(agent_[2].row_, agent_[2].col_, agent_[2].index);
    agent_[2].setPosition(sf::Vector2f(agent_[2].col_[0] * 16, agent_[2].row_[0] * 16));
    board_.units_[agent_[2].index] = 1;

    // Pac-Man Agent
    agent_[3].init(16.0f,
      { 00.0f,0.0f }, { 0.0f,0.0f }, kTrackingMovement, "../../../data/gfx/agents/allied_flag.bmp");
    agent_[3].index = board_.randomWalkableTile();
    board_.index2rowcol(agent_[3].row_, agent_[3].col_, agent_[3].index);
    agent_[3].setPosition(sf::Vector2f(agent_[3].col_[0] * 16, agent_[3].row_[0] * 16));
    board_.units_[agent_[3].index] = 1;

    // Agent
    player_.init(16.0f,
      { 00.0f,0.0f }, { 0.0f,0.0f }, kNone, "../../../data/gfx/agents/axis_soldier.bmp");
    player_.index = board_.randomWalkableTile();
    board_.index2rowcol(player_.row_, player_.col_, player_.index);
    player_.setPosition(sf::Vector2f(player_.col_[0] * 16, player_.row_[0] * 16));
    board_.units_[player_.index] = 1;

    //texture.loadFromFile("../../../data/gfx/maps/map_03_960x704_cost.png");
    texture.loadFromFile("../../../data/gfx/maps/map_03_960x704_layout ABGS.png");
    sprite.setTexture(texture);
    sprite.setScale(1.0f, 1.0f);
}

void TitleScene::update(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window,int dest) {
	
	system("cls");
	
	for (int i = 0; i < 4; ++i)
	{
		agent_[i].update(deltaTime, myinput, &board_,player_.index);	
	}
	board_.debugPrint();
	
    //printf("X:%f                Y:%f          Index:%d\n", agent_.position_.x, agent_.position_.y,agent_.index);
}

void TitleScene::updateRandomMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window)
{
  for (int i = 0; i < 4; ++i)
  {
    if (agent_[i].typeMovement == kRandomMovement)
    {
      agent_[i].update(deltaTime, myinput, &board_, player_.index);
    }
  }
  player_.update(deltaTime, myinput, &board_, player_.index);
  system("cls");
  board_.debugPrint();
}

void TitleScene::updateDeterministMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window)
{
  for (int i = 0; i < 4; ++i)
  {
    if (agent_[i].typeMovement == kDeterministMovement)
    {
      agent_[i].update(deltaTime, myinput, &board_, player_.index);
    }
  }
  player_.update(deltaTime, myinput, &board_, player_.index);
}

void TitleScene::updatePatronMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window)
{
  for (int i = 0; i < 4; ++i)
  {
    if (agent_[i].typeMovement == kPattern)
    {
      agent_[i].update(deltaTime, myinput, &board_, player_.index);
    }
  }

  player_.update(deltaTime, myinput, &board_, player_.index);
}

void TitleScene::updatePacManMovement(sf::Time deltaTime, Input& myinput, sf::RenderWindow& window,int dest)
{
  for (int i = 0; i < 4; ++i)
  {
    if (agent_[i].typeMovement == kTrackingMovement)
    {
      agent_[i].update(deltaTime, myinput, &board_, player_.index);
    }
  }

  player_.update(deltaTime, myinput, &board_, player_.index);
}

void TitleScene::draw(sf::RenderWindow& window) {
	
    window.draw(sprite);
	
    for (int i = 0; i < 4; ++i)
    {
		agent_[i].draw(window);
    }

    player_.draw(window);
}

TitleScene::~TitleScene() {
   
}
