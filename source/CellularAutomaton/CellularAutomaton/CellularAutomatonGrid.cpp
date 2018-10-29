#include "CellularAutomatonGrid.hpp"

namespace cellular
{

CellularAutomatonGrid::CellularAutomatonGrid(unsigned width, unsigned height)
    : m_Width(width), m_Height(height),
      m_Vertices(width*height)
{
    for (unsigned row = 0; row < m_Height; row++)
        for (unsigned col = 0; col < m_Width; col++)
        {
            auto& vertex = m_Vertices.at(GetIndex(row, col));
            vertex.color = sf::Color::White;
            vertex.position = sf::Vector2f((float)col, (float)row);
        }
}

sf::Vertex& CellularAutomatonGrid::GetVertex(unsigned row, unsigned col)
{
    return m_Vertices.at(GetIndex(row, col)); 
}

sf::Vertex& CellularAutomatonGrid::GetVertex(unsigned index)
{
    return m_Vertices.at(index);
}

unsigned CellularAutomatonGrid::GetIndex(int row, int col) const
{
    row %= (int)m_Height;
    if (row < 0) 
        row += (int)m_Height;
    
    col %= (int)m_Width;
    if (col < 0)
        col += (int)m_Width;

    return row*m_Width + col; 
}

void CellularAutomatonGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Vertices.data(), m_Vertices.size(), sf::Points, states);
}

};