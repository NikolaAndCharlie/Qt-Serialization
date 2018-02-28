cmake_minimum_required(VERSION 3.5)
project(serialization)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

set(Qt_lib Qt5::Widgets Qt5::Core)

file(GLOB SRC src/*.cc)
file(GLOB HDR src/*.h)

add_executable(serialization WIN32 ${SRC} ${HDR})
target_link_libraries(serialization ${Qt_lib})
