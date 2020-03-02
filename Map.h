//
// Created by vojta on 1/12/20.
//

#ifndef BUMBLEBEE_MAP_H
#define BUMBLEBEE_MAP_H

#include <fstream>
#include <string>
#include <SDL2pp/Texture.hh>
#include "Shape.h"

class mapBlock {
public:
    bool hasBlock = false;
    SDL_Color color = {0, 0, 0, 0};

    mapBlock() {
        hasBlock = false;
    }

    void set(SDL_Color color) {
        this->color = color;
        hasBlock = true;
    }
};

class Map {
public:
    Map();

    bool HasBlock(int x, int y);

    void AddBlock(Shape *shape);

    int CheckRows();
    bool CheckLost();
    void ClearMap();

    mapBlock mapData[10][20];
private:
    bool CheckRow(int y);
    void EraseRow(int y);
};


#endif //BUMBLEBEE_MAP_H
