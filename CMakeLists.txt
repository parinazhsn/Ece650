cmake_minimum_required(VERSION 3.10)
project(ece650-a2)

## ECE650 Specific configuration start here
## Project specific configurations go here

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/run)

# create the main executable
## add additional .cpp files if needed

add_Library(Main Main.cpp Main.cpp )
add_library(Graph Graph.h Graph.cpp )
add_library(Edge Edge.h Edge.cpp )
add_library(ShortestPath ShortestPath.h ShortestPath.cpp )
add_library(Vertex Vertex.h Vertex.cpp )
add_library(VistedPath VisitedPath.h VisitedPath.cpp )
#add_library(pch pch.h pch.cpp )

add_executable(a2-ece650 Main.cpp)
target_link_libraries(a2-ece650 PRIVATE Graph Edge ShortestPath Vertex VistedPath Main)

# create the executable for tests
#add_executable(tests test.cpp)
#install(PROGRAMS ece650-a1.py DESTINATION bin)
#install(TARGETS ece650-a2 ece650-a3 RUNTIME DESTINATION bin)
