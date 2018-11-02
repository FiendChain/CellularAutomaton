#include "App/App.hpp"
#include "CellularAutomaton/GOL/GOL.hpp"
#include "CellularAutomaton/Langton/Langton.hpp"
#include "CellularAutomaton/Langton/AI/NormalLangtonAnt.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string gameType(argc <= 1 ? "gol" : argv[1]);
    sf::Vector2u resolution(1920, 1080);
    if (gameType == "gol")
    {
        App app(resolution.x, resolution.y, 60, "Game of Life");
        app.SetCellularAutomaton<cellular::gol::GOL>(resolution.x, resolution.y, std::thread::hardware_concurrency()-1);
        app.Run(); 
    }
    else if (gameType == "langton") 
    {
        sf::Vector2u aspectRatio(16, 9);
        sf::Vector2u gridSize(aspectRatio * 20u);
        App app(resolution.x, resolution.y, 60, "Langton Ant");
        auto& langton = app.SetCellularAutomaton<cellular::langton::Langton>(gridSize.x, gridSize.y);
        auto& ant = langton.AddAnt<cellular::langton::NormalLangtonAnt>();
        ant.SetPosition(gridSize.x/2.0f, gridSize.y/2.0f);
        app.Run();
    }
    else
    {
        std::cerr << gameType << " is not a valid automaton!";
        return 1;
    }
    
    return 0;
}