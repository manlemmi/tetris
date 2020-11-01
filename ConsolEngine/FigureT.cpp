#include "FigureT.h"

FigureT::FigureT(int x, int y) : Tetromino(x, y)
{
	currentCoords.at(0).reset(new SingleBrick(x, y));
	currentCoords.at(1).reset(new SingleBrick(x, y - 1));
	currentCoords.at(2).reset(new SingleBrick(x, y + 1));
	currentCoords.at(3).reset(new SingleBrick(x - 1, y));

	prevCoords.at(0).reset(new SingleBrick(x, y));
	prevCoords.at(1).reset(new SingleBrick(x, y - 1));
	prevCoords.at(2).reset(new SingleBrick(x, y + 1));
	prevCoords.at(3).reset(new SingleBrick(x - 1, y));
}

void FigureT::rotate()&
{
	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		if(!(currentCoords.at(i) == centerOfGravity))
		{

			currentCoords.at(i)->setCoordX(centerOfGravity->getCoordX() -
				(prevCoords.at(i)->getCoordY() - centerOfGravity->getCoordY()));

			currentCoords.at(i)->setCoordY(centerOfGravity->getCoordY() +
				(prevCoords.at(i)->getCoordX() - centerOfGravity->getCoordX()));
		}
	}
}
