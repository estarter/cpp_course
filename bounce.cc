#include <iostream>

void clearScreen(char* screen);
void drawScreen(char screen[]);
void drawParticle(char screen[], const int particlePosition, const char& particleSymbol);
void moveParticle(double& particlePosition, double& particleSpeed);

const int maxColumn = 80;
const int minColumn = 0;
const int screenSize = maxColumn+1;

const int particleAmount = 4;

struct Particle {
  char symbol;
  double position;
  double speed;
};

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
      drawParticle(screen, particleList[i].position, particleList[i].symbol);
      moveParticle(particleList[i].position, particleList[i].speed);
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

void drawParticle(char screen[], const int particlePosition, const char& particleSymbol) {
  screen[particlePosition] = particleSymbol;
}

void moveParticle(double& particlePosition, double& particleSpeed) {
    particlePosition += particleSpeed;
    if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }    
}
