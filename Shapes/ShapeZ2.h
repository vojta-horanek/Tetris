#ifndef SHAPEZ2_H
#define SHAPEZ2_H

#include "../Shape.h"

class ShapeZ2 : public Shape {
public:
    ShapeZ2() {
        height = 2;

        color = {0xe8, 0x29, 0x10, 255};

        blocks[0].emplace_back(0, 0);
        blocks[0].emplace_back(1, 0);
        blocks[0].emplace_back(1, 1);
        blocks[0].emplace_back(2, 1);

        blocks[1].emplace_back(1, 0);
        blocks[1].emplace_back(1, 1);
        blocks[1].emplace_back(0, 1);
        blocks[1].emplace_back(0, 2);

        blocks[2].emplace_back(0, 0);
        blocks[2].emplace_back(1, 0);
        blocks[2].emplace_back(1, 1);
        blocks[2].emplace_back(2, 1);

        blocks[3].emplace_back(1, 0);
        blocks[3].emplace_back(1, 1);
        blocks[3].emplace_back(0, 1);
        blocks[3].emplace_back(0, 2);
    }

};

#endif // SHAPEZ2_H