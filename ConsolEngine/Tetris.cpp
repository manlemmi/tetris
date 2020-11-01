#include "Tetris.h"
#include <ctime>

Tetris::Tetris() : BaseApp(26, 26),
currentFigure(TetrominoFactory::createTetromino(2, 8)),
nextFigure(TetrominoFactory::createTetromino(2, 8)),
moveable(true),
counterFigureBricks(0),
changePreview(true),
counterLandedBricks(0),
score(0),
scoreString(L"Score:"),
tickCounter(0),
currentTick(0)
{
	//drawing borders
	for(int i = 0; i < 26; i++)
	{
		SetChar(0, i, L'#');
		SetChar(25, i, L'#');
		SetChar(i, 0, L'#');
		SetChar(i, 26, L'#');
		SetChar(i, 22, L'#');

		if(i < 22)
		{
			SetChar(16, i, L'#');
		}

		SetChar(4, 24, L'>');

		if(i >= 1 && i <= 15)
		{
			for(int j = 1; j < 22; j++)
			{
				SetChar(i, j, L'.');
			}

		}

	}

	for(int i = 0; i < scoreString.size(); i++)
	{
		SetChar(5 + i, 24, scoreString.at(i));
	}

	scoreToString = to_wstring(score);

	for(int i = 0; i < scoreToString.size(); i++)
	{
		SetChar(13 + i, 24, scoreToString.at(i));
	}
}

void Tetris::UpdateF(float deltaTime)
{
	++tickCounter;

	if(currentFigure->isControllable())
	{
		currentTick = averageSpeed;
	} else
	{
		currentTick = uncontrollableSpeed;
	}

	if(tickCounter == currentTick)
	{
		for(int i = 0; i < TETROMINO_SIZE; i++)
		{
			if(currentFigure->getCurrentCoords().at(i)->getCoordX() == bottomBorder - 1)
			{
				currentFigure->setLanded();
				break;
			}
			for(int j = 0; j < landedBricks.size(); j++)
			{
				if(currentFigure->getCurrentCoords().at(i)->getCoordY() == landedBricks.at(j)->getCoordY() &&
				   currentFigure->getCurrentCoords().at(i)->getCoordX() == landedBricks.at(j)->getCoordX() - 1)
				{
					currentFigure->setLanded();
					break;
				}
			}
			if(currentFigure->isLanded())
			{
				break;
			}
		}

		if(currentFigure->isLanded())
		{
			for(int i = 0; i < TETROMINO_SIZE; i++)
			{
				if(currentFigure->getCurrentCoords().at(i)->getCoordX() <= 1)
				{
					exit(0);
				}
			}

			for(int i = 0; i < TETROMINO_SIZE; i++)
			{
				landedBricks.emplace_back(std::move(currentFigure->getCurrentCoords().at(i)));
			}

			currentFigure = std::move(nextFigure);
			nextFigure = TetrominoFactory::createTetromino(2, 8);

			changePreview = true;

			for(int i = 0; i < landedBricks.size(); i++)
			{
				SetChar(landedBricks.at(i)->getCoordY(),
						landedBricks.at(i)->getCoordX(), L'.');
			}

			counterLandedBricks = 0;

			for(int i = FIELD_HEIGHT; i > 0; i--)
			{
				for(int j = 0; j < landedBricks.size(); j++)
				{
					if(landedBricks.at(j)->getCoordX() == i)
						counterLandedBricks++;

					if(counterLandedBricks == 15)
					{
						for(int k = 0; k < landedBricks.size(); k++)
						{
							if(landedBricks.at(k)->getCoordX() == i)
							{
								landedBricks.erase(landedBricks.begin() + k);
								k = 0;
							}
						}

						for(int k = 0; k < landedBricks.size(); k++)
						{
							if(landedBricks.at(k)->getCoordX() == i)
							{
								landedBricks.erase(landedBricks.begin() + k);
								k = 0;
							}
						}

						for(int k = 0; k < landedBricks.size(); k++)
						{
							if(landedBricks.at(k)->getCoordX() < i)
							{
								landedBricks.at(k)->falling();
							}
						}

						score += 100;

						i = FIELD_HEIGHT;
					}
				}
				counterLandedBricks = 0;
			}

			scoreToString = to_wstring(score);

			for(int i = 0; i < scoreToString.size(); i++)
			{
				SetChar(13 + i, 24, scoreToString.at(i));
			}

			for(int i = 0; i < landedBricks.size(); i++)
			{
				SetChar(landedBricks.at(i)->getCoordY(),
						landedBricks.at(i)->getCoordX(), L'▣');
			}

		} else
		{
			currentFigure->falling();
		}

		tickCounter = 0;
	}

	if(changePreview)
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				SetChar(i + 19, j + 3, L' ');
			}
		}

		for(int i = 0; i < TETROMINO_SIZE; i++)
		{
			SetChar(nextFigure->getPrevCoords().at(i)->getCoordY() + 12,
					nextFigure->getCurrentCoords().at(i)->getCoordX() + 2, L'▣');
		}

		changePreview = false;
	}

	for(int i = 0; i < TETROMINO_SIZE; i++)
	{
		SetChar(currentFigure->getPrevCoords().at(i)->getCoordY(),
				currentFigure->getPrevCoords().at(i)->getCoordX(), L'.');
		SetChar(currentFigure->getCurrentCoords().at(i)->getCoordY(),
				currentFigure->getCurrentCoords().at(i)->getCoordX(), L'▣');
	}

	currentFigure->backup();
}

void Tetris::KeyPressed(int btnCode)
{
	if(btnCode == 75 && currentFigure->isControllable())
	{
		moveable = true;
		counterFigureBricks = 0;

		for(int i = 0; i < TETROMINO_SIZE; i++)
		{
			if(currentFigure->getCurrentCoords().at(i)->getCoordY() > leftBorder)
				counterFigureBricks++;

			for(int j = 0; j < landedBricks.size(); j++)
			{
				if(currentFigure->getCurrentCoords().at(i)->getCoordY() - 1 == landedBricks.at(j)->getCoordY() &&
				   currentFigure->getCurrentCoords().at(i)->getCoordX() == landedBricks.at(j)->getCoordX())
					moveable = false;

				if(!moveable)
				{
					break;
				}
			}

			if(!moveable)
			{
				break;
			}

		}

		if(counterFigureBricks == TETROMINO_SIZE && moveable)
		{
			currentFigure->movingLeft();
		}

	} else if(btnCode == 77 && currentFigure->isControllable()) //right arrow
	{
		moveable = true;
		counterFigureBricks = 0;

		for(int i = 0; i < TETROMINO_SIZE; i++)
		{
			if(currentFigure->getCurrentCoords().at(i)->getCoordY() < rightBorder - 1)
				counterFigureBricks++;

			for(int j = 0; j < landedBricks.size(); j++)
			{
				if(currentFigure->getCurrentCoords().at(i)->getCoordY() + 1 == landedBricks.at(j)->getCoordY() &&
				   currentFigure->getCurrentCoords().at(i)->getCoordX() == landedBricks.at(j)->getCoordX())
					moveable = false;

				if(!moveable)
				{
					break;
				}
			}

			if(!moveable)
			{
				break;
			}
		}

		if(counterFigureBricks == TETROMINO_SIZE && moveable)
		{
			currentFigure->movingRight();
		}

	} else if(btnCode == 32 && currentFigure->isControllable())
	{
		moveable = true;
		counterFigureBricks = 0;

		currentFigure->rotate();

		for(int i = 0; i < TETROMINO_SIZE; i++)
		{
			if(currentFigure->getCurrentCoords().at(i)->getCoordY() <= rightBorder - 1 &&
			   currentFigure->getCurrentCoords().at(i)->getCoordY() >= leftBorder &&
			   currentFigure->getCurrentCoords().at(i)->getCoordX() <= bottomBorder - 1)
				counterFigureBricks++;

			for(int j = 0; j < landedBricks.size(); j++)
			{
				if(currentFigure->getCurrentCoords().at(i)->getCoordY() == landedBricks.at(j)->getCoordY() &&
				   currentFigure->getCurrentCoords().at(i)->getCoordX() == landedBricks.at(j)->getCoordX())
					moveable = false;

				if(!moveable)
				{
					break;
				}
			}

			if(!moveable)
			{
				break;
			}
		}

		if(counterFigureBricks != TETROMINO_SIZE || !moveable)
		{
			currentFigure->setPrevState();
		}

	} else if(btnCode == 80 && currentFigure->isControllable()) //down arrow
	{
		currentFigure->setControllable();
		tickCounter = 0;
	}
}


