# cpp_course

## Intro
Following Jacek Generowicz's C++ course at CERN

Materials:

1. http://jacek.web.cern.ch/jacek/courses/c++1/course.html
2. http://jacek.web.cern.ch/jacek/courses/c++-modern/course.html
3. http://jacek.web.cern.ch/jacek/courses/c++-generic-and-STL/course.html

Resources:

1. http://en.cppreference.com/ (or http://www.cplusplus.com/)

## QA
Unit testing is done using google test (https://github.com/google/googletest)  
Googletest are linked as submodule, to update use command

    git submodule update --init --recursive

## Related

Tools:
- Valgrind for the memory leak run-time analysis: http://valgrind.org/

```bash
    clang++ -Wall -ansi -pedantic -std=c++14 -g main.cc # add -g flag to give to valgrind an access to the sources
    valgrind --leak-check=full ./a.out
```
