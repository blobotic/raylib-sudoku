#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
private:
	Cell tiles[9][9];
public: 
	int get(int x, int y);
	void drawGrid();
};

#endif