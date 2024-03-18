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



const int MAX_LEAF_SIZE = 20;

std::vector<Leaf*> _leafs;

int main() {
    // Create the root Leaf
    Leaf* root = new Leaf(0, 0, 10, 10);
    std::list<Leaf> leaf_edge_nodes;
    std::list<Rectangle> halls;
    _leafs.push_back(root);

    bool did_split = true;

    // Loop through every Leaf in the vector until no more Leafs can be split
    while (did_split) {
        did_split = false;

        for (auto l : _leafs) {
            if (l->leftChild == nullptr && l->rightChild == nullptr) { // If this Leaf is not already split
                // If this Leaf is too big, or 75% chance
                if (l->width > MAX_LEAF_SIZE || l->height > MAX_LEAF_SIZE || (rand() % 100 > 25)) {
                    if (l->split()) { // Split the Leaf
                        // If we did split, push the child leafs to the vector
                        _leafs.push_back(l->leftChild);
                        _leafs.push_back(l->rightChild);
                        did_split = true;
                    }
                }
            }
        }
    }

    // Create rooms in each Leaf
    root->createRooms(&leaf_edge_nodes, &halls);

    return 0;
}