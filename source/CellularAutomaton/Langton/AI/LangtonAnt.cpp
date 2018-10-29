#include "LangtonAnt.hpp"

namespace cellular::langton
{

LangtonAnt::LangtonAnt()
    : m_Position(0, 0)
{

}

void LangtonAnt::SetPosition(unsigned int x, unsigned int y)
{
    m_Position.x = x;
    m_Position.y = y;
}

void LangtonAnt::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}

}