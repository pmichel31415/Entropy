CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Entropy)

add_definitions(-std=gnu++11)
add_definitions(-fpermissive)

ADD_EXECUTABLE(entropy main.cpp Storing/store.h Storing/store.cpp Storing/store_tree.h Storing/store_tree.cpp Storing/simple_tree.h Storing/simple_tree.cpp construct.h construct.cpp gen.h gen.cpp entropy.h entropy.cpp def.h)

