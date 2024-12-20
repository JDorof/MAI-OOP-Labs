cmake_minimum_required(VERSION 3.14)
project(lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(src)

file(GLOB SOURCES "src/*.cpp")
add_executable(lab ${SOURCES})

add_executable(runTests tests/unit.cpp src/entity.cpp src/npc.cpp)

target_link_libraries(runTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS runTests
)