#ifndef __TETROMINO__
#define __TETROMINO__

#include "SingleBrick.h"
#include "globals.h"
#include <array>
#include <memory>

class Tetromino : public Pixel
{
public:
	Tetromino(int x, int y);
	virtual void rotate() & = 0;
	std::array<std::unique_ptr<SingleBrick>, TETROMINO_SIZE>& getPrevCoords();
	std::array<std::unique_ptr<SingleBrick>, TETROMINO_SIZE>& getCurrentCoords();
	std::unique_ptr<SingleBrick>& getCenter();
	void movingRight()&;
	void movingLeft()&;
	void falling()&;
	void backup()&;
	virtual void setPrevState()&;
	bool isControllable()&;
	void setControllable()&;
	bool isLanded()&;
	void setLanded()&;

protected:
	std::array<std::unique_ptr<SingleBrick>, TETROMINO_SIZE> prevCoords;
	std::array<std::unique_ptr<SingleBrick>, TETROMINO_SIZE> currentCoords;
	std::unique_ptr<SingleBrick> prevCenter;//previous center of gravity
	std::unique_ptr<SingleBrick> centerOfGravity;

private:
	bool controllable;
	bool landed;
};

#endif  __TETROMINO__

