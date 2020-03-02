#include "Shape.h"

Shape::Shape() = default;

Shape::~Shape() = default;

void Shape::Rotate() {
    rotation = (rotation + 1) % 4;
}

std::vector<SDL2pp::Point> Shape::GetBlocks() {
    return blocks[rotation];
}

void Shape::RotateBack() {
    if (rotation == 0) rotation = 3;
    else rotation--;
}
