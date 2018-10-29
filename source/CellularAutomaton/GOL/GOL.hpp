#pragma once

#include "GOLGrid.hpp"
#include "Rules/GOLNormal.hpp"
#include "ThreadPool.hpp"

#include <SFML/Graphics.hpp>
#include <functional>
#include <thread>
#include <vector>
#include <memory>
#include <random>
#include "CellularAutomaton.hpp"

namespace cellular::gol
{

typedef std::function<GOLGrid::State(GOLGrid&, unsigned int, unsigned int)> GOLFunc;

class GOL: public CellularAutomaton
{
    private:
        std::unique_ptr<GOLGrid> m_Grid, m_Buffer;   
        ThreadPool m_ThreadPool;
        std::vector<std::function<void(const GOLFunc&)>> m_ThreadFunctions;
        std::default_random_engine m_RngEngine;
        const int m_TotalThreads;
    public:
        GOL(unsigned int width, unsigned int height, unsigned int totalThreads);
        virtual void Update(); 
        virtual void PollEvents(const sf::Event& event);
        template <class RNG>
        void Randomise(RNG& engine, float threshold);
    private:
        void CreateThreads();
        void UpdateThread(const GOLFunc& func, unsigned int rowStart, unsigned int rowEnd);
        void SwapBuffers();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

template <class RNG>
void GOL::Randomise(RNG& engine, float threshold)
{
    std::uniform_real_distribution<float> probability(0, 1);
    for (unsigned int row = 0; row < GetHeight(); row++)
        for (unsigned int col = 0; col < GetWidth(); col++)
        {
            if (probability(engine) > threshold)
                m_Grid->SetState(GOLGrid::State::Dead, row, col);
            else
                m_Grid->SetState(GOLGrid::State::Alive, row, col);
        }
}

}