#pragma once

#include "CellularAutomatonGrid.hpp"

#include <vector>
#include <SFML/Graphics.hpp>

namespace cellular::gol
{

class GOLGrid: public CellularAutomatonGrid
{
    public:
        enum State { Alive, Dead, Dying, Ressurecting };
    private:
        std::vector<State> m_States;
    public:
        GOLGrid(unsigned int width, unsigned int height);
        GOLGrid::State GetState(unsigned int row, unsigned int col) const;
        void SetState(GOLGrid::State state, unsigned int row, unsigned int col);
        virtual inline unsigned GetIndex(unsigned row, unsigned col) const
        { return row*GetWidth() + col; }
};

}