#ifndef SHAPEZ_H
#define SHAPEZ_H

#include "../Shape.h"

class ShapeZ : public Shape {
public:
    ShapeZ() {
        height = 2;

        color = {0x6a, 0xd3, 0x00, 255};

        blocks[0].emplace_back(1, 0);
        blocks[0].emplace_back(2, 0);
        blocks[0].emplace_back(0, 1);
        blocks[0].emplace_back(1, 1);

        blocks[1].emplace_back(0, 0);
        blocks[1].emplace_back(0, 1);
        blocks[1].emplace_back(1, 1);
        blocks[1].emplace_back(1, 2);

        blocks[2].emplace_back(1, 0);
        blocks[2].emplace_back(2, 0);
        blocks[2].emplace_back(0, 1);
        blocks[2].emplace_back(1, 1);

        blocks[3].emplace_back(0, 0);
        blocks[3].emplace_back(0, 1);
        blocks[3].emplace_back(1, 1);
        blocks[3].emplace_back(1, 2);
    }

};

#endif // SHAPEZ_H
