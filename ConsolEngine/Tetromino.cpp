#include "Tetromino.h"

Tetromino::Tetromino(int x, int y) : centerOfGravity(new SingleBrick(x, y)), prevCenter(new SingleBrick(x, y)), controllable(true), landed(false) {}

std::array<std::unique_ptr<SingleBrick>, TETROMINO_SIZE>& Tetromino::getPrevCoords()
{
	return prevCoords;
}

std::array<std::unique_ptr<SingleBrick>, TETROMINO_SIZE>& Tetromino::getCurrentCoords()
{
	return currentCoords;
}

std::unique_ptr<SingleBrick>& Tetromino::getCenter()
{
	return centerOfGravity;
}

void Tetromino::movingRight()&
{

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		currentCoords.at(i)->movingRight();
	}

	centerOfGravity->movingRight();

	//bool moveable = true;
/*
	for (int i = 0; i < TETROMINO_SIZE; i++) {

		if (GetChar(currentCoords.at(i)->getCoordX() + 1,
			currentCoords.at(i)->getCoordY()) != '.') {
			moveable = false;
			break;
		}

	}

	if (moveable) {

		/*if (GetChar(centerOfGravity->getCoordX() + 1, centerOfGravity->getCoordY()) != '.') {
			moveable = false;
		}*/

		/*	}

			if (moveable) {
				for (int i = 0; i < TETROMINO_SIZE; i++) {
					currentCoords.at(i)->movingRight();
				}

				centerOfGravity->movingRight();
			}*/

}

void Tetromino::movingLeft()&
{

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		currentCoords.at(i)->movingLeft();
	}

	centerOfGravity->movingLeft();

}

void Tetromino::falling()&
{

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		currentCoords.at(i)->falling();
	}

	centerOfGravity->falling();

}

void Tetromino::backup()&
{

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		prevCoords.at(i)->setCoordX(currentCoords.at(i)->getCoordX());
		prevCoords.at(i)->setCoordY(currentCoords.at(i)->getCoordY());
	}

	prevCenter->setCoordX(centerOfGravity->getCoordX());
	prevCenter->setCoordY(centerOfGravity->getCoordY());

}

void Tetromino::setPrevState()&
{

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		currentCoords.at(i)->setCoordX(prevCoords.at(i)->getCoordX());
		currentCoords.at(i)->setCoordY(prevCoords.at(i)->getCoordY());
	}

	centerOfGravity->setCoordX(prevCenter->getCoordX());
	centerOfGravity->setCoordY(prevCenter->getCoordY());

}

bool Tetromino::isControllable()&
{
	return controllable;
}

void Tetromino::setControllable()&
{
	controllable = !controllable;
}

bool Tetromino::isLanded()&
{
	return landed;
}

void Tetromino::setLanded()&
{
	landed = true;
}
