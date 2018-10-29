#pragma once

#include "CellularAutomatonGrid.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

namespace cellular::langton
{

class LangtonGrid: public CellularAutomatonGrid
{
    public:
        enum State { White, Black };
    private:
        std::vector<State> m_States;
    public:
        LangtonGrid(unsigned int width, unsigned int height);
        void Clear(State state = State::White);
        State GetState(int row, int col) const;
        void SetState(State state, int row, int col);
};

}