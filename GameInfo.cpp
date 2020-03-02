//
// Created by vojta on 2/19/20.
//

#include "GameInfo.h"

GameInfo::GameInfo(Renderer &renderer) {
    font = new SDL2pp::Font("/usr/share/fonts/ttf/DejaVuSans.ttf", 20);
    fontBig = new SDL2pp::Font("/usr/share/fonts/ttf/DejaVuSans.ttf", 70);
    this->renderer = &renderer;
}

GameInfo::~GameInfo() {
    delete(font);
    delete(fontBig);
}

void GameInfo::RenderScore(int score) {
    Texture scoreTexture(*renderer, fontBig->RenderText_Blended(std::to_string(score), {255, 255, 255, 255}));
    //TODO render text in this color renderer->SetDrawColor({0xe8, 0x29, 0x10, 255});
    renderer->Copy(scoreTexture, NullOpt, Rect(Point(500 - scoreTexture.GetSize().x / 2, 40), scoreTexture.GetSize()));
}

void GameInfo::RenderLevel(int level) {
    std::string infoText = "level: " + std::to_string(level);
    Texture levelTexture(*renderer, font->RenderText_Blended(infoText, {255, 255, 255, 255}));
    renderer->Copy(levelTexture, NullOpt, Rect(Point(500 - levelTexture.GetSize().x / 2, 150), levelTexture.GetSize()));
}

void GameInfo::RenderFps(float fps) {
    Texture fpsTexture(*renderer, font->RenderText_Blended(std::to_string(fps), {255, 255, 0}));
    renderer->Copy(fpsTexture, NullOpt, Rect(Point(410, 800 - fpsTexture.GetSize().y - 10), fpsTexture.GetSize()));

}