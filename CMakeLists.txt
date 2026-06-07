cmake_minimum_required(VERSION 3.10)
project(banking)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(banking STATIC
    src/Account.cpp
    src/Transaction.cpp
)
target_include_directories(banking PUBLIC include)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    
    # Подключаем Google Test напрямую
    add_subdirectory(third-party/gtest)
    
    file(GLOB TEST_SOURCES tests/*.cpp)
    add_executable(check ${TEST_SOURCES})
    target_link_libraries(check banking gtest_main gmock)
    target_include_directories(check PRIVATE include)
    add_test(NAME check COMMAND check)
endif()
