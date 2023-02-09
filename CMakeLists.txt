cmake_minimum_required(VERSION 3.5.0)
project(basic-game VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engine)
add_executable(basic-game src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC AvariceEngine)

target_include_directories(basic-game
        PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_BINARY_DIR}"
    )
