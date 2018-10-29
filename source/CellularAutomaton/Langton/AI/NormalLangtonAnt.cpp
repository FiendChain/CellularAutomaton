#include "NormalLangtonAnt.hpp"

namespace cellular::langton
{

NormalLangtonAnt::NormalLangtonAnt()
    : m_Direction(Direction::Down)
{
    
}

void NormalLangtonAnt::SetDirection(Direction direction)
{
    m_Direction = direction;
}

void NormalLangtonAnt::Update(LangtonGrid& grid)
{
    const sf::Vector2u& position = GetPosition();
    LangtonGrid::State state = grid.GetState(position.y, position.x);
    switch (state)
    {
    case LangtonGrid::State::White: // turn right
        grid.SetState(LangtonGrid::State::Black, position.y, position.x);
        TurnRight();
        UpdatePosition(grid);
        break;
    case LangtonGrid::State::Black: // turn left
        grid.SetState(LangtonGrid::State::White, position.y, position.x);
        TurnLeft();
        UpdatePosition(grid);
        break;
    default:
        return;
    }
}

void NormalLangtonAnt::TurnRight()
{
    if (m_Direction == Direction::Left)
    {
        m_Direction = Direction::Up;
        return;
    }
    else
    {
        m_Direction = (Direction)(m_Direction + 1);
    }
}

void NormalLangtonAnt::TurnLeft()
{
    if (m_Direction == Direction::Up)
    {
        m_Direction = Direction::Left;
        return;
    }
    else
    {
        m_Direction = (Direction)(m_Direction - 1);
    }
}

void NormalLangtonAnt::UpdatePosition(LangtonGrid& grid, int distance)
{
    auto& position = GetPosition();
    sf::Vector2i newPosition(position.x, position.y);
    switch (m_Direction)
    {
    case Direction::Up:
        newPosition.y += distance;
        break;
    case Direction::Down:
        newPosition.y -= distance;
        break;
    case Direction::Left:
        newPosition.x -= distance;
        break;
    case Direction::Right:
        newPosition.x += distance;
        break;
    }
    // perform wrapping
    newPosition.x %= (int)grid.GetWidth();
    newPosition.y %= (int)grid.GetHeight();

    if (newPosition.x < 0) 
        newPosition.x += (int)grid.GetWidth();
    if (newPosition.y < 0)
        newPosition.y += (int)grid.GetHeight();

    position.x = newPosition.x;
    position.y = newPosition.y;
}

}