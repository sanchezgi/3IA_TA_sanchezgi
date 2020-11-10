/**
* @author Alejandro Sanchez Gimeno
* @date 30 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Game class that manages all the scenes.
*/

#include "game.h"
#include "mainscene.h"
#include "gamemanager.h"

sf::Time TimePerFrame = sf::seconds(1.0f);

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
    //InitInput(input_);

}

void Game::mainLoop(Input& input_) {

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window_.isOpened())
    {
        //sf::Time deltaTime = clock.restart();
        checkScene();
        processEvent(input_);
        //update(deltaTime);
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvent(input_);
            fixedUpdate(TimePerFrame);       	
        }
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
    current_scene_->update(deltaTime, input_, window_.window_);
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
    current_scene_->update(deltaTIme, input_, window_.window_);
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
