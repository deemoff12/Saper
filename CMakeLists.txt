cmake_minimum_required(VERSION 3.13)
project(Saper)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "D:/Pobrane/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system)
add_executable(Saper main.cpp minesboard.h minesboard.cpp MSBoardTextView.h MSBoardTextView.cpp MSTextController.h MSTextController.cpp)

target_link_libraries(Saper sfml-graphics sfml-window sfml-system)

