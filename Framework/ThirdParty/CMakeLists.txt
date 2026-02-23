cmake_minimum_required(VERSION 3.27)

add_subdirectory(raylib)
add_subdirectory(yaml-cpp)

set_target_properties(
    raylib
    yaml-cpp
    glfw
    PROPERTIES FOLDER "ThirdParty"
)