cmake_minimum_required(VERSION 3.26)
project(tergp C)

set(CMAKE_C_STANDARD 17)

add_executable(tergp main.c
        headers/headers.h
        headers/lists.h
        headers/player.h
        Sources/auxFuncs.c
        Sources/player/playerMovement.c
        Sources/lists/listHandling.c
        Sources/maps/fileHandling.c
        Sources/maps/mapHandling.c
        headers/map.h
)

target_link_libraries(${PROJECT_NAME} -lncursesw)