#include "gtest/gtest.h"
#include "particle.h"

TEST(NormalParticle, move) {
    NormalParticle p('x', 2, 40);
    p.moveParticle();
    EXPECT_EQ(42, p.getPosition());
    p.moveParticle();
    EXPECT_EQ(80, p.getPosition());
    p.moveParticle();
    EXPECT_EQ(40, p.getPosition());
}

TEST(MagicParticle, move) {
    MagicParticle p('x', 2, 40);
    p.moveParticle();
    EXPECT_EQ(42, p.getPosition());
    p.moveParticle();
    EXPECT_EQ(0, p.getPosition());
    p.moveParticle();
    EXPECT_EQ(40, p.getPosition());
}
