#include "Grid.h"
#include "../include/raylib.h"

int Grid::get(int x, int y) {
	if (x < 9 && x > -1 && y < 9 && y > -1) return tiles[x][y].val();
	else return -1;
}

void Grid::drawGrid() {
	int topPadding=75, leftPadding = 75;

	Cell c1 = tiles[0][0];
	int w = c1.width, h = c1.height; 

	DrawRectangleLinesEx({leftPadding, topPadding, 9*w, 9*h}, 5, BLACK);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			DrawRectangleLinesEx({leftPadding+3*w*i, topPadding+3*h*j, 3*w, 3*h}, 2, BLACK);
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			tiles[i][j].drawCell(leftPadding+w*i, topPadding+h*j);
		}
	}
}