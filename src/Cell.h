#ifndef CELL_H
#define CELL_H

#include <stdlib.h>

class Cell {
private:
	int a = std::rand()%9+1;
public:
	int width = 50, height = 50, size = 24;
	int val() {return a;}
	void drawCell(int x, int y);
};

#endif