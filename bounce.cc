#include <iostream>

void clearScreen();
void drawScreen();
void drawParticle(const int particlePosition, const char& particleSymbol);
void moveParticle(double& particlePosition, double& particleSpeed);

const int maxColumn = 80;
const int minColumn = 0;
char screen[maxColumn];

int main() {

  char particleSymbol = 'x';
  double particlePosition = 0;
  double particleSpeed = 6.3;
  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    clearScreen();
    drawParticle(particlePosition, particleSymbol);
    moveParticle(particlePosition, particleSpeed);
    drawScreen();
    timeStep++;
  }
}

void clearScreen() {
  for (int i = 0; i < maxColumn; i++) {
    screen[i] = ' ';
  }
}
void drawScreen() {
  for (int i = 0; i < maxColumn; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

void drawParticle(const int particlePosition, const char& particleSymbol) {
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
