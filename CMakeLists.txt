cmake_minimum_required(VERSION 3.24)
project(basic-game VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(AvariceEngine)

add_executable(basic-game src/main.cpp
    src/settings.cpp
    src/monster.cpp
    src/gui.cpp
    src/maps.h
    src/tower.cpp
    src/game.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC Avarice)


