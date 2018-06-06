cmake_minimum_required(VERSION 2.8.12)
project(my_project)

set(CMAKE_CXX_FLAGS "/W3 /WX /wd4005 /wd4068 /wd4244 /wd4267 /wd4800 /DNOMINMAX /DWIN32_LEAN_AND_MEAN /D_CRT_SECURE_NO_WARNINGS ${CMAKE_CXX_FLAGS}")
option(BUILD_TESTING "Build tests." off)

# Executables
add_executable(bug_test main.cc)

# Packages
add_subdirectory(abseil-cpp)
target_link_libraries(bug_test absl::variant)
