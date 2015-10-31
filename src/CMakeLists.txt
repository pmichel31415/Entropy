CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Entropy)

ADD_EXECUTABLE(entropy main.cpp Storing/store.h Storing/store.cpp Storing/store_tree.h Storing/store_tree.cpp Storing/simple_tree.h Storing/simple_tree.cpp Testing/test.h Testing/test.cpp construct.h construct.cpp)
