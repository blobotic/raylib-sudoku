#include "Cell.h"
#include "../include/raylib.h"
#include <cstdio>
#include <string>

void Cell::drawCell(int selectedNumber, bool hl, int x, int y) {
	char const *aval = std::to_string(a).c_str();
	int textWidth = MeasureText(aval, size);

	// if the number is a given or not; changeable 
	// red if it's fixed, gray if not
	Color fixedColor = (fixed) ? RED : GRAY;

	// highlight cell yellow if selected number is in it
	if (selectedNumber == 0) ;
	else if (inCell(selectedNumber)) DrawRectangle(x, y, 50, 50, YELLOW);
	else if (hl) DrawRectangle(x, y, 50, 50, GOLD);

	// draw number
	if (a > 0) DrawText(aval, x+width/2-textWidth/2, y+height/2-size/2, size, fixedColor);

	// draw outline
	DrawRectangleLines(x, y, 50, 50, BLACK);
}

bool Cell::inCell(int selectedNumber) {
	return a==selectedNumber;
}