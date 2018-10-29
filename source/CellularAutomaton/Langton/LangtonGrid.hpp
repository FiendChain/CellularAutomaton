#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace cellular::langton
{

class LangtonGrid: public sf::Drawable
{
    public:
        enum State { White, Black };
    private:
        const unsigned int m_Width, m_Height;
        std::vector<State> m_States;
        std::vector<sf::Vertex> m_Vertices;
    public:
        LangtonGrid(unsigned int width, unsigned int height);
        void Clear(State state = State::White);
        State GetState(int row, int col) const;
        void SetState(State state, int row, int col);
        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }
    private:
        inline unsigned int GetIndex(int row, int col) const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

}