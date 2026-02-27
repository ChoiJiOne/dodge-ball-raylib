cmake_minimum_required(VERSION 3.27)

add_subdirectory(raylib)
add_subdirectory(yaml-cpp)
add_subdirectory(msgpack-cpp)

set_target_properties(
    raylib
    yaml-cpp
    glfw
    msgpack-cxx-headers
    PROPERTIES FOLDER "ThirdParty"
)