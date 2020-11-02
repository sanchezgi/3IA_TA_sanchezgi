#include <board.h>

Board::Board()
{
	width_ = 0;
	height_ = 0;
}

Board::~Board()
{
	
}

void Board::init(int width, int height)
{
	if (width_>= 0)
	{
		width_ = width;		
	}
	else
	{
		width_ = kBoardMaxSize / 4;
	}

	if (height_ >= 0)
	{
		height_ = height;
	}
	else
	{
		height_ = kBoardMaxSize / 4;
	}

	for (Cell& c : cells_)
	{
		c.value = kTileType_Void;
		c.height = 0;
	}

	for (int& u : units_)
	{
		u = 1;
	}
}

Cell& Board::cell(int row, int col)
{
	//assert if row or col are negative
	
	return cells_[col + row * width_];
}

int Board::north(int idx)
{
	int const index = idx - width_;

	if (index >= 0)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

int Board::east(int idx)
{
	int const index = idx + 1;

	if (index % width_ == 0)
	{
		return  -1;
	}
	else
	{
		return index;
	}
}

int Board::south(int idx)
{
	int const index = idx + width_;

	if (index < width_ * height_)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

int Board::west(int idx)
{
	if (idx % width_ == 0)
	{
		return  -1;
	}
	else
	{
		return idx - 1;
	}
}

uint8_t Board::isWall(int idx)
{
	if (cells_[idx].value == kTileType_Wall)
	{
		return 1;
	}
	return 0;
}

uint8_t Board::isDoor(int idx)
{
	if (cells_[idx].value == kTileType_Door)
	{
		return 1;
	}
	return 0;
}

void Board::index2rowcol(int* row, int* col, int idx)
{
	if (idx < 0 || idx > width_ * height_)
	{
		idx = 0;
	}
	
	*row = idx / width_;
	*col = idx % width_;
}

void Board::saveCSV(const char* csv)
{
	
}

int Board::findUnit(int roster_idx)
{
	for (int idx = 0; idx < width_* height_; ++idx)
	{
		if (units_[idx == roster_idx])
		{
			return  idx;
		}
	}

	return -1;
}

bool Board::checkUnitMovement(int roster_idx, int origin, int dest)
{
	if (dest < 0) return false;
	if (dest >= width_ * height_) return false;
	if (units_[dest] != -1) return  false;

	return  true;
}

void Board::moveUnit(int roster_idx, int origin, int dest)
{
	if (checkUnitMovement(roster_idx, origin, dest)) 
	{
		units_[dest] = units_[origin];
		units_[origin] = -1;
	}
}

void Board::killUnit(int target_idx)
{
	if (target_idx < 0) return;

	int idx = findUnit(target_idx);
	
	if (idx > -1)
	{
		units_[idx] = -1;
	}	
}

int Board::euclideanDistance(int origin, int dest)
{
	int rowOrigin = -1, colOrigin = -1, rowDestiny = -1, colDestiny = -1;
	index2rowcol(&rowOrigin, &colOrigin, origin);
	index2rowcol(&rowDestiny, &colDestiny, origin);

	if (rowOrigin == -1 || colOrigin == -1 || rowDestiny == -1 || rowDestiny == -1)
	{
		return -1;
	}
	
	return abs(rowDestiny - rowOrigin) + abs(colDestiny - colOrigin);
}

std::stack<int> Board::pathFind(int start, int target, int limit)
{
	std::stack<int> myStack;
	return myStack;
}

int Board::randomWalkableTile()
{
	int random_index = rand() % (width_ * height_);
	
	while (isWall(random_index) == 1)
	{
		random_index = rand() % (width_ * height_);
	}
	return random_index;
}

void Board::debugPrint()
{
	for (int row = 0; row < height_; ++row)
	{
		for (int col = 0; col < width_; ++col)
		{
			if (cell(row,col).value == kTileType_Normal)
			{
				printf(".");
			}else if(cell(row,col).value == kTileType_Wall){
				printf("#");
			}else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
