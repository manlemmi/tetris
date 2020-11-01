#ifndef __FIGURE_L__
#define __FIGURE_L__

#include "Tetromino.h"

class FigureL : public Tetromino
{
public:
	FigureL(int x, int y);
	void rotate() & override;
};

#endif  __FIGURE_L__
