#include "particle.h"

extern const int maxColumn = 80;
extern const int minColumn = 0;

Particle::Particle() {
  this->symbol = 'o';
  this->position = 0;
  this->speed = 1;
}
void Particle::set(char symbol, double position, double speed) {
  this->symbol = symbol;
  this->position = position;
  this->speed = speed;
}
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
