#ifndef __BOARD_LOADER_H__
#define __BOARD_LOADER_H__ 1

#include <board.h>
#include <common_def.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


static ErrorCode BoardFromImage(Board* board, const char* filename)
{
	if (filename == nullptr) return kErrorCode_File;
	if (board == nullptr) return kErrorCode_DataNullPointer;

	sf::Texture texture;
	sf::Sprite sprite;

	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sf::Image image =  texture.copyToImage();
	sf::IntRect rectangle = sprite.getTextureRect();
	sprite.setTextureRect(rectangle);

	for (int i = 0; i < rectangle.width; ++i)
	{
		for (int j = 0; j < rectangle.height; ++j)
		{
			sf::Color color = image.getPixel(i, j);

			if (color.r == 0xFF && color.g == 0xFF && color.b == 0xFF)
			{
				board->cell(j, i).value = kTileType_Normal;
			}else if(color.r == 0x00 && color.g == 0x00 && color.b == 0x00)
			{
				board->cell(j, i).value = kTileType_Wall;
			}else
			{
				board->cell(j, i).value = kTileType_Wall;
			}
		}
	}
}
#endif


