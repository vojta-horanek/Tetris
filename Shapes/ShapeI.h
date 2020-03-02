#ifndef SHAPEI_H
#define SHAPEI_H

#include "../Shape.h"

class ShapeI : public Shape {
public:
    ShapeI() {
        height = 1;

        color = {0x66, 0xdd, 0xff, 255};

        blocks[0].emplace_back(0, 0);
        blocks[0].emplace_back(1, 0);
        blocks[0].emplace_back(2, 0);
        blocks[0].emplace_back(3, 0);

        blocks[1].emplace_back(1, 0);
        blocks[1].emplace_back(1, 1);
        blocks[1].emplace_back(1, 2);
        blocks[1].emplace_back(1, 3);

        blocks[2].emplace_back(0, 0);
        blocks[2].emplace_back(1, 0);
        blocks[2].emplace_back(2, 0);
        blocks[2].emplace_back(3, 0);

        blocks[3].emplace_back(1, 0);
        blocks[3].emplace_back(1, 1);
        blocks[3].emplace_back(1, 2);
        blocks[3].emplace_back(1, 3);
    }

};

#endif // SHAPEI_H
