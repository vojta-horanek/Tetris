//
// Created by vojta on 1/12/20.
//

#include "Map.h"

Map::Map() = default;

bool Map::HasBlock(int x, int y) {
    return mapData[x][y].hasBlock;
}

void Map::ClearMap() {
    for (auto &x : mapData) {
        for (auto &y : x) {
            y.hasBlock = false;
        }
    }
}

bool Map::CheckLost() {
    for (auto &i : mapData) {
        if (i[0].hasBlock) {
            ClearMap();
            return true;
        }
    }
    return false;
}


void Map::AddBlock(Shape *shape) {
    for (auto &point : shape->GetBlocks()) {
        mapData[shape->position.x + point.x][shape->position.y + point.y].set(shape->color);
    }
}

int Map::CheckRows() {
    int fullRowsDeleted= 0;
    for (int y = 19; y >= 0; y--) {
        if (CheckRow(y)) {
            EraseRow(y);
            fullRowsDeleted++;
            y = 19; // reset search
        }
    }
    return fullRowsDeleted;
}

bool Map::CheckRow(int y) {
    for (auto &x : mapData) {
        if (!x[y].hasBlock) return false;
    }
    return true;
}

void Map::EraseRow(int y) {
    for (int i = y; i > 0; i--) {
        for (auto &x : mapData) {
            x[i] = x[i - 1];
        }
    }
}
