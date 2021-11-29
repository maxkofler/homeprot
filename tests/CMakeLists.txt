
cmake_minimum_required(VERSION 3.5)
project (HomeProtTests)

include_directories(../include)
include_directories(./include)

file(GLOB_RECURSE Sources "src/**.cpp")

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
    homeprot
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
