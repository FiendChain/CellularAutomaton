#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace cellular
{

class CellularAutomatonGrid: public sf::Drawable
{
    private:
        const unsigned m_Width, m_Height;
        std::vector<sf::Vertex> m_Vertices;
    public:
        CellularAutomatonGrid(unsigned width, unsigned height);
        sf::Vertex& GetVertex(unsigned row, unsigned col);
        sf::Vertex& GetVertex(unsigned index);
        inline unsigned GetWidth() const { return m_Width; }
        inline unsigned GetHeight() const { return m_Height; }
        virtual unsigned GetIndex(int row, int col) const;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}