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
    void drawParticle(Screen& screen) const;
    virtual void moveParticle();
    friend std::istream& operator>>(std::istream&, Particle& p);
};

class MagicParticle : public Particle {
public:
    virtual void moveParticle();
};
#endif
