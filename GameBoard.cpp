//
// Created by vojta on 1/12/20.
//

#include "GameBoard.h"

GameBoard::GameBoard(SDL2pp::Renderer &renderer, Map *map) {
    this->renderer = &renderer;
    this->blockSize = 40;
    this->map = map;
}

GameBoard::~GameBoard() = default;

void GameBoard::RenderShape(Shape *shape) {
    for (auto &point : shape->GetBlocks()) {
        DrawBlockOutline((shape->position.x + point.x) * blockSize, (shape->position.y + point.y) * blockSize,
                         shape->color);
    }
}

void GameBoard::DrawBlock(int x, int y, SDL_Color color) {
    SDL2pp::Rect target(x, y, blockSize, blockSize);
    renderer->SetDrawColor(color);
    renderer->FillRect(target);
}

void GameBoard::DrawBlockOutline(int x, int y, SDL_Color color) {
    SDL2pp::Rect target(x, y, blockSize, blockSize);
    SDL2pp::Rect target2(x + 3, y + 3, blockSize - 6, blockSize - 6);

    renderer->SetDrawColor(0, 0, 0, 255);
    renderer->FillRect(target);

    renderer->SetDrawColor(color.r, color.g, color.b, 120);
    renderer->FillRect(target);

    renderer->SetDrawColor(color);
    renderer->FillRect(target2);
}

void GameBoard::RenderBackground() {
    renderer->SetDrawColor({0x4a, 0x4a, 0x4a, 255});

    for (int x = 40; x <= 400; x += 40) {
        renderer->DrawLine(x, 0, x, 800);
    }
    for (int y = 40; y < 800; y += 40) {
        renderer->DrawLine(0, y, 400, y);
    }
}

void GameBoard::RenderMap() {

    for (int i = 0; i < 10; i++) {
        for (int x = 0; x < 20; x++) {
            if (map->mapData[i][x].hasBlock) {
                DrawBlockOutline(i * blockSize, x * blockSize, map->mapData[i][x].color);
            }
        }
    }
}

void GameBoard::RenderDestination(Shape *shape) {

    int i = GetFinalDestination(shape);
    for (auto &p : shape->GetBlocks()) {
        SDL_Color c = {shape->color.r, shape->color.g, shape->color.b, 100};
        DrawBlock((shape->position.x + p.x) * blockSize, (i + p.y) * blockSize, c);
    }
}

int GameBoard::GetFinalDestination(Shape *shape) {

    for (int i = shape->position.y; i < 20; i++) {
        for (auto &point : shape->GetBlocks()) {
            if (map->HasBlock(shape->position.x + point.x, i + point.y + 1) ||
                i + point.y >= 19) {
                return i;
            }
        }
    }
}

void GameBoard::RenderGuidelines(Shape *shape) {
    int maxX = 0;
    int minX = 999;
    int minY = 0;

    for (auto &point : shape->GetBlocks()) {
        if (maxX <= shape->position.x + point.x) {
            maxX = shape->position.x + point.x + 1;
        }
        if (minX >= shape->position.x + point.x) {
            minX = shape->position.x + point.x;
        }
        if (minY <= shape->position.y + point.y) {
            minY = shape->position.y + point.y + 1;
        }
    }

    renderer->SetDrawColor(shape->color.r, shape->color.g, shape->color.b, 170);
    renderer->DrawLine(minX * blockSize, shape->position.y * blockSize, minX * blockSize, 800);
    renderer->DrawLine(maxX * blockSize, shape->position.y * blockSize, maxX * blockSize, 800);
    renderer->DrawLine(minX * blockSize, shape->position.y * blockSize, maxX * blockSize,
                       shape->position.y * blockSize);
}

void GameBoard::RenderNextShape(Shape *shape) {

}


