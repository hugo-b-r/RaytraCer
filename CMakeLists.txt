cmake_minimum_required(VERSION 3.14)

project(RaytraCer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

#find_package(sdl2 CONFIG REQUIRED)

add_executable(raytracer "Sources/RaytraCer.cpp" "Sources/RaytraCer.h" "Sources/Vector2.h" "Sources/Vector2.cpp" "Sources/Vector3.cpp" "Sources/Vector3.h" "Sources/Ray.h" "Sources/Ray.cpp" "Sources/Color.h" "Sources/Color.cpp" "Sources/Objects.h" "Sources/Objects.cpp"     "Sources/Scene.cpp" "Sources/Scene.h" "Sources/Utilities.h" "Sources/RealWindow.h" "Sources/RealWindow.cpp" "Sources/Utilities.cpp")

target_link_libraries(raytracer PRIVATE SDL3::SDL3)