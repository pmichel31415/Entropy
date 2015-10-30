CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Entropy)

ADD_EXECUTABLE(entropy main.cpp Storing/sqlite3.c Storing/sqlite3.h Storing/store.h Storing/store_map.cpp Storing/store_sqlite.cpp construct.cpp)
