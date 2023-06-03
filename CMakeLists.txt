cmake_minimum_required( VERSION 3.2 )
project( FaboRobot )

include_directories(
    include
    ${PROJECT_SOURCE_DIR}/include
)

add_library(${PROJECT_NAME} SHARED
    src/Robot.cc
)

target_link_libraries(

)