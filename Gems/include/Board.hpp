#pragma once
#include <const.hpp>
#include <Gem.hpp>
#include <Bonus.hpp>

class Board {
public:
    Board(int width, int height);
    ~Board();

    void render();
    void swap(int prevRow, int prevCol, int row, int col);

private:
    int width;
    int height;
    Gem*** grid;
    std::vector<Bonus*> bonuses;
    
    void draw();
    void drawSquare(int row, int col) ;
    void processSerialGrid();
    bool searchSerialVoidGem(int row, int col);
    bool searchSerialGem(int row, int col);
    bool isValidCell(int col, int row);
    void processVoidGem();
    void VoidGemUp();
    void UsedBonus();
};
