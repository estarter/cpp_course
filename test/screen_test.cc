#include "gtest/gtest.h"
#include "screen.h"


class ScreenTest : public ::testing::Test {
protected:
    Screen screen;
    ScreenTest() : screen(10) {}

    virtual void SetUp() {
        screen.clearScreen();
    }

  // virtual void TearDown() {}
};


TEST_F(ScreenTest, changing) {
    ASSERT_EQ(' ', screen[0]);
    screen[0] = 'x';
    ASSERT_EQ('x', screen[0]);
    screen.clearScreen();
    ASSERT_EQ(' ', screen[0]);
}

TEST_F(ScreenTest, copy_ctor) {
    screen[0] = 'x';

    Screen copy_screen = screen;
    ASSERT_EQ('x', copy_screen[0]);
    copy_screen[0] = 'o';
    ASSERT_EQ('o', copy_screen[0]);
    ASSERT_EQ('x', screen[0]);

    copy_screen.clearScreen();
    ASSERT_EQ(' ', copy_screen[0]);
    ASSERT_EQ('x', screen[0]);

    copy_screen[0] = 'o';
    screen.clearScreen();
    ASSERT_EQ('o', copy_screen[0]);
    ASSERT_EQ(' ', screen[0]);
}
