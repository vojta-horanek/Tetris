#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>


class Shape {
public:
    Shape();

    virtual ~Shape();

    void Rotate();
    void RotateBack();

    SDL_Color color = {0, 255, 0, 255};

    std::vector<SDL2pp::Point> GetBlocks();
    SDL2pp::Point position = {3, 0};

    int height{};
protected:
    int rotation = 0;
    std::vector<SDL2pp::Point> blocks[4];
};

#endif // SHAPE_H
