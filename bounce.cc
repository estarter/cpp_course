#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "particle.h"
#include "screen.h"


int main() {
    Screen screen(maxColumn+1);
    std::vector<std::unique_ptr<Particle>> particleList;

    std::string filename = "bounce.cfg";
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return EXIT_FAILURE;
    } else {
        int i = 1;
        do {
            char type, symbol;
            double position, speed;
            in >> type >> symbol >> position >> speed;
            if (in.eof()) break;
            if (!in.good()) {
                std::cerr << "Bad data in file: " << filename << " , line number: " << i << std::endl;
                return EXIT_FAILURE;
            }

            if (type == 'm') {
                particleList.push_back(std::make_unique<MagicParticle>(symbol, position, speed));
            } else if (type == 'p') {
                particleList.push_back(std::make_unique<NormalParticle>(symbol, position, speed));
            }
            i++;
        } while (!in.eof());
    }

    int timeStep = 0;
    int stopTime = 60;

    while (timeStep < stopTime) {
        screen.clearScreen();
        for (auto& particle : particleList) {
            particle->drawParticle(screen);
            particle->moveParticle();
        }
        screen.drawScreen();
        timeStep++;
    }
}
