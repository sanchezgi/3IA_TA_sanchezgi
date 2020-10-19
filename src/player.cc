/**
* @author Alejandro Sanchez Gimeno
* @date 25 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Player class.
*/
#include"player.h"

Player::Player() {
    init();
}

Player::Player(const Player& o) {
    position_.x = o.position_.x;
    position_.y = o.position_.y;
    velocity_.x = o.velocity_.x;
    velocity_.y = o.velocity_.y;
    sprite_ = o.sprite_;
    elapsed_ = o.elapsed_;
    
}

Player::~Player() {
    delete(texture_);
    texture_ = nullptr;
    delete(sprite_);
    sprite_ = nullptr;
}

void Player::init() {
    life_ = 0;
    gravity_ = 0;
    jumpSpeed_ = 0;
    moveSpeed_ = 0;
    position_.x = 0;
    position_.y = 0;
    velocity_.x = 0;
    velocity_.y = 0;

    texture_ = new sf::Texture();
    sprite_ = new sf::Sprite();
}

void Player::init(int life, int gravity, int jumpSpeed, int moveSpeed, sf::Vector2f position,
    sf::Vector2f velocity, const char* file_name) {

    life_ = life;
    gravity_ = gravity;
    jumpSpeed_ = jumpSpeed;
    moveSpeed_ = moveSpeed;
    position_.x = position.x;
    position_.y = position.y;
    velocity_.x = velocity.x;
    velocity_.y = velocity.y;

    if (file_name != NULL) {
        texture_->loadFromFile(file_name);
        sprite_->setTexture(*texture_);
    }

    sprite_->setScale({ 20.0f,20.0f });

    sf::IntRect rect = sprite_->getTextureRect();

 
    sprite_->setTextureRect(rect);
}

void Player::setPosition(sf::Vector2f pos) {
    sprite_->setPosition({ pos.x,pos.y });
}

sf::Vector2f Player::getPosition() {
    return sprite_->getPosition();
}

void Player::movePosition(sf::Vector2f pos) {

    sf::Vector2f position = sprite_->getPosition();

    position_.x = position.x;
    position_.y = position.y;
    sf::IntRect rect = sprite_->getTextureRect();

    sprite_->move({ pos.x,pos.y });
}


void Player::move(Input& input) {
 
        static int timer = 0;
        sf::Vector2f pos = sprite_->getPosition();
        sf::IntRect rect = sprite_->getTextureRect();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        	
            velocity_.x = moveSpeed_;
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity_.x = - moveSpeed_;
        }
        else {
            velocity_.x = 0;
        }
	
        movePosition({ velocity_.x, velocity_.y });
    

}

void Player::update(Input& input) {

    move(input);
}

void Player::draw(sf::RenderWindow& window) {
    
        window.draw(*sprite_);
    
}
