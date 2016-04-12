#include "gtest/gtest.h"
#include "particle.h"

TEST(Particle, moveParticle) {
    Particle p;
    p.set('x', 2, 4);
    p.moveParticle();
    EXPECT_EQ(6, p.getPosition());
    p.moveParticle();
    EXPECT_EQ(10, p.getPosition());
}
