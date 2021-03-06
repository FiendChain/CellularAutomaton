#pragma once

#include "Camera/ControllableCamera.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "Utility/FpsCounter/FpsCounter.hpp"
#include "CellularAutomaton.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include <memory>

class App
{
    private:
        unsigned int m_Width, m_Height, m_Fps;
        bool m_Paused;
        sf::RenderWindow m_Window;
        ControllableCamera m_Camera;
        ResourceManager m_ResourceManager;
        FpsCounter m_FpsCounter;
        std::unique_ptr<cellular::CellularAutomaton> m_CellularAutomaton; 
    public:
        App(unsigned int width, unsigned int height, unsigned int fps, const std::string& title = "Cellular Automaton");
        void Run();
        template <typename T, typename ...Args>
        T& SetCellularAutomaton(Args&& ...args);
    private:
        void PollEvents();
        void PollKeyPresses(sf::Keyboard::Key& key);
        void Resize(float x, float y);
        void SetFrameRate(unsigned int fps);
        void Update();
        void Render();
};

template <typename T, typename ...Args>
T& App::SetCellularAutomaton(Args&& ...args) 
{
    T *automaton = new T(std::forward<Args>(args)...);
    m_CellularAutomaton = std::unique_ptr<cellular::CellularAutomaton>(automaton);
    return *automaton;
}