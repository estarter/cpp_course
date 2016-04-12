#include "screen.h"
#include <iostream>
#include <algorithm>

Screen::Screen(int screenSize) : 
      screenSize(screenSize),
      screen(new char[screenSize]) { }

Screen::Screen(const Screen& orig) :
    screenSize(orig.screenSize),
    screen(new char[screenSize]) {
  std::copy(orig.screen, orig.screen + screenSize, this->screen);
}

Screen::~Screen() {
  delete[] screen;
}

Screen& Screen::operator=(const Screen& other) {
  // self-assignment check
  if (this == &other) {
    return *this;
  }
  // assignment logic
  screenSize = other.screenSize;
  delete[] screen;
  screen = new char[screenSize];
  std::copy(other.screen, other.screen + screenSize, this->screen);
  return *this;
}

void Screen::clearScreen() {
  for (int i = 0; i < screenSize; i++) {
    screen[i] = ' ';
  }
}

void Screen::drawScreen() {
  for (int i = 0; i < screenSize; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

char& Screen::operator[](unsigned pos) {
  return screen[pos];
}

