#ifndef __FIGURE_Z__
#define __FIGURE_Z__

#include "Tetromino.h"

class FigureZ : public Tetromino
{
public:
	FigureZ(int x, int y);
	void rotate() & override;
	void setPrevState() & override;

private:
	bool secondTurn;
};

#endif  __FIGURE_Z__
