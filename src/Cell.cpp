#include "Cell.h"
#include "../include/raylib.h"
#include <cstdio>
#include <string>

void Cell::drawCell(int x, int y) {
	char const *aval = std::to_string(a).c_str();
	int textWidth = MeasureText(aval, size);

	if (a > 0) DrawText(aval, x+width/2-textWidth/2, y+height/2-size/2, size, GRAY);
	DrawRectangleLines(x, y, 50, 50, BLACK);
}