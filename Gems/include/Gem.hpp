#pragma once
#include <const.hpp>

class Gem {
protected:
    float r, g, b;
    bool voidGem;
public:
    float getR() const;
    float getG() const;
    float getB() const;
    bool getVoidGem() const;
    Gem();
    bool operator==(const Gem& other) const;
    void generateRandomColor();
    void setVoidGem();
    void setColor(Gem* gem);
};
