#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;
const int screenSize = maxColumn+1;

const int particleAmount = 4;

struct Particle {
  char symbol;
  double position;
  double speed;
};


void clearScreen(char* screen);
void drawScreen(char screen[]);
void drawParticle(char screen[], const Particle& particle);
void moveParticle(Particle& particle);

int main() {
  char* screen = new char[screenSize];

  Particle particleList[particleAmount];
  particleList[0].symbol = 'x';
  particleList[1].symbol = '+';
  particleList[2].symbol = 'a';
  particleList[3].symbol = 'b';
  particleList[0].position = 1;
  particleList[1].position = 2;
  particleList[2].position = 3;
  particleList[3].position = 4;
  particleList[0].speed = 1.1;
  particleList[1].speed = 2.2;
  particleList[2].speed = 3.3;
  particleList[3].speed = 4.4;

  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    clearScreen(screen);
    for (int i = 0; i < particleAmount; i++) {
      drawParticle(screen, particleList[i]);
      moveParticle(particleList[i]);
    }
    drawScreen(screen);
    timeStep++;
  }
  delete[] screen;
}

void clearScreen(char* screen) {
  char * end = screen + screenSize;
  for (; screen < end; screen++) {
    *screen = ' ';
  }
}
void drawScreen(char screen[]) {
  for (int i = 0; i < screenSize; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

void drawParticle(char screen[], const Particle& particle) {
  screen[static_cast<int>(particle.position)] = particle.symbol;
}

void moveParticle(Particle& particle) {
    particle.position += particle.speed;
    if (particle.position >= maxColumn) {
      particle.position = maxColumn;
      particle.speed = -particle.speed;
    } else if (particle.position < minColumn) {
      particle.position = minColumn;
      particle.speed = -particle.speed;
    }    
}
