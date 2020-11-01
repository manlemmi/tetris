#ifndef __FIGURE_I__
#define __FIGURE_I__

#include "Tetromino.h"

class FigureI : public Tetromino
{
public:
	FigureI(int x, int y);
	void rotate() & override;
	void setPrevState() & override;

private:
	bool secondTurn;
};

#endif  __FIGURE_I__