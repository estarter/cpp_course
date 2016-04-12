#ifndef SCREEN_H
#define SCREEN_H

class Screen {
  int screenSize;
  char* screen;
public:
  Screen(int screenSize);
  Screen(const Screen& orig);
  ~Screen();
  Screen& operator=(const Screen& other);
  void clearScreen();
  void drawScreen();
  char& operator[](unsigned pos);
};

#endif
