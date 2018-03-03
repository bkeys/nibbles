cmake_minimum_required(VERSION 2.8.11)
project(nibbles)

# State directories for modules and binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Dependencies)
include(ExternalProject)

#Making the compiler as strict as possible
set(CMAKE_CXX_FLAGS "-std=c++14 -fno-elide-constructors -pedantic-errors -Werror -Wextra -Wall -Wpedantic -Winit-self -Wmissing-declarations -Wuninitialized -Woverloaded-virtual -Wold-style-cast -Wfatal-errors -O3 -ldl -pthread")
add_definitions(${CMAKE_CXX_FLAGS})

#Location of source filesfind_package(SDL2 REQUIRED)
file(GLOB SOURCE src/*.cpp src/*.hpp)

# Find dependencies
#find_package(SDL2 REQUIRED)
#if(NOT SDL2_FOUND)
    include(SDL2)
#    message(FATAL_ERROR "Package SDL2 is required, but not found!")
#endif(NOT SDL2_FOUND)

find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message(FATAL_ERROR "Package OpenGL is required, but not found!")
endif(NOT OpenGL_FOUND)

include(GLUT)
#find_package(GLUT)
#if(NOT GLUT_FOUND)
#    message(FATAL_ERROR "Package GLUT is required, but not found!")
#endif(NOT GLUT_FOUND)

# Specify include directories
include_directories(
    ${FREEGLUT_INCLUDE_DIR}
    ${OpenGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
)
message("${OPENGL_LIBRARIES} ------***")

# Create the binary
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})

# Link the libraries
add_dependencies(${CMAKE_PROJECT_NAME} sdl2 freeglut)

target_link_libraries(${CMAKE_PROJECT_NAME}
  ${FREEGLUT_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${SDL2_LIBRARY}
)
