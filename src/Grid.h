#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <utility>

class Grid {
private:
	Cell tiles[9][9];
	int *snRef;
	int topPadding = 75, leftPadding = 75;
public: 
	int get(int x, int y);
	void drawGrid();
	void changeValue(int x, int y, int selNum);
	bool inGroup(int x, int y, int num);

	std::pair<int, int> getCellFromPixels(int x, int y);


	Grid(int *selectedNumber) {
		snRef = selectedNumber;
	}
};

#endif