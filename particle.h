#ifndef PARTICLE_H
#define PARTICLE_H

#include "screen.h"

static int maxColumn = 80;
static int minColumn = 0;

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
