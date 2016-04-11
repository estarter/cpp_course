#include <iostream>

char particleSymbol = 'x';
void drawParticle(double particlePosition);
void moveParticle(double& particlePosition, double& particleSpeed, int minColumn, int maxColumn);

int main() {

  double particlePosition = 0;
  double particleSpeed = 6.3;
  int maxColumn = 80;
  int minColumn = 0;
  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    drawParticle(particlePosition);
    moveParticle(particlePosition, particleSpeed, minColumn, maxColumn);
    timeStep++;
  }
}

void drawParticle(double particlePosition) {
    for (int i = 0; i < particlePosition; i++) {
      std::cout << " ";
    }
    std::cout << particleSymbol << std::endl;

}
void moveParticle(double& particlePosition, double& particleSpeed, int minColumn, int maxColumn) {
    particlePosition += particleSpeed;
    if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }    
}
