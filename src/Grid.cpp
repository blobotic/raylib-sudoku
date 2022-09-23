#include "Grid.h"
#include "../include/raylib.h"

int Grid::get(int x, int y) {
	if (x < 9 && x > -1 && y < 9 && y > -1) return tiles[x][y].val();
	else return -1;
}

void Grid::drawGrid() {
	Cell c1 = tiles[0][0];
	int w = c1.width, h = c1.height; 

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			tiles[i][j].drawCell(*snRef, inGroup(i, j, *snRef), leftPadding+w*i, topPadding+h*j);
		}
	}

	// outline across the entire thing + outline arou 3x3 grids
	DrawRectangleLinesEx({leftPadding, topPadding, 9*w, 9*h}, 5, BLACK);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			DrawRectangleLinesEx({leftPadding+3*w*i, topPadding+3*h*j, 3*w, 3*h}, 2, BLACK);
		}
	}
}


std::pair<int, int> Grid::getCellFromPixels(int x, int y) {
	int xVal = (x-leftPadding)/tiles[0][0].width;
	int yVal = (y-topPadding)/tiles[0][0].height;
	return std::make_pair(xVal, yVal);
}

// x and y are in PIXELS
void Grid::changeValue(int x, int y, int num) {
	if (x < leftPadding || y < topPadding || x > leftPadding + 9 * tiles[0][0].width || y > topPadding + 9 * tiles[0][0].height) return;

	std::pair<int, int> cellIndex = getCellFromPixels(x, y);
	tiles[cellIndex.first][cellIndex.second].setA(num);
}

// checks if tiles[x][y] can see num
bool Grid::inGroup(int x, int y, int num) {
	int xBase = x - (x%3);
	int yBase = y - (y%3);

	// 3x3 boxes
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tiles[xBase + (x+i)%3][yBase + (y+j)%3].inCell(num)) return true;
		}
	}

	// rows and columns
	for (int i = 0; i < 9; i++) {
		if (tiles[(x+i)%9][y].inCell(num) || tiles[x][(y+i)%9].inCell(num)) return true;
	}

	return false;
}