#include <iostream>
#include <stdlib.h>

#ifndef LEAF_RECT
#define LEAF_RECT
class Rectangle
{

public:
	int pX, pY, width, height;
	Rectangle(int x, int y, int width, int height);
	void setHeight(int);
	void setWidth(int);
	int perimeter();
	float area();
	void show();
	int sameArea(Rectangle);

	int left();
	int right();
	int top();
	int bottom();

	
};
#endif