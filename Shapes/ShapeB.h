#ifndef SHAPEB_H
#define SHAPEB_H

#include "../Shape.h"

class ShapeB : public Shape {
public:
    ShapeB() {
        height = 2;

        color = {0xfe, 0xea, 0x00, 255};

        blocks[0].emplace_back(0, 0);
        blocks[0].emplace_back(0, 1);
        blocks[0].emplace_back(1, 1);
        blocks[0].emplace_back(1, 0);

        blocks[1].emplace_back(0, 1);
        blocks[1].emplace_back(0, 0);
        blocks[1].emplace_back(1, 1);
        blocks[1].emplace_back(1, 0);

        blocks[2].emplace_back(0, 0);
        blocks[2].emplace_back(0, 1);
        blocks[2].emplace_back(1, 1);
        blocks[2].emplace_back(1, 0);

        blocks[3].emplace_back(0, 0);
        blocks[3].emplace_back(0, 1);
        blocks[3].emplace_back(1, 1);
        blocks[3].emplace_back(1, 0);
    }

};

#endif // SHAPEL_B
