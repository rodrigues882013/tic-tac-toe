cmake_minimum_required(VERSION 3.9)
project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 11)

# Set source and header folders
file(GLOB src "src/*.cpp")
file(GLOB includes "includes/*.hpp" )

add_executable(tic-tac-toe ${src} ${includes})

# SFML config
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(tic-tac-toe ${SFML_LIBRARIES})
endif()

