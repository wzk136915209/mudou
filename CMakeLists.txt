cmake_minimum_required(VERSION 3.16)
project(mudou)
set(Debug_Release Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE ${Debug_Release})
find_package(Boost 1.65.0 REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})

add_executable(mudou main.cpp)
target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC
#        Boost
        ${Boost_LIBRARIES}
        pthread
        )
#message(" int  ${Boost_LIBRARIES} boost")
