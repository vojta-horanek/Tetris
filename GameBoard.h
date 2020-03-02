//
// Created by vojta on 1/12/20.
//

#ifndef BUMBLEBEE_GAME_H
#define BUMBLEBEE_GAME_H


#include <SDL2pp/Renderer.hh>
#include <iostream>
#include "Map.h"
#include "Shape.h"

class GameBoard {
public:
    GameBoard(SDL2pp::Renderer &renderer, Map *map);

    virtual ~GameBoard();

    void RenderShape(Shape *shape);

    void RenderMap();

    void RenderBackground();

    void RenderGuidelines(Shape *shape);

    void RenderDestination(Shape *shape);
    int GetFinalDestination(Shape *shape);
    void RenderNextShape(Shape *shape);


private:
    SDL2pp::Renderer *renderer;
    int blockSize;
    Map *map;

    void DrawBlock(int x, int y, SDL_Color color);

    void DrawBlockOutline(int x, int y, SDL_Color color);

};


#endif //BUMBLEBEE_GAME_H
