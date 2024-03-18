#include "Rectangle.h"


Rectangle::Rectangle(int X, int Y, int Width, int Height) {
	setWidth(Width);
	setHeight(Height);
	pX = X;
	pY = Y;
}

void Rectangle::setHeight(int h)
{
	height = h;
}

void Rectangle::setWidth(int wid)
{
	width = wid;
}

int Rectangle::perimeter()
{
	return (2 * height + 2 * width);
}

float Rectangle::area()
{
	return height * width;
}

void Rectangle::show()
{
	//cout << "Length: " << length << " Width: " << width;
}

int Rectangle::sameArea(Rectangle other)
{
	int areaf = height * width;
	int areas = other.height * other.width;
	if (areaf == areas)
		return 1;
	return 0;
}

int Rectangle::left() {
	return pX;	
}

int Rectangle::right() {
	return pX + width;
}

int Rectangle::top() {
	return pY;
}

int Rectangle::bottom() {
	return pY + height;

}
