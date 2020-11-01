#ifndef __FIGURE_O__
#define __FIGURE_O__

#include "Tetromino.h"

class FigureO : public Tetromino
{
public:
	FigureO(int x, int y);
	void rotate() & override;
};

#endif  __FIGURE_O__

