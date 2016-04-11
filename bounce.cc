#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;
const int screenSize = maxColumn+1;

const int particleAmount = 4;

struct Particle {
  char symbol;
  double position;
  double speed;
  Particle() {
    this->symbol = 'o';
    this->position = 0;
    this->speed = 1;
  }
  void set(char symbol, double position, double speed) {
    this->symbol = symbol;
    this->position = position;
    this->speed = speed;
  }
  void drawParticle(char screen[]) {
    screen[static_cast<int>(this->position)] = this->symbol;
  }

  void moveParticle() {
      this->position += this->speed;
      if (this->position >= maxColumn) {
        this->position = maxColumn;
        this->speed = -this->speed;
      } else if (this->position < minColumn) {
        this->position = minColumn;
        this->speed = -this->speed;
      }    
  }

};

void clearScreen(char* screen);
void drawScreen(char screen[]);

int main() {
  char* screen = new char[screenSize];

  Particle particleList[particleAmount];

  particleList[0].set('x', 1, 1.1);
  particleList[1].set('+', 2, 2.1);
  particleList[2].set('a', 3, 3.1);
  particleList[3].set('b', 4, 4.1);

  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
    clearScreen(screen);
    for (int i = 0; i < particleAmount; i++) {
      particleList[i].drawParticle(screen);
      particleList[i].moveParticle();
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
