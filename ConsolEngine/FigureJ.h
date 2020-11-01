#ifndef __FIGURE_J__
#define __FIGURE_J__

#include "Tetromino.h"

class FigureJ : public Tetromino
{
public:
	FigureJ(int x, int y);
	void rotate() & override;
};

#endif  __FIGURE_J__