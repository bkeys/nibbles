project("nibbles")

cmake_minimum_required(VERSION 2.8)
file(GLOB SOURCES src/*.cpp src/*.hpp)

add_executable(nibbles ${SOURCES})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


include_directories(${OPENGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})

target_link_libraries(nibbles ${OPENGL_LIBRARIES} ${SDL2_LIBRARY} ${GLUT_LIBRARY})

