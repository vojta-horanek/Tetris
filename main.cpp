#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/SDLTTF.hh>
#include "GameBoard.h"
#include "GameInfo.h"
#include "Shape.h"
#include "Shapes/ShapeT.h"
#include "Shapes/ShapeL.h"
#include "Shapes/ShapeL2.h"
#include "Shapes/ShapeZ.h"
#include "Shapes/ShapeZ2.h"
#include "Shapes/ShapeB.h"
#include "Shapes/ShapeI.h"

#define FPS_CAP 60
#define TICKS_PER_FRAME 1000 / FPS_CAP

const int SPEED_NORMAL = 10;
const int SPEED_FAST = 5;
const int SPEED_INSTANT = 1;

Shape *getRandomShape() {
    switch (rand() % 7) {
        case 0:
            return new ShapeL;
        case 1:
            return new ShapeT;
        case 2:
            return new ShapeL2;
        case 3:
            return new ShapeB;
        case 4:
            return new ShapeZ;
        case 5:
            return new ShapeZ2;
        default:
        case 6:
            return new ShapeI;
    }
}

bool TryRotate(Shape *shape, Map *map) {
    shape->Rotate();
    for (auto &point : shape->GetBlocks()) {
        if (shape->position.x + point.x < 0 ||
            shape->position.x + point.x >= 10 ||
            map->HasBlock(shape->position.x + point.x, shape->position.y + point.y) ||
            shape->position.y + point.y >= 20) {
            return true;
        }
    }
    return false;
}

int main() {
    try {
        using namespace SDL2pp;

        SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        SDLTTF sdl_ttf;

        Window window("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 800, 0);
        Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
        renderer.SetDrawBlendMode(SDL_BLENDMODE_BLEND);

        Map map;
        GameBoard gameBoard(renderer, &map);
        GameInfo gameInfo(renderer);

        SDL_Event event;
        bool run = true;
        bool showFPS = false;

        Uint32 startTicks = SDL_GetTicks();
        Uint32 frames = 0;
        Uint32 loopTicks = 0;

        Uint32 speedModifier = 0;

        int score = 0;
        int level = 0;
        int totalRowsRemoved = 0;
        bool showGuidelines = false;
        bool showDestination = true;

        srand(time(nullptr));

        Shape *shape = getRandomShape();
        Shape *nextShape = getRandomShape();
        nextShape->position = {11, 10};
        Uint32 dx = 0;
        Uint32 dy = SPEED_NORMAL;

        while (run) {
            loopTicks = SDL_GetTicks();

            renderer.SetDrawColor({0x2a, 0x2a, 0x2a, 255});
            renderer.Clear();

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym) {
                            case SDLK_f:
                                showFPS = !showFPS;
                                break;
                            case SDLK_SPACE:
                                dy = SPEED_INSTANT;
                                break;
                            case SDLK_g:
                                showGuidelines = !showGuidelines;
                                break;
                            case SDLK_d:
                                showDestination = !showDestination;
                                break;
                            case SDLK_k:
                            case SDLK_UP:
                                if (TryRotate(shape, &map))
                                    shape->RotateBack();
                                break;
                            case SDLK_DOWN:
                            case SDLK_j:
                                dy = SPEED_FAST;
                                break;
                            case SDLK_LEFT:
                            case SDLK_h:
                                dx = -1;
                                break;
                            case SDLK_RIGHT:
                            case SDLK_l:
                                dx = 1;
                                break;
                        }
                        break;
                    case SDL_KEYUP:
                        switch (event.key.keysym.sym) {
                            case SDLK_j:
                            case SDLK_DOWN:
                                dy = SPEED_NORMAL;
                                break;
                        }
                        break;
                    case SDL_QUIT:
                        run = false;
                        break;
                }
            }

            if (dy != SPEED_INSTANT) shape->position.x += dx;
            if (dy == SPEED_INSTANT) {
                shape->position.y++;
            } else if (dy == SPEED_FAST && frames % dy == 0) {
                shape->position.y++;
            } else if (frames % (dy + (5 - speedModifier)) == 0) {
                shape->position.y++;
            }

            // Collision Detection
            for (auto &point : shape->GetBlocks()) {

                if (shape->position.x + point.x < 0 || shape->position.x + point.x >= 10) {
                    shape->position.x -= dx;
                    break;
                } else if (map.HasBlock(shape->position.x + point.x, shape->position.y + point.y) ||
                           shape->position.y + point.y >= 20) {

                    if (dx != 0) {
                        shape->position.x -= dx;
                        continue;
                    } else {
                        shape->position.y--;
                    }
                    map.AddBlock(shape);

                    delete (shape);
                    shape = nextShape;
                    nextShape = getRandomShape();
                    nextShape->position = {11, 10};
                    shape->position = {3, 0};

                    dy = SPEED_NORMAL;
                    break;
                }

            }
            dx = 0;

            gameBoard.RenderBackground();
            gameBoard.RenderShape(shape);
            if (showGuidelines) gameBoard.RenderGuidelines(shape);
            if (showDestination) gameBoard.RenderDestination(shape);
            gameBoard.RenderMap();

            // TODO Dont check this every frame but only when a block is placed
            int scoreToAdd = 0;
            int rowsRemoved = map.CheckRows();
            totalRowsRemoved += rowsRemoved;

            if (totalRowsRemoved == 10) {
                level++;
                totalRowsRemoved = 0;
                if (speedModifier < 5) speedModifier++;
            }

            switch (rowsRemoved) {
                case 0:
                    scoreToAdd = 0;
                    break;
                case 1:
                    scoreToAdd = 40;
                    break;
                case 2:
                    scoreToAdd = 100;
                    break;
                case 3:
                    scoreToAdd = 300;
                    break;
                case 4:
                default:
                    scoreToAdd = 1200;
                    break;
            }
            score += scoreToAdd * (level + 1);


            if (map.CheckLost()) {
                score = 0;
                level = 0;
            }

            gameInfo.RenderLevel(level);
            gameInfo.RenderScore(score);
            gameBoard.RenderShape(nextShape);

            if (showFPS) {
                float fps = frames / ((float) (SDL_GetTicks() - startTicks) / 1000.f);
                gameInfo.RenderFps(fps);
            }

            renderer.Present();
            frames++;

            const Uint32 frameTicks = SDL_GetTicks() - loopTicks;
            if (frameTicks < TICKS_PER_FRAME) {
                SDL_Delay(TICKS_PER_FRAME - frameTicks);
            }
        }
    } catch (SDL2pp::Exception &e) {
        // Exception stores SDL_GetError() result and name of function which failed
        std::cerr << "Error in: " << e.GetSDLFunction() << std::endl;
        std::cerr << "  Reason: " << e.GetSDLError() << std::endl;
    } catch (std::exception &e) {
        // This also works (e.g. "SDL_Init failed: No available video device")
        std::cerr << e.what() << std::endl;
    }
    return 0;
}