# -*- mode: makefile-gmake; -*-
# This is a minimalistic generic makefile with automatic dependency
# generation. It is only expected to work with GNU make and g++ or
# clang.

# For a fancier version, with copious explanatory comments, look at
# the file called 'Makefile' in this same directory

# Instructions for use:

GTEST_DIR = ./googletest/googletest

CPPFLAGS += -isystem $(GTEST_DIR)/include
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: bounce test

# 1.  Save this file in your source directory under the name
#     'Makefile'.

# 2.  If you do not use .cc as the filename extension for your C++
#     source code replace the three occurrances of .cc near the bottom
#     of this file, with whatever extension you use. Allowed choices
#     are:
#                       .cc .cp .cxx .cpp .CPP .c++ .C

# 3.  Make sure that the only files with the filename extension
#     specified in the last step, that can be found in the source
#     directory, are those which contain source code for your project.

# 4a. If you are using nonstandard libraries, you may have to specify
#     include directories here ...
	# -I /usr/local/include/SomeLibrary
CXXFLAGS += -ansi -pedantic -Wall
# 4b. ... and library directories here.
	# -L /usr/local/lib/SomeLibrary
LDFLAGS +=  

# 5.  If you want to use clang rather than g++, uncomment the next line
CXX := clang++

# 6.  Change 'executable' below, to whatever name you want your
#     executable to have.

# 7.  Type 'make' on the command line.

CPPFLAGS += -MD -MP

SOURCES := $(wildcard *.cc)

bounce: $(SOURCES:%.cc=%.o)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm *.o *.a *.d bounce bounce_test

-include $(SOURCES:%.cc=%.d)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

particle_test.o: test/particle_test.cc $(GTEST_HEADERS)
	# TODO how to include sources?
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c test/particle_test.cc -I.

screen_test.o: test/screen_test.cc $(GTEST_HEADERS)
	# TODO how to include sources?
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c test/screen_test.cc -I.

bounce_test: screen.o particle.o particle_test.o screen_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test: bounce_test
	./bounce_test

# TODO how to run test program from Makefile
