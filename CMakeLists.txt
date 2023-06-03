cmake_minimum_required( VERSION 3.18 )
project( faborobot )

include_directories(
    include
    ${PROJECT_SOURCE_DIR}/include
)

add_library(${PROJECT_NAME} SHARED
    src/Robot.cc
)