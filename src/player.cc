/**
* @author Alejandro Sanchez Gimeno
* @date 25 Oct 2019
* @copyright 2019 Alejandro Sanchez Gimeno
* @brief Player class.
*/
#include "player.h"
#include "board.h"

Player::Player() {
    init();
}

Player::Player(const Player& o) {
    position_.x = o.position_.x;
    position_.y = o.position_.y;
    velocity_.x = o.velocity_.x;
    velocity_.y = o.velocity_.y;
    sprite_ = o.sprite_;  
}

Player::~Player() {
    delete(texture_);
    texture_ = nullptr;
    delete(sprite_);
    sprite_ = nullptr;
}

void Player::init() {

    moveSpeed_ = 0;
    position_.x = 0;
    position_.y = 0;
    velocity_.x = 0;
    velocity_.y = 0;
    row_[0] = 0;
    col_[0] = 0;
    index = 0;
    typeMovement = kRandomMovement;

    texture_ = new sf::Texture();
    sprite_ = new sf::Sprite();
}

void Player::init(int moveSpeed, sf::Vector2f position,
    sf::Vector2f velocity, const char* file_name) {

    moveSpeed_ = moveSpeed;
    position_.x = position.x;
    position_.y = position.y;
    velocity_.x = velocity.x;
    velocity_.y = velocity.y;
    row_[0] = 0;
    col_[0] = 0;
    index = 0;
    typeMovement = kTrackingMovement;
    pathChosen = false;
    direction = -1;

	patternsArray->push_back(kGoForward);
    patternsArray->push_back(kGoForward);
    patternsArray->push_back(kTurnRight);
    patternsArray->push_back(kTurnRight);
    patternsArray->push_back(kBackwards);
    patternsArray->push_back(kBackwards);
    patternsArray->push_back(kTurnLeft);
    patternsArray->push_back(kTurnLeft);

    direction = kUp;

    step = 0;
	
    if (file_name != NULL) {
        texture_->loadFromFile(file_name);
        sprite_->setTexture(*texture_);
    }

    sprite_->setScale({ 1.0f,1.0f });

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

    sprite_->move({ pos.x,pos.y });
}

void Player::randomMovement(sf::Time deltaTime, Input& input, Board* board)
{
    bool found = false;

    while (!found)
    {
        const auto random = rand() % 4;

        if (random == 0 && board->checkUnitMovement(0, index, board->north(index)))
        {
            board->moveUnit(0, index, board->north(index));
            direction = kUp;
            velocity_.y = -moveSpeed_;
            velocity_.x = 0.0f;
            index = board->north(index);
            found = true;

        }
        else if (random == 1 && board->checkUnitMovement(0, index, board->west(index)))
        {
            board->moveUnit(0, index, board->west(index));
            direction = kLeft;
            velocity_.x = -moveSpeed_;
            velocity_.y = 0.0f;
            index = board->west(index);
            found = true;

        }
        else if (random == 2 && board->checkUnitMovement(0, index, board->south(index)))
        {
            board->moveUnit(0, index, board->south(index));
            direction = kDown;
            velocity_.y = moveSpeed_;
            velocity_.x = 0.0f;
            index = board->south(index);
            found = true;

        }
        else if (random == 3 && board->checkUnitMovement(0, index, board->east(index)))
        {
            board->moveUnit(0, index, board->east(index));
            direction = kRight;
            velocity_.x = moveSpeed_;
            velocity_.y = 0.0f;
            index = board->east(index);
            found = true;
        }
        else
        {
            direction = kDirectionNone;
            velocity_.x = 0.0f;
            velocity_.y = 0.0f;
            found = false;
        }
    }

    movePosition({ velocity_.x , velocity_.y });
}

void Player::deterministMovement(sf::Time deltaTime, Input& input, Board* board)
{	
    if (!pathChosen)
    {
        direction = rand() % 4;
        pathChosen = true;
    }
   
    if (direction == kUp)
    {
        board->moveUnit(0, index, board->north(index));
        velocity_.y = -moveSpeed_;
        velocity_.x = 0.0f;
        index = board->north(index);
    }
    else if (direction == kLeft)
    {
        board->moveUnit(0, index, board->west(index));
        velocity_.x = -moveSpeed_;
        velocity_.y = 0.0f;
        index = board->west(index);
    }
    else if (direction == kDown)
    {
        board->moveUnit(0, index, board->south(index));
        velocity_.y = moveSpeed_;
        velocity_.x = 0.0f;
        index = board->south(index);
    }
    else if (direction == kRight)
    {
        board->moveUnit(0, index, board->east(index));
        velocity_.x = moveSpeed_;
        velocity_.y = 0.0f;
        index = board->east(index);     
    }

    movePosition({ velocity_.x , velocity_.y });
}

void Player::patternMovement(sf::Time deltaTime, Input& input, Board* board)
{
	switch (patternsArray->at(step))
	{
		case kGoForward:
			board->moveUnitWithoutCheck(0,index,board->north(index));
            direction = kUp;
            velocity_.y = -moveSpeed_;
            velocity_.x = 0.0f;
            index = board->north(index);
            step++;
            break;
		
        case kTurnRight:
            board->moveUnitWithoutCheck(0, index, board->east(index));
            direction = kRight;
            velocity_.x = moveSpeed_;
            velocity_.y = 0.0f;
            index = board->east(index);
            step++;
            break;
		
        case kTurnLeft:
            board->moveUnitWithoutCheck(0, index, board->west(index));
            direction = kLeft;
            velocity_.x = -moveSpeed_;
            velocity_.y = 0.0f;
            index = board->west(index);
            step++;
			break;

        case kBackwards:
            board->moveUnitWithoutCheck(0, index, board->south(index));
            direction = kDown;
            velocity_.y = moveSpeed_;
            velocity_.x = 0.0f;
            index = board->south(index);
            step++;
			break;
		
        default:
            break;	
	}

	//TODO step up to size of patternsArray
	
	if (step >= patternsArray->size())
	{
        step = 0;
	}
	
    movePosition({ velocity_.x , velocity_.y });
	
}

void Player::trackingMovement(sf::Time deltaTime, Input& input, Board* board, int dest)
{
	if (direction == kDirectionNone)
	{
		direction = rand() % 4;
	}

    int directions[4];
	
    directions[0] = board->north(index);
    directions[1] = board->west(index);
    directions[2] = board->south(index);
    directions[3] = board->east(index);
	
    int distances[4] = {0};

    const int back = (direction + 2) % 4;

    directions[back] = -1;

	// Non walkable
	
    for (int i = 0; i < 4; ++i)
    {
	    if (directions[i] != -1)
	    {
		    if (board->checkUnitMovement(0,index,directions[i]) == false)
		    {
                directions[i] = -1;
            }
	    }
    }

	// Check distances

    for (int i = 0; i < 4; ++i)
    {
	    if (directions[i] != -1)
	    {
            distances[i] = board->manhattanDistance(directions[i], dest);
	    }
    }

	// Chose direction

    int next = 4;

    int min_distance = board->width_ * board->height_;

    for (int i = 0; i < 4; ++i)
    {
	    if (directions[i] != -1)
	    {
		    if (distances[i] < min_distance)
		    {
                min_distance = distances[i];
                next = i;
		    }
	    }
    }
	
    direction = next;

    switch (direction)
    {
		case kUp:
    		board->moveUnitWithoutCheck(0, index, board->north(index));
			direction = kUp;
			velocity_.y = -moveSpeed_;
			velocity_.x = 0.0f;
			index = board->north(index);
			break;
    	
        case kLeft:
            board->moveUnitWithoutCheck(0, index, board->west(index));
            direction = kLeft;
            velocity_.x = -moveSpeed_;
            velocity_.y = 0.0f;
            index = board->west(index);
            break;

        case kDown:
            board->moveUnitWithoutCheck(0, index, board->south(index));
            direction = kDown;
            velocity_.y = moveSpeed_;
            velocity_.x = 0.0f;
            index = board->south(index);
            break;

        case kRight:
            board->moveUnitWithoutCheck(0, index, board->east(index));
            direction = kRight;
            velocity_.x = moveSpeed_;
            velocity_.y = 0.0f;
            index = board->east(index);
            break;

        case kDirectionNone:
            direction = kDirectionNone;
            velocity_.x = 0.0f;
            velocity_.y = 0.0f;
            break;
    		  	
        default:
            break;   		
    }

    movePosition({ velocity_.x , velocity_.y });
}


void Player::move(sf::Time deltaTime, Input& input,Board* board)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
        typeMovement = kDeterministMovement;
		
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        typeMovement = kRandomMovement;
    }
	
	switch (typeMovement)
	{
		case kRandomMovement: randomMovement(deltaTime, input, board);
			break;
		
        case kPathFinding:
			break;
		
        case kPattern: patternMovement(deltaTime, input, board);
            break;

        case kDeterministMovement: deterministMovement(deltaTime, input, board);
            break;

        case kTrackingMovement: trackingMovement(deltaTime, input, board, 124);
			break;
		
        case kNone:
            break;
		
        default:
			break;
	}
    
}

void Player::update(sf::Time deltaTime, Input& input,Board* board) {
	
    move(deltaTime,input,board);
}

void Player::draw(sf::RenderWindow& window) {
    
        window.draw(*sprite_);
    
}
