/**
* @author Alejandro Sanchez Gimeno
* @date 2020 - 2021
* @copyright 2020 Alejandro Sanchez Gimeno
* @brief Game class that manages all the scenes.
*/

#include "game.h"
#include "mainscene.h"
#include "gamemanager.h"

sf::Time TimePerFrameRandom = sf::seconds(0.75f);
sf::Time TimePerFrameDeterminist = sf::seconds(1.0f);
sf::Time TimePerFramePattern = sf::seconds(1.25f);
sf::Time TimePerFramePacMan = sf::seconds(1.5f);
sf::Time TimePerFrameInput = sf::seconds(0.0f);

void Game::init() {
    GameManager& GM = GameManager::Instance();

    GameManager::Instance().w_width_ = 960;
    GameManager::Instance().w_height_ = 704;

    window_.init(960 , 704);
    
    srand(time(NULL));
    window_.frame(60);

    Scene* intro = new TitleScene();
    newScene(intro);

    GameManager::Instance().num_scene_ = 1;
    GameManager::Instance().load_ = true;
}

void Game::mainLoop(Input& input_) {

    sf::Clock clockRandom;
    sf::Clock clockDeterminist;
    sf::Clock clockPattern;
    sf::Clock clockPacMAn;
    sf::Clock clockInput;

    sf::Time timeSinceLastUpdateRandom = sf::Time::Zero;
    sf::Time timeSinceLastUpdateDeterminist = sf::Time::Zero;
    sf::Time timeSinceLastUpdatePattern = sf::Time::Zero;
    sf::Time timeSinceLastUpdatePacMan = sf::Time::Zero;
    sf::Time timeSinceLastUpdateInput = sf::Time::Zero;

    while (window_.isOpened())
    {
        checkScene();
        processEvent(input_);

        timeSinceLastUpdateRandom += clockRandom.restart();
        timeSinceLastUpdateDeterminist += clockDeterminist.restart();
        timeSinceLastUpdatePattern += clockPattern.restart();
        timeSinceLastUpdatePacMan += clockPacMAn.restart();
        timeSinceLastUpdateInput += clockInput.restart();

        if (timeSinceLastUpdateRandom > TimePerFrameRandom)
        {
          timeSinceLastUpdateRandom -= TimePerFrameRandom;
          fixedUpdateRandom(TimePerFrameRandom);
        }

        if (timeSinceLastUpdateDeterminist > TimePerFrameDeterminist)
        {
          timeSinceLastUpdateDeterminist -= TimePerFrameDeterminist;
          fixedUpdateDeterminist(TimePerFrameDeterminist);
        }

        if (timeSinceLastUpdatePattern > TimePerFramePattern)
        {
          timeSinceLastUpdatePattern -= TimePerFramePattern;
          fixedUpdatePattern(TimePerFramePattern);
        }

        if (timeSinceLastUpdatePacMan > TimePerFramePacMan)
        {
          timeSinceLastUpdatePacMan -= TimePerFramePacMan;
          fixedUpdatePacMan(TimePerFramePacMan);
        }
      
        fixedUpdateInput(TimePerFrameInput);
        
        draw();
    }
}

void Game::finish() {

    GameManager& GM = GameManager::Instance();

    window_.destroy();
    delete(current_scene_);

}

Scene* Game::newScene(Scene* scene) {
    Scene* aux = current_scene_;
    scene->init();
    current_scene_ = scene;
    return aux;
}

void Game::input(Input& input)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        input_.IsMovingUp = true;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        input_.IsMovingDown = true;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        input_.IsMovingLeft = true;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        input_.IsMovingRight = true;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window_.window_.close();
    else
    {
        input_.IsMovingDown = false;
        input_.IsMovingUp = false;
        input_.IsMovingLeft = false;
        input_.IsMovingRight = false;
    }	
}
void Game::update(sf::Time deltaTime)
{
    current_scene_->update(deltaTime, input_, window_.window_,0);
}

void Game::processEvent(Input& input_)
{
    sf::Event event;
    while (window_.window_.pollEvent(event))
    {
        input(input_);
    }
}

void Game::fixedUpdate(sf::Time deltaTIme)
{
    current_scene_->update(deltaTIme, input_, window_.window_,0);
}

void Game::fixedUpdateRandom(sf::Time deltaTIme)
{
  current_scene_->updateRandomMovement(deltaTIme, input_, window_.window_);
}

void Game::fixedUpdateDeterminist(sf::Time deltaTIme)
{
  current_scene_->updateDeterministMovement(deltaTIme, input_, window_.window_);
}

void Game::fixedUpdatePattern(sf::Time deltaTIme)
{
  current_scene_->updatePatronMovement(deltaTIme, input_, window_.window_);
}

void Game::fixedUpdatePacMan(sf::Time deltaTIme)
{
  current_scene_->updatePacManMovement(deltaTIme, input_, window_.window_,0);
}

void Game::fixedUpdateInput(sf::Time deltaTIme)
{
  current_scene_->updateInputMovement(deltaTIme, input_, window_.window_, 0);
}

void Game::draw() {
    window_.clear();
    current_scene_->draw(window_.window_);
    window_.display();
}

void Game::checkScene() {
    if (GameManager::Instance().load_ == false) {
        delete current_scene_;
        current_scene_ = nullptr;
        if (GameManager::Instance().num_scene_ == 1) {
            Scene* intro = new TitleScene();
            newScene(intro);
        }
        if (GameManager::Instance().num_scene_ == 2) {
            Scene* title = new TitleScene();
            newScene(title);
        }
        GameManager::Instance().load_ = true;
    }
}
