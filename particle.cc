#include "particle.h"
#include "screen.h"

extern const int maxColumn = 80;
extern const int minColumn = 0;

Particle::Particle() : symbol('o'), position(0), speed(1) {}
Particle::Particle(char symbol, double position, double speed) : symbol(symbol), position(position), speed(speed) {}

void Particle::drawParticle(Screen& screen) const {
  screen[this->position] = this->symbol;
}

void Particle::moveParticle() {
    position += speed;
    if (this->position >= maxColumn) {
        this->position = maxColumn;
        this->speed = -this->speed;
    } else if (this->position < minColumn) {
        this->position = minColumn;
        this->speed = -this->speed;
    }    
}

std::istream& operator>>(std::istream& in, Particle& p) {
    return in >> p.symbol >> p.position >> p.speed;
}

void MagicParticle::moveParticle() {
    position += speed;
    if (this->position >= maxColumn) {
        this->position = minColumn;
    } else if (this->position < minColumn) {
        this->position = maxColumn;
    }    
}
