#include "particle.h"
#include "screen.h"


const int particleAmount = 4;


int main() {
  Screen screen(maxColumn+1);

  Particle particleList[particleAmount];

  particleList[0].set('x', 1, 1.1);
  particleList[1].set('+', 2, 2.1);
  particleList[2].set('a', 3, 3.1);
  particleList[3].set('b', 4, 4.1);

  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    screen.clearScreen();
    for (int i = 0; i < particleAmount; i++) {
      particleList[i].drawParticle(screen);
      particleList[i].moveParticle();
    }
    screen.drawScreen();
    timeStep++;
  }
}
