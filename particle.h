#ifndef PARTICLE_H
#define PARTICLE_H

#include "screen.h"

extern const int maxColumn;
extern const int minColumn;

class Particle {
  char symbol;
  double position;
  double speed;
public:
  Particle();
  void set(char symbol, double position, double speed);
  void drawParticle(Screen& screen) const;
  void moveParticle();
};

#endif
