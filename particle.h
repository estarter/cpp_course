#ifndef PARTICLE_H
#define PARTICLE_H
#include <fstream>

class Screen;

extern const int maxColumn;
extern const int minColumn;

class Particle {
  char symbol;
  double position;
  double speed;
public:
  Particle();
  void drawParticle(Screen& screen) const;
  void moveParticle();
  friend std::istream& operator>>(std::istream&, Particle& p);
};

#endif
