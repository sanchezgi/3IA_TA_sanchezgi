/**
* @author Alejandro Sanchez Gimeno
* @date 30 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Game class that manages all the scenes.
*/

#include "game.h"
#include "mainscene.h"
#include "gamemanager.h"

void Game::init() {
    GameManager& GM = GameManager::Instance();
	
    GameManager::Instance().w_width_ = 1920;
    GameManager::Instance().w_height_ = 1080;

    window_.init(1920, 1080);
    
    srand(time(NULL));
    window_.frame(60);

    Scene* intro = new TitleScene();
    newScene(intro);

    GameManager::Instance().num_scene_ = 1;
    GameManager::Instance().load_ = true;
    InitInput(input_);
}

void Game::mainLoop() {
    while (window_.isOpened())
    {
        GameManager::Instance().dt_clock_.restart();
        checkScene();
        sf::Event event;
        while (window_.window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window_.destroy();
            }
            CheckInput(input_, event);
        }      
        input();
        update(GameManager::Instance().dt_clock_.getElapsedTime().asSeconds());
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

void Game::input() {

}
void Game::update(float deltaTime) {
    current_scene_->update(GameManager::Instance().dt_clock_.getElapsedTime().asSeconds(), input_, window_.window_);
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
