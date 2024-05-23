#include <Board.hpp>
#include <main.hpp>

Board::Board(int width, int height){
    this->width = width;
    this->height = height;
    grid = new Gem**[width];
    for (int i = 0; i < width; ++i) {
        grid[i] = new Gem*[height];
    } 
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            grid[i][j] = new Gem();
        }  
    }    
}

Board::~Board(){
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            delete[] grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;
    for (Bonus* bonus : bonuses) {
        delete bonus;
    }
}

void Board::swap(int prevRow, int prevCol, int row, int col){
    Gem* temp = grid[prevRow][prevCol];
    grid[prevRow][prevCol] = grid[row][col];
    grid[row][col] = temp;
}

bool Board::searchSerialVoidGem(int row, int col){
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; ++i) {
        int newcol = col + dx[i];
        int newrow = row + dy[i];
        if (newcol > 0 && newcol < width &&
            newrow > 0 && newrow < height &&
            grid[newcol][newrow]->getVoidGem() && 
            *grid[newcol][newrow] == *grid[col][row]){

            grid[col][row]->setVoidGem();
            draw();
            return true;
        }
    }
    return false;
}

bool Board::isValidCell(int col, int row) {
    return col >= 0 && col < width && row >= 0 && row < height && !grid[col][row]->getVoidGem();
}

bool Board::searchSerialGem(int row, int col){
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int newCol1 = col + dx[i];
        int newRow1 = row + dy[i];
        if (isValidCell(newCol1, newRow1)&& 
            *grid[newCol1][newRow1] == *grid[col][row]){
            for (int j = 0; j < 4; j++) {
                int newCol2 = newCol1 + dx[j];
                int newRow2 = newRow1 + dy[j];

                if (isValidCell(newCol2, newRow2) && 
                    *grid[newCol2][newRow2] == *grid[col][row] &&
                    !(col == newCol2 && row == newRow2)){
                    int rangombonus = rand() % 10;
                    if (rangombonus == 0){
                        bonuses.push_back(new BombBonus(col, row));
                    } else if (rangombonus == 1){
                        bonuses.push_back(new PaintBonus(col, row));
                    }else{
                        grid[col][row]->setVoidGem();
                    }
                    grid[newCol1][newRow1]->setVoidGem();
                    grid[newCol2][newRow2]->setVoidGem();
                    draw();
                    return true;
                }
            }
        }
    }
    return false;
}
void Board::processSerialGrid() {
    bool process = true;
    while (process){
        process = false;
        for (int col = 0; col < width; col++) {
            for (int row = 0; row < height; row++) {
                if (grid[col][row]->getVoidGem()){
                    continue;
                }
                if (searchSerialVoidGem(row, col)){
                    process = true;
                    continue;
                }

                if (searchSerialGem(row, col)){
                    process = true;
                    continue;
                }
            }
        }
    }
}
void Board::VoidGemUp(){
    bool process = true;
    while (process){
        process = false;
        for (int col = 1; col < width; col++) {
            for (int row = 0; row < height; row++) {
                if(grid[col][row]->getVoidGem() && !grid[col-1][row]->getVoidGem()){
                    swap(col, row, col-1, row);
                    process = true;
                }
            }
            draw();
        }
    }
}

void Board::processVoidGem() {
    bool process = true;
    while (process){
        process = false;
        VoidGemUp();
        for (int row = 0; row < height; row++) {
            if (grid[0][row]->getVoidGem()){
                grid[0][row]->setVoidGem();
                process = true;              
            }
        }
        draw();  
    }
}

void Board::render() {
    draw();
    processSerialGrid();
    processVoidGem();
    UsedBonus();
}

void Board::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            drawSquare(i, j);
        }
    }
    glfwSwapBuffers(window);
    glfwPollEvents();
}
void Board::drawSquare(int row, int col) {

    glColor3f(grid[row][col]->getR(),  grid[row][col]->getG(),  grid[row][col]->getB());
    glBegin(GL_QUADS);
    glVertex2f(-1.0f + 2.0f * (col) / (height), 1.0f - 2.0f * (row) / (width));
    glVertex2f(-1.0f + 2.0f * (col+1) / (height), 1.0f - 2.0f * (row) / (width));
    glVertex2f(-1.0f + 2.0f * (col+1) / (height), 1.0f - 2.0f * (row+1) / (width));
    glVertex2f(-1.0f + 2.0f * (col) / (height), 1.0f - 2.0f * (row+1) / (width));
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0f + 2.0f * (col) / (height), 1.0f - 2.0f * (row) / (width));
    glVertex2f(-1.0f + 2.0f * (col+1) / (height), 1.0f - 2.0f * (row) / (width));
    glVertex2f(-1.0f + 2.0f * (col+1) / (height), 1.0f - 2.0f * (row+1) / (width));
    glVertex2f(-1.0f + 2.0f * (col) / (height), 1.0f - 2.0f * (row+1) / (width));
    glEnd();
}

void Board::UsedBonus(){
    for (auto& bonus : bonuses) {
        bonus->useBonus(grid);
        draw();
    }

    for (Bonus* bonus : bonuses) {
        delete bonus;
    }
    bonuses.clear();
}

