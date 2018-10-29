#include "Langton.hpp"
#include "CellularAutomaton.hpp"

namespace cellular::langton
{

Langton::Langton(unsigned int width, unsigned int height)
    : CellularAutomaton(width, height),
      m_Grid(width, height),
      m_Ants(0)
{

}

void Langton::Update()
{
    for (auto& ant: m_Ants)
    {
        ant->Update(m_Grid);
    }
}

void Langton::PollEvents(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::R)
        {
            Reset();
        }
        break;
    }
}

void Langton::Reset()
{
    sf::Vector2u centre(m_Grid.GetWidth(), m_Grid.GetHeight());
    for (auto& ant: m_Ants)
    {
        ant->SetPosition(centre.x/2, centre.y/2);
    }
    m_Grid.Clear();
}

void Langton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Grid, states);
}

}