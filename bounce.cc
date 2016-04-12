#include <iostream>
#include <algorithm>

const int maxColumn = 80;
const int minColumn = 0;

const int particleAmount = 4;

class Screen {
  const int screenSize;
  char* screen;
public:
  Screen(int screenSize) : 
        screenSize(screenSize),
        screen(new char[screenSize]) { }
  Screen(const Screen& orig) :
      screenSize(orig.screenSize),
      screen(new char[screenSize]) {
    std::copy(orig.screen, orig.screen + screenSize, this->screen);
  }
  ~Screen() {
    delete[] screen;
  }

  void clearScreen() {
    for (int i = 0; i < screenSize; i++) {
      screen[i] = ' ';
    }
  }
  void drawScreen() {
    for (int i = 0; i < screenSize; i++) {
      std::cout << screen[i];
    }
    std::cout << std::endl;
  }
  char& operator[](unsigned pos) {
    return screen[pos];
  }
};

class Particle {
  char symbol;
  double position;
  double speed;
public:
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
  void drawParticle(Screen& screen) const {
    screen[this->position] = this->symbol;
  }

  void moveParticle() {
      position += speed;
      if (this->position >= maxColumn) {
        this->position = maxColumn;
        this->speed = -this->speed;
      } else if (this->position < minColumn) {
        this->position = minColumn;
        this->speed = -this->speed;
      }    
  }
};


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
