cmake_minimum_required(VERSION 3.15)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

SET(SDL2PP_WITH_IMAGE ON)
SET(SDL2PP_WITH_MIXER ON)
SET(SDL2PP_WITH_TTF ON)

ADD_SUBDIRECTORY(libSDL2pp)

INCLUDE_DIRECTORIES(${SDL2PP_INCLUDE_DIRS})

ADD_EXECUTABLE(Tetris
        main.cpp GameBoard.cpp GameBoard.h Map.cpp Map.h Shape.cpp Shape.h
        Shapes/ShapeT.h Shapes/ShapeL.h Shapes/ShapeL2.h Shapes/ShapeZ.h Shapes/ShapeZ2.h Shapes/ShapeB.h Shapes/ShapeI.h GameInfo.cpp GameInfo.h)

target_link_libraries(Tetris ${SDL2PP_LIBRARIES})
