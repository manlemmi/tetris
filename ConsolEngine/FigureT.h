#ifndef __FIGURE_T__
#define __FIGURE_T__

#include "Tetromino.h"

class FigureT : public Tetromino
{
public:
	FigureT(int x, int y);
	void rotate() & override;
};

#endif  __FIGURE_T__
