#include "LangtonAnt.hpp"

namespace cellular::langton
{

class NormalLangtonAnt: public LangtonAnt
{
    private:
        enum Direction: int { Up = 0, Right = 1, Down = 2, Left = 3 };
        Direction m_Direction;
    public:
        NormalLangtonAnt();
        void SetDirection(Direction direction);
        virtual void Update(LangtonGrid& grid);
        void UpdatePosition(LangtonGrid& grid, int distance = 1);
        void TurnRight();
        void TurnLeft();
};

}