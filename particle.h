#ifndef PARTICLE_H
#define PARTICLE_H
#include <fstream>
#include <iostream>

class Screen;

extern const int maxColumn;
extern const int minColumn;

class Particle {
protected:
    char symbol;
    double position;
    double speed;
public:
    Particle();
    Particle(char symbol, double position, double speed);
    virtual ~Particle() {}
    char getSymbol() { return symbol;};
    double getPosition() { return position;};
    double getSpeed() { return speed;}
    void drawParticle(Screen& screen) const;
    virtual void moveParticle() = 0;
    friend std::istream& operator>>(std::istream&, Particle& p);
};

class NormalParticle : public Particle {
public:
    NormalParticle(char symbol, double position, double speed) : Particle(symbol, position, speed) {}
    virtual void moveParticle();
};

class MagicParticle : public Particle {
public:
    MagicParticle(char symbol, double position, double speed) : Particle(symbol, position, speed) {}
    virtual void moveParticle();
};
#endif
