#ifndef __TETROMINO_FACTORY__
#define __TETROMINO_FACTORY__

#include "FigureI.h"
#include "FigureZ.h"
#include "FigureS.h"
#include "FigureL.h"
#include "FigureJ.h"
#include "FigureT.h"
#include "FigureO.h"

#include <memory>

class TetrominoFactory
{
public:
	static std::unique_ptr<Tetromino> createTetromino(int x, int y);
};


#endif  __TETROMINO_FACTORY__

