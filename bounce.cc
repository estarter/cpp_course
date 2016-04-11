#include <iostream>

void drawParticle(const double particlePosition, const char& particleSymbol);
void moveParticle(double* particlePosition, double* particleSpeed);

const int maxColumn = 80;
const int minColumn = 0;

int main() {

  char particleSymbol = 'x';
  double particlePosition = 0;
  double particleSpeed = 6.3;
  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    drawParticle(particlePosition, particleSymbol);
    moveParticle(&particlePosition, &particleSpeed);
    timeStep++;
  }
}

void drawParticle(const double particlePosition, const char& particleSymbol) {
    for (int i = 0; i < particlePosition; i++) {
      std::cout << " ";
    }
    std::cout << particleSymbol << std::endl;
}

void moveParticle(double* particlePosition, double* particleSpeed) {
    *particlePosition += *particleSpeed;
    if (*particlePosition >= maxColumn) {
      *particlePosition = maxColumn;
      *particleSpeed = -*particleSpeed;
    } else if (*particlePosition < minColumn) {
      *particlePosition = minColumn;
      *particleSpeed = -*particleSpeed;
    }    
}
