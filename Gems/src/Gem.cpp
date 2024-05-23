#include <Gem.hpp>

Gem::Gem() {
    generateRandomColor();
    voidGem = false;
}

float Gem::getR() const {
    if (voidGem)
        return 0.0f;
    return r;
}

float Gem::getG() const {
    if (voidGem)
        return 0.0f;
    return g;
}

float Gem::getB() const {
    if (voidGem)
        return 0.0f;
    return b;
}

bool Gem::operator==(const Gem& other) const {
    return r == other.r && g == other.g && b == other.b;
}

void Gem::generateRandomColor() {
    int randomIndex = rand() % lenColorValues ;
    r = colorValues[randomIndex][0];
    g = colorValues[randomIndex][1];
    b = colorValues[randomIndex][2];
}
bool Gem::getVoidGem() const {
    return voidGem;
}
void Gem::setVoidGem() {
    if(voidGem){
        generateRandomColor();
        voidGem = false;
    }else{
        voidGem = true;
    }
}
void Gem::setColor(Gem* gem) {
    this->r = gem->getR();
    this->g = gem->getG();
    this->b = gem->getB();
}