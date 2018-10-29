cmake_minimum_required(VERSION 3.0)

project("Game of Life - Multithreaded")

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)
set(APP_DIR ${SRC_DIR}/App)
set(CELLULAR_DIR ${SRC_DIR}/CellularAutomaton)
set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)

include_directories(${SRC_DIR} ${APP_DIR} ${CELLULAR_DIR})

add_subdirectory(${CELLULAR_DIR})

set(APP_FILES
    ${APP_DIR}/App.cpp
    ${APP_DIR}/Camera/Camera.cpp
    ${APP_DIR}/Camera/ControllableCamera.cpp
    ${APP_DIR}/ResourceManager/ResourceManager.cpp
    ${APP_DIR}/Utility/FpsCounter/FpsCounter.cpp)

add_library(App ${APP_FILES})
target_compile_options(App PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(App cellular ${SFML_LIB})

add_executable(main ${SRC_DIR}/main.cpp)
target_compile_options(main PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(main gol langton App)