#include "LangtonGrid.hpp"

namespace cellular::langton
{

LangtonGrid::LangtonGrid(unsigned int width, unsigned int height)
    : m_Width(width), m_Height(height),
      m_States(width*height, State::White),
      m_Vertices(width*height)
{
    for (unsigned int row = 0; row < m_Height; row++)
        for (unsigned int col = 0; col < m_Width; col++)
        {
            auto& vertex = m_Vertices.at(GetIndex(row, col));
            vertex.position = sf::Vector2f(col, row);
            vertex.color = sf::Color::White;
        }
}

void LangtonGrid::Clear(State state)
{
    for (unsigned int row = 0; row < m_Height; row++)
        for (unsigned int col = 0; col < m_Width; col++)
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
    auto& vertex = m_Vertices.at(GetIndex(row, col));
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

unsigned int LangtonGrid::GetIndex(int row, int col) const
{
    row %= (int)m_Height;
    if (row < 0) 
        row += (int)m_Height;
    
    col %= (int)m_Width;
    if (col < 0)
        col += (int)m_Width;

    return row*m_Width + col; 
}

void LangtonGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Vertices.data(), m_Vertices.size(), sf::Points, states);
}

}