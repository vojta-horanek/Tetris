#ifndef SHAPET_H
#define SHAPET_H

#include "../Shape.h"

class ShapeT : public Shape {
public:
    ShapeT() {
        height = 2;

        color = {0x87, 0x37, 0xd9, 255};

        blocks[0].emplace_back(1, 0);
        blocks[0].emplace_back(0, 1);
        blocks[0].emplace_back(1, 1);
        blocks[0].emplace_back(2, 1);

        blocks[1].emplace_back(1, 0);
        blocks[1].emplace_back(1, 1);
        blocks[1].emplace_back(2, 1);
        blocks[1].emplace_back(1, 2);

        blocks[2].emplace_back(0, 1);
        blocks[2].emplace_back(1, 1);
        blocks[2].emplace_back(2, 1);
        blocks[2].emplace_back(1, 2);

        blocks[3].emplace_back(1, 0);
        blocks[3].emplace_back(0, 1);
        blocks[3].emplace_back(1, 1);
        blocks[3].emplace_back(1, 2);

    }

};

#endif // SHAPET_H
