cmake_minimum_required (VERSION 3.5)

project(HomeProt)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)

include_directories(include)

file (GLOB_RECURSE libfiles "src/**.cpp")

add_library(homeprot STATIC ${libfiles})