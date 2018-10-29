#pragma once

#include <SFML/Graphics.hpp>
#include "CellularAutomaton.hpp"
#include "LangtonGrid.hpp"
#include "AI/LangtonAnt.hpp"
#include <vector>
#include <memory>

namespace cellular::langton
{

class Langton: public CellularAutomaton 
{
    private:
        LangtonGrid m_Grid;
        std::vector<std::unique_ptr<LangtonAnt>> m_Ants;
    public:
        Langton(unsigned int width, unsigned int height);
        virtual void Update();
        virtual void PollEvents(const sf::Event& event);
        template <typename RNG>
        void Randomise(RNG& rng);
        template <typename T, typename ...Args>
        T& AddAnt(Args&& ...args);
        void Reset();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

template <typename T, typename ...Args>
T& Langton::AddAnt(Args&& ...args)
{
    T *ant = new T(std::forward<Args>(args)...);
    m_Ants.push_back(std::unique_ptr<LangtonAnt>(ant));
    return *ant;
}

}

