#pragma once
#include <SFML/Graphics.hpp>
#include "CellularAutomatonGrid.hpp"

namespace cellular
{

class CellularAutomaton: public sf::Drawable
{
    private:
        unsigned m_Width, m_Height;
    public:
        CellularAutomaton(unsigned width, unsigned height);
        inline unsigned GetWidth() const { return m_Width; }
        inline unsigned GetHeight() const { return m_Height; }
        virtual void PollEvents(const sf::Event& event) = 0;
        virtual void Update() = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

}
