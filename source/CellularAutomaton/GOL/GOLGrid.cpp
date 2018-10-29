#include "GOLGrid.hpp"
#include <SFML/Graphics.hpp>

namespace cellular::gol
{

GOLGrid::GOLGrid(unsigned int width, unsigned int height)
    : CellularAutomatonGrid(width, height),
      m_States(width*height)
{
    for (unsigned int row = 0; row < GetHeight(); row++)
        for (unsigned int col = 0; col < GetWidth(); col++)
        {
            SetState(State::Dead, row, col);
        }
}

GOLGrid::State GOLGrid::GetState(unsigned int row, unsigned int col) const
{
    return m_States.at(GetIndex(row, col));  
}

void GOLGrid::SetState(GOLGrid::State state, unsigned int row, unsigned int col)
{
    unsigned index = GetIndex(row, col);
    auto& vertex = GetVertex(index);
    m_States.at(index) = state;
    switch (state)
    {
    case State::Dead:
        vertex.color = sf::Color::Black;
        break;
    case State::Alive:
        vertex.color = sf::Color::White;
        break;
    case State::Dying:
        vertex.color = sf::Color::Red;
        break;
    case State::Ressurecting:
        vertex.color = sf::Color::Green;
        break;
    default:
        vertex.color = sf::Color::Yellow;
    }
}
 
}