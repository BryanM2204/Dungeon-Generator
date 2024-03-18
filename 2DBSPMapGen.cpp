#include <iostream>
#include <string>
#include <random>
#include <functional>
#include <stdlib.h>
#include "Rectangle.h"
#include "Leaf.h"
#include <vector>
#include <list>
#include "Point.h"
#include <cmath>
#include <time.h>       /* time */

using namespace std;

int main() {
	/* initialize random seed: */
	srand(time(NULL));

	int MAX_LEAF_SIZE = 20;
	Leaf* root = new Leaf(0, 0, 100, 100);
	std::list<Leaf> leaf_edge_nodes;
	std::list<Rectangle> halls;

	root->createRooms();


	// need a char map (space is char 40, wall is char 179);
	char map[100][100]; // same width / height as the root leaf
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++){
			map[i][j] = 178;
		}
	}

	for (std::list<Leaf>::iterator l = leaf_edge_nodes.begin(); l != leaf_edge_nodes.end(); ++l) {
		
		Rectangle* room = l->getRoom();
		int left = room->left();
		int right = room->right();
		int top = room->top();
		int bottom = room->bottom();

		if (left < 1) left = 1;
		if (right < 1) right = 1;
		if (top < 1) top = 1;
		if (bottom < 1) bottom = 1;

		if (right - left > 3 && bottom - top > 3) {

			for (int i = left; i <= right; i++) {
				for (int j = top; j <= bottom; j++) {
					map[i][j] = 32;
				}
			}
		}
	}

	for (std::list<Rectangle>::iterator hh = halls.begin(); hh != halls.end(); ++hh) {
		
		int left = hh->left();
		int right = hh->right();
		int top = hh->top();
		int bottom = hh->bottom();

		if (left < 1) left = 1;
		if (right < 1) right = 1;
		if (top < 1) top = 1;
		if (bottom < 1) bottom = 1;

		if (left > 99) left = 98;
		if (right > 99) right = 98;
		if (top > 99) top = 98;
		if (bottom > 99) bottom = 98;

		for (int i = left; i <= right; i++) {
			for (int j = top; j <= bottom; j++) {
				map[i][j] = 32;
			}
		}
	}

	cout << endl;
	cout << "=== DUNGEON GENERATOR v0.1 ===";
	cout << endl << endl;
	for (int j = 0; j < 100; j++) {
		cout << "  ";
		for (int i = 0; i < 100; i++){
			cout << map[i][j];
		}
		cout << endl;
	}

	int d;
	cin >> d;
}










/*

int randIBetween(int a, int b) {
	return ((rand() % b) + a);
}

bool randTrue(int percentage) {
	return (percentage > randIBetween(1, 100));
}

void createHall(Rectangle* l, Rectangle* r) {
	// now we connect these two rooms together with hallways.
	// this looks pretty complicated, but it's just trying to figure out which point is where and then either draw a straight line, or a pair of lines to make a right-angle to connect them.
	// you could do some extra logic to make your halls more bendy, or do some more advanced things if you wanted.
	//list<Rectangle> halls; 

	list<Rectangle*> halls;

	Point* p1 = new Point(randIBetween(l->left() + 1, l->right() - 2), randIBetween(l->top() + 1, l->bottom() - 2));
	Point* p2 = new Point(randIBetween(r->left() + 1, r->right() - 2), randIBetween(r->top() + 1, r->bottom() - 2));

	int w = p2->first - p1->first;
	int h = p2->second - p2->second;

	if (w < 0) {
		if (h < 0) {
			if (randTrue(50)) {
				halls.push_back(new Rectangle(p2->first, p1->second, abs(w), 1));
				halls.push_back(new Rectangle(p2->first, p2->second, 1, abs(h)));
			}
			else {
				halls.push_back(new Rectangle(p2->first, p2->second, abs(w), 1));
				halls.push_back(new Rectangle(p1->first, p2->second, 1, abs(h)));
			}
		}
		else if (h > 0) {
			if (randTrue(50)) {
				halls.push_back(new Rectangle(p2->first, p1->second, abs(w), 1));
				halls.push_back(new Rectangle(p2->first, p1->second, 1, abs(h)));
			}
			else {
				halls.push_back(new Rectangle(p2->first, p2->second, abs(w), 1));
				halls.push_back(new Rectangle(p1->first, p1->second, 1, abs(h)));
			}
		}
		else {
			halls.push_back(new Rectangle(p2->first, p2->second, abs(w), 1));
		}
	}
	else if (w > 0) {
		if (h < 0) {
			if (randTrue(50)) {
				halls.push_back(new Rectangle(p1->first, p2->second, abs(w), 1));
				halls.push_back(new Rectangle(p1->first, p2->second, 1, abs(h)));
			}
			else {
				halls.push_back(new Rectangle(p1->first, p1->second, abs(w), 1));
				halls.push_back(new Rectangle(p2->first, p2->second, 1, abs(h)));
			}
		}
		else if (h > 0) {
			if (randTrue(50)) {
				halls.push_back(new Rectangle(p1->first, p1->second, abs(w), 1));
				halls.push_back(new Rectangle(p2->first, p1->second, 1, abs(h)));
			}
			else {
				halls.push_back(new Rectangle(p1->first, p2->second, abs(w), 1));
				halls.push_back(new Rectangle(p1->first, p1->second, 1, abs(h)));
			}
		}
		else {
			halls.push_back(new Rectangle(p1->first, p1->second, abs(w), 1));
		}
	}
	else {
		if (h < 0) {
			halls.push_back(new Rectangle(p2->first, p2->second, 1, abs(h)));
		}
		else if (h > 0) {
			halls.push_back(new Rectangle(p1->first, p1->second, 1, abs(h)));
		}
	}

}


*/