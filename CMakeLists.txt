cmake_minimum_required(VERSION 3.10)
project(print)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
target_link_libraries(example1 print)
target_link_libraries(example2 print)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    
    # Отключаем -Werror для GTest
    if(CMAKE_COMPILER_IS_GNUCXX)
        target_compile_options(gtest PRIVATE -w)
        target_compile_options(gtest_main PRIVATE -w)
    endif()
    
    file(GLOB PRINT_TEST_SOURCES tests/*.cpp)
    add_executable(check ${PRINT_TEST_SOURCES})
    target_link_libraries(check print gtest_main)
    add_test(NAME check COMMAND check)
endif()
