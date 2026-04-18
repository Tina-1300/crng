cmake_minimum_required(VERSION 3.20)

project(crng VERSION 0.1.0 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build shared libs" OFF)
option(BUILD_TESTS "Build tests" ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ======================
# MODULES CMAKE
# ======================
include(cmake/CompilerWarnings.cmake)
include(cmake/IPO.cmake)
include(cmake/Tests.cmake)

# ======================
# LIBRARY
# ======================
add_library(crng
    src/crng.c
)

target_include_directories(crng
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

apply_project_warnings(crng)
enable_lto_if_supported(crng)

# Windows crypto API
if(WIN32)
    target_link_libraries(crng PRIVATE bcrypt)
endif()

# ======================
# TESTS
# ======================
if(BUILD_TESTS)
    enable_testing()
    enable_tests(crng)
endif()


# cmake -B build -G "Visual Studio 18 2026"
# cmake --build build --config Debug

# cmake --build build --config Release

# ctest --test-dir build -C Debug

# ou

# ctest --test-dir build -C Release

# ----------------------------------


# cmake --preset msvc-release
# cmake --build --preset msvc-release --config Release
# ctest --preset msvc-release -C release

# cmake --preset msvc-debug
# cmake --build --preset msvc-debug --config debug
# ctest --preset msvc-debug -C debug