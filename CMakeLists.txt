cmake_minimum_required(VERSION 3.18)
project(FlyOverBoxes C)

set(CMAKE_C_STANDARD 11)

set(HEADERS_FILES
        Sources/Drawing/Drawing.h
        Sources/Game/Game.h
        Sources/Menu/Menu.h
        Sources/Objects/Bomb.h
        Sources/Objects/Histogram.h
        Sources/Objects/Image.h
        Sources/Objects/Plane.h
        Sources/Scores/Scores.h
        Sources/Utils/CommandParsing.h
        Sources/Utils/Log.h
        Sources/Utils/Options.h
        Sources/Includes.h
)

set(SOURCES_FILES
        Sources/Drawing/Drawing.c
        Sources/Game/Game.c
        Sources/Menu/Menu.c
        Sources/Objects/Bomb.c
        Sources/Objects/Histogram.c
        Sources/Objects/Image.c
        Sources/Objects/Plane.c
        Sources/Scores/Scores.c
        Sources/Utils/CommandParsing.c
        Sources/Utils/Log.c
        Sources/Utils/Options.c
        Main.c
)

add_executable(FlyOverBoxes ${SOURCES_FILES} ${HEADERS_FILES})
#