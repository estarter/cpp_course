#include "gtest/gtest.h"
#include "screen.h"

TEST(Screen, changing) {
    Screen screen(10);
    screen.clearScreen();
    ASSERT_EQ(' ', screen[0]);
    screen[0] = 'x';
    ASSERT_EQ('x', screen[0]);
    screen.clearScreen();
    ASSERT_EQ(' ', screen[0]);
}

TEST(Screen, copy_ctor) {
    Screen orig_screen(10);
    orig_screen.clearScreen();
    orig_screen[0] = 'x';

    Screen copy_screen = orig_screen;
    ASSERT_EQ('x', copy_screen[0]);
    copy_screen[0] = 'o';
    ASSERT_EQ('o', copy_screen[0]);
    ASSERT_EQ('x', orig_screen[0]);

    copy_screen.clearScreen();
    ASSERT_EQ(' ', copy_screen[0]);
    ASSERT_EQ('x', orig_screen[0]);

    copy_screen[0] = 'o';
    orig_screen.clearScreen();
    ASSERT_EQ('o', copy_screen[0]);
    ASSERT_EQ(' ', orig_screen[0]);
}
