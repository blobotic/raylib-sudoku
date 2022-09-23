#ifndef CELL_H
#define CELL_H

#include <stdlib.h>

class Cell {
private:
	int a = (std::rand()%9+1)*(std::rand()%2);
	bool fixed = (std::rand()%2)*(std::rand()%2);
	int pencil[9] = {false};
public:
	int width = 50, height = 50, size = 24;
	int val() {return a;}
	void drawCell(int selectedNumber, bool highlightCell, int x, int y);
	bool inCell(int selectedNumber);

	void setA(int val) {if (!fixed) a = val;}
};

#endif