# cpp_course

## Intro
Following Jacek Generowicz's C++ course at CERN

Materials:

1. http://jacek.web.cern.ch/jacek/courses/c++1/course.html
2. http://jacek.web.cern.ch/jacek/courses/c++-modern/course.html
3. http://jacek.web.cern.ch/jacek/courses/c++-generic-and-STL/course.html

Resources:

1. http://en.cppreference.com/ (or http://www.cplusplus.com/)

## STL notes 

###Containers:
- sequential (performance: [table](http://john-ahlgren.blogspot.ch/2013/10/stl-container-performance.html) or [flowchart](http://stackoverflow.com/questions/10699265/how-can-i-efficiently-select-a-standard-library-container-in-c11) from [source](http://homepages.e3.net.nz/~djm/cppcontainers.html))
 - `vector` - resizable array
 - `list` - double linked list
 - `deque` - (list of arrays) double ended queue
 - `forward_list` - single linked list
 - `array` - fixed size array
- associative
 - `set` - binary tree, unique values kept ordered 
 - `map` - binary tree, key-values container with unique keys
 - `multset`/`multimap` - allows to keep multiple items
 - `unordered_set`/`unordered_map` - use hash function
 - `unordered_multiset`/`unordered_multimap`
- adapters
 - `stack` - provides FILO on top of a container (deque by default)
 - `queue` - provides FIFO on top of a container (deque by default)
 - `priority_queue` - provides heap on top of a container (vector by default)

###Iterators
Types: input/output/forward/bidirectional/random access 
- `begin(vector<int> {})`/`rbegin`/`cbegin`/`crbegin` - return an iterator for given container
- `end(vector<int> {})`/... - return an iterator for given container 
- `front_inserter` / `back_inserter` - insert new item in front/back
- `inserter` - insert new item in the given place
- `istream_iterator`/`ostream_iterator` - to deal with std::cin/std::cout
- helper functions: `advance(it)` / `distance(it)` / `next(it)` / `prev(it)`

###Algorithms
Typical signature: ```std::alg(InputIt begin, InputIt end, OutputIt out)```
An algorithm may have alg_if, alg_n, alg_backward, ... implementations.
- `std::for_each` - call function (lambda) for the range
- `std::generate` - to populates data in existing container
- `std::generate_n` - allows to create new items
- `std::iota(begin(v), end(v), 0)` - fills contrainer sequentually
- `std::copy` and `std::copy_if` - copy from range to an iterator (+ ostream_iterator) (begin allows to modify existing, inserter to add new)
- `vector.insert` - faster than inserter iterator or std::copy 
- `std::transform` - copy with modification
- `std::accumulate` - reduce to return a single item (sum, max, multiplication, ...)
- `std::find` and `std::find_if` - return an iterator to the first element matching criteria
- `std::remove` - don't forget to call erase ```v.erase(remove(begin(v), end(v), 666), end(v));```
- more algs: http://en.cppreference.com/w/cpp/header/algorithm

### Others
- `std::numeric_limits<int>::max()` - max value for int
- `std::plus` and other functional objects from http://en.cppreference.com/w/cpp/utility/functional
- `std::sort` / `std::make_heap` / `std::binary_search` / `std::boyer_moore_searcher`
- `std::is_permutation` / `std::next_permutation` / `std::prev_permutation`

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
