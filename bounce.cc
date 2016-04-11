#include <iostream>

void clearScreen(char screen[]);
void drawScreen(char screen[]);
void drawParticle(char screen[], const int particlePosition, const char& particleSymbol);
void moveParticle(double& particlePosition, double& particleSpeed);

const int maxColumn = 80;
const int minColumn = 0;
const int screenSize = maxColumn+1;

const int particleAmount = 4;

int main() {
  char screen[screenSize];

  char particleSymbols[particleAmount] = {'x', '+', 'a', 'b'};
  double particlePositions[particleAmount] = {1, 2, 3, 4};
  double particleSpeeds[particleAmount] = {1.1, 2.2, 3.3, 4.4};

  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    clearScreen(screen);
    for (int i = 0; i < particleAmount; i++) {
      drawParticle(screen, particlePositions[i], particleSymbols[i]);
      moveParticle(particlePositions[i], particleSpeeds[i]);
    }
    drawScreen(screen);
    timeStep++;
  }
}

void clearScreen(char screen[]) {
  for (int i = 0; i < screenSize; i++) {
    screen[i] = ' ';
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
