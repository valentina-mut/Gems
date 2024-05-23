#pragma once
#include <const.hpp>
#include <Gem.hpp>


class Bonus{
public:
    Bonus(int col, int row);
    virtual void useBonus(Gem*** grid)=0;
protected:
    int col;
    int row;
};

class PaintBonus : public Bonus {
public:
    PaintBonus(int col, int row);
    void useBonus(Gem*** grid);
};

class BombBonus : public Bonus {
public:
    BombBonus(int col, int row);
    void useBonus(Gem*** grid);
};