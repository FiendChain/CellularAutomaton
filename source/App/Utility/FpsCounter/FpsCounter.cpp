#include "FpsCounter.hpp"
#include <sstream>

FpsCounter::FpsCounter()
{
    m_Text.setColor(sf::Color::White);
    m_Text.setCharacterSize(12.0f);
    m_Text.setPosition(10, 10);
}

void FpsCounter::Update(const sf::Clock& clock)
{
    m_FrameTime = (clock.getElapsedTime() - m_LastFrameRender).asMilliseconds();
    m_LastFrameRender = clock.getElapsedTime();
    SetFps(1000.0f/(float)m_FrameTime);
}

void FpsCounter::SetFps(float fps)
{
    m_Fps = fps;
    std::stringstream ss;
    ss << "Fps: " << fps;
    m_Text.setString(ss.str());
}

void FpsCounter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Text, states);
}
