#ifndef SHAPEL2_H
#define SHAPEL2_H

#include "../Shape.h"

class ShapeL2 : public Shape {
public:
    ShapeL2() {
        height = 2;

        color = {0xf1, 0x9a, 0x00, 255};

        blocks[0].emplace_back(2, 0);
        blocks[0].emplace_back(0, 1);
        blocks[0].emplace_back(1, 1);
        blocks[0].emplace_back(2, 1);

        blocks[1].emplace_back(1, 0);
        blocks[1].emplace_back(1, 1);
        blocks[1].emplace_back(1, 2);
        blocks[1].emplace_back(0, 0);

        blocks[2].emplace_back(0, 1);
        blocks[2].emplace_back(0, 0);
        blocks[2].emplace_back(1, 0);
        blocks[2].emplace_back(2, 0);

        blocks[3].emplace_back(0, 0);
        blocks[3].emplace_back(0, 1);
        blocks[3].emplace_back(0, 2);
        blocks[3].emplace_back(1, 2);

    }

};

#endif // SHAPEL2_H
