#ifndef __FIGURE_S__
#define __FIGURE_S__

#include "Tetromino.h"

class FigureS : public Tetromino
{
public:
	FigureS(int x, int y);
	void rotate() & override;
	void setPrevState() & override;

private:
	bool secondTurn;
};

#endif  __FIGURE_S__