project("Cellular Automaton")

set(ROOT_DIR .)
set(CELLULAR_DIR ${ROOT_DIR}/CellularAutomaton)
set(GOL_DIR ${ROOT_DIR}/GOL)
set(LANGTON_DIR ${ROOT_DIR}/Langton)
set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)

include_directories(${CELLULAR_DIR} ${GOL_DIR} ${LANGTON_DIR})

set(CELLULAR_FILES
    ${CELLULAR_DIR}/CellularAutomaton.cpp
    ${CELLULAR_DIR}/CellularAutomatonGrid.cpp)

add_library(cellular ${CELLULAR_FILES})
target_link_libraries(cellular ${SFML_LIB})
target_compile_options(cellular PUBLIC -std=c++17 -O3)
target_include_directories(cellular PUBLIC ${CELLULAR_DIR})

set(GOL_FILES 
    ${GOL_DIR}/GOL.cpp
    ${GOL_DIR}/GOLGrid.cpp
    ${GOL_DIR}/ThreadPool.cpp
    ${GOL_DIR}/Rules/GOLNormal.cpp)

add_library(gol ${GOL_FILES})
target_link_libraries(gol cellular ${SMFL_LIB})
target_compile_options(gol PUBLIC -std=c++17 -O3 -pthread)
target_include_directories(gol PRIVATE ${GOL_DIR})

set(LANGTON_FILES
    ${LANGTON_DIR}/Langton.cpp
    ${LANGTON_DIR}/LangtonGrid.cpp
    ${LANGTON_DIR}/AI/LangtonAnt.cpp
    ${LANGTON_DIR}/AI/NormalLangtonAnt.cpp)

add_library(langton ${LANGTON_FILES})
target_link_libraries(langton cellular ${SMFL_LIB})
target_compile_options(langton PUBLIC -std=c++17 -O3)
target_include_directories(langton PRIVATE ${LANGTON_DIR})

install(TARGETS cellular gol langton DESTINATION bin)