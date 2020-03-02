#ifndef SHAPEL_H
#define SHAPEL_H

#include "../Shape.h"

class ShapeL : public Shape {
public:
    ShapeL() {
        height = 2;

        color = {0x00, 0x3b, 0xfc, 255};

        blocks[0].emplace_back(0, 0);
        blocks[0].emplace_back(0, 1);
        blocks[0].emplace_back(1, 1);
        blocks[0].emplace_back(2, 1);

        blocks[1].emplace_back(0, 0);
        blocks[1].emplace_back(0, 1);
        blocks[1].emplace_back(0, 2);
        blocks[1].emplace_back(1, 0);

        blocks[2].emplace_back(2, 1);
        blocks[2].emplace_back(0, 0);
        blocks[2].emplace_back(1, 0);
        blocks[2].emplace_back(2, 0);

        blocks[3].emplace_back(1, 0);
        blocks[3].emplace_back(1, 1);
        blocks[3].emplace_back(1, 2);
        blocks[3].emplace_back(0, 2);
    }

};

#endif // SHAPEL_H
