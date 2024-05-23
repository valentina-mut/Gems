#include <Bonus.hpp>

Bonus::Bonus(int col, int row) {
    this->col = col;
    this->row = row;
}

PaintBonus::PaintBonus(int col, int row) : Bonus(col, row){}

void PaintBonus::useBonus(Gem*** grid) {
    int paintBonusBlock = 0;
    int rowPaint, colPaint;
    while (paintBonusBlock<3) {
        rowPaint = row + rand() % 5 - 2;
        colPaint = col + rand() % 5 - 2; 
        if (rowPaint>=0 && rowPaint <  GRIDHEIGHT &&
            colPaint>=0 && colPaint <  GRIDWIDTH &&
            !(grid[colPaint][rowPaint]->getVoidGem())) {
            grid[colPaint][rowPaint]->setColor(grid[col][row]);
            paintBonusBlock ++; 
        }    
    }
    grid[col][row]->setVoidGem();
}

BombBonus::BombBonus(int col, int row) : Bonus(col, row){}

void BombBonus::useBonus(Gem*** grid) {
    int BombBonusBlock = 0;
    while (BombBonusBlock < 5) {
        int i = rand() % GRIDWIDTH;
        int j = rand() % GRIDHEIGHT;
        if (!(grid[i][j]->getVoidGem())) {
            grid[i][j]->setVoidGem();
            BombBonusBlock++;
        }
    }
    grid[col][row]->setVoidGem();
}
