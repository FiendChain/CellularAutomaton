#include "GOL.hpp"
#include "CellularAutomaton.hpp"

#include <functional>
#include <thread>
#include <memory>

namespace cellular::gol
{

GOL::GOL(unsigned int width, unsigned int height, unsigned int totalThreads)
    : CellularAutomaton(width, height),
      m_Grid(std::make_unique<GOLGrid>(width, height)),
      m_Buffer(std::make_unique<GOLGrid>(width, height)),
      m_ThreadPool(totalThreads),
      m_ThreadFunctions(0),
      m_TotalThreads(totalThreads)
{
    if (m_TotalThreads <= 0)
        throw std::runtime_error("Couldn't create threads for GOL");
    CreateThreads();
    Randomise(m_RngEngine, 0.3f);
}

void GOL::Update()
{
    for (auto& threadFunc: m_ThreadFunctions)
    {
        m_ThreadPool.AddJob(std::bind(threadFunc, rules::Default));
    }

    m_ThreadPool.WaitUntilFinished();

    SwapBuffers();
}

void GOL::PollEvents(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::R)
        {
            Randomise(m_RngEngine, 0.3f);
        }
        break;
    }
}

void GOL::CreateThreads()
{
    unsigned int rowIter = GetHeight()/m_TotalThreads;
    unsigned int row = 0;
    unsigned int rowEnd = 0;
    for (unsigned int threadID = 0; threadID < m_TotalThreads; threadID++)
    {
        if (threadID == m_TotalThreads-1) rowEnd = GetHeight();
        else                              rowEnd = row + rowIter;
        m_ThreadFunctions.emplace_back([this, row, rowEnd](const GOLFunc& func) {
            UpdateThread(func, row, rowEnd);
        });
        row = rowEnd;
    }
}

void GOL::UpdateThread(const GOLFunc& func, unsigned int rowStart, unsigned int rowEnd)
{
    for (unsigned int row = rowStart; row < rowEnd; row++)
        for (unsigned int col = 0; col < GetWidth(); col++)
        {
            GOLGrid::State state = func(*m_Grid, row, col);
            m_Buffer->SetState(state, row, col);
        }
}

void GOL::SwapBuffers()
{
    m_Grid.swap(m_Buffer);
}

void GOL::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*m_Grid, states);
}

}