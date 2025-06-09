cmake_minimum_required(VERSION 3.10)

project(RaytraCer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

#find_package(sdl2 CONFIG REQUIRED)

add_executable(raytracer "Sources/RaytraCer.cpp" "Sources/RaytraCer.h" "Sources/Vector2.h" "Sources/Vector2.cpp" "Sources/Vector3.cpp" "Sources/Vector3.h" "Sources/Ray.h" "Sources/Ray.cpp" "Sources/Color.h" "Sources/Color.cpp" "Sources/Objects.h" "Sources/Objects.cpp" "Sources/Image.h" "Sources/Image.cpp"   "Sources/Scene.cpp" "Sources/Scene.h" "Sources/Utilities.h")

target_link_libraries(raytracer PRIVATE SDL3::SDL3)