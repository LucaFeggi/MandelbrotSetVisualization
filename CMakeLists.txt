cmake_minimum_required(VERSION 3.5.1)
project(mandelbrot_linux)

set(CMAKE_CXX_STANDARD 11)

set(PROJECTNAME "mandelbrot_linux")
set(INCLUDEDIRECTORY "./HeaderFiles")
set(SOURCEDIR "./SourceFiles")
# choosing directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# FindSDL2, FindSDL2_ttf modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

file(GLOB SOURCES "${SOURCEDIR}/*.cpp")
add_executable(${PROJECTNAME} ${SOURCES})

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_include_directories(${PROJECTNAME} PRIVATE ${INCLUDEDIRECTORY})
include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(${PROJECTNAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECTNAME} SDL2::SDL2 SDL2::Main SDL2::TTF)




# https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html
# https://cmake.org/cmake/help/latest/module/FindSDL_ttf.html
# https://github.com/tcbrindle/sdl2-cmake-scripts/tree/master
# https://github.com/aminosbh/sdl2-ttf-sample/blob/master/CMakeLists.txt

# setting folders for binaries, libraries
# https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir

# bash commands
# $ cmake -S . -B ./build
# $ cmake --build ./build
# $ x64/mandelbrot_linux
