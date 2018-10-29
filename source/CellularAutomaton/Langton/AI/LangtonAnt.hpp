#pragma once

#include <SFML/Graphics.hpp>
#include "../LangtonGrid.hpp"

namespace cellular::langton
{

class LangtonAnt: public sf::Drawable
{
    private:
        sf::Vector2u m_Position;
    public:
        LangtonAnt();
        virtual void Update(LangtonGrid& grid) = 0;
        void SetPosition(unsigned int x, unsigned int y);
        inline sf::Vector2u& GetPosition() { return m_Position; }
    private:    
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}