#include <iostream>
#include <fstream>
#include <cstdlib>
#include "particle.h"
#include "screen.h"


int main() {
    Screen screen(maxColumn+1);
    Particle* particleList;

    int particleAmount;

    std::string filename = "bounce.cfg";
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return EXIT_FAILURE;
    } else {
        in >> particleAmount;
        particleList = new Particle[particleAmount];
        for (int i = 0; i < particleAmount; i++) {
            char sym;
            double pos, speed;
            in >> sym >> pos >> speed;
            if (!in.good()) {
                std::cerr << "Bad data in file: " << filename << " , line number: " << i+2 << std::endl;
                return EXIT_FAILURE;
            }
            particleList[i].set(sym, pos, speed);
        }
    }

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
