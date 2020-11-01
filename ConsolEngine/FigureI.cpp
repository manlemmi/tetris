#include "FigureI.h"

FigureI::FigureI(int x, int y) : Tetromino(x, y), secondTurn(false)
{
	currentCoords.at(0).reset(new SingleBrick(x, y));
	currentCoords.at(1).reset(new SingleBrick(x + 1, y));
	currentCoords.at(2).reset(new SingleBrick(x - 1, y));
	currentCoords.at(3).reset(new SingleBrick(x + 2, y));

	prevCoords.at(0).reset(new SingleBrick(x, y));
	prevCoords.at(1).reset(new SingleBrick(x + 1, y));
	prevCoords.at(2).reset(new SingleBrick(x - 1, y));
	prevCoords.at(3).reset(new SingleBrick(x + 2, y));
}

void FigureI::rotate()&
{
	int a = -1;

	if(!secondTurn)
	{
		a *= -1;
	}

	secondTurn = !secondTurn;

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		if(!(currentCoords.at(i) == centerOfGravity))
		{
			currentCoords.at(i)->setCoordX(centerOfGravity->getCoordX() -
				(prevCoords.at(i)->getCoordY() - centerOfGravity->getCoordY()) * a);

			currentCoords.at(i)->setCoordY(centerOfGravity->getCoordY() +
				(prevCoords.at(i)->getCoordX() - centerOfGravity->getCoordX()) * a);
		}
	}
}

void FigureI::setPrevState()&
{
	Tetromino::setPrevState();
	secondTurn = !secondTurn;
}
