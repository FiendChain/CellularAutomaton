#include "LangtonGrid.hpp"
 
namespace cellular::langton
{

LangtonGrid::LangtonGrid(unsigned int width, unsigned int height)
    : CellularAutomatonGrid(width, height),
      m_States(width*height, State::White)
{

}

void LangtonGrid::Clear(State state)
{
    for (unsigned int row = 0; row < GetHeight(); row++)
        for (unsigned int col = 0; col < GetWidth(); col++)
        {
            SetState(state, row, col);
        }
}

LangtonGrid::State LangtonGrid::GetState(int row, int col) const
{
    return m_States.at(GetIndex(row, col));
}

void LangtonGrid::SetState(LangtonGrid::State state, int row, int col)
{
    m_States.at(GetIndex(row, col)) = state; 
    auto& vertex = GetVertex(row, col);
    switch (state)
    {
    case State::White:
        vertex.color = sf::Color::White;
        break;
    case State::Black:
        vertex.color = sf::Color::Black;
        break;
    }
}

}