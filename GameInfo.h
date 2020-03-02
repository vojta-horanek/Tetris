//
// Created by vojta on 2/19/20.
//

#ifndef TETRIS_GAMEINFO_H
#define TETRIS_GAMEINFO_H

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/SDLTTF.hh>
#include "Shape.h"

using namespace SDL2pp;

class GameInfo {
public:
    GameInfo(Renderer &renderer);
    ~GameInfo();
    void RenderScore(int score);
    void RenderLevel(int level);
    void RenderFps(float fps);

private:
    Font *font;
    Font *fontBig;
    Renderer *renderer;
};


#endif //TETRIS_GAMEINFO_H
