# Project
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(libtgchat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

# Ccache
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

# Build type
set(DEFAULT_BUILD_TYPE "Release")
if((EXISTS "${CMAKE_SOURCE_DIR}/.svn") OR (EXISTS "${CMAKE_SOURCE_DIR}/.git"))
  set(DEFAULT_BUILD_TYPE "Debug")
endif()
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Using build type '${DEFAULT_BUILD_TYPE}' (default).")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}")
else()
  message(STATUS "Using build type '${CMAKE_BUILD_TYPE}'.")
endif()

# Compiler specifics
set(ATOMIC_TEST_SOURCE
  "
  #include <atomic>
  int main() { std::atomic<int64_t> i(0); i++; return 0; }
  ")
check_cxx_source_compiles("${ATOMIC_TEST_SOURCE}" HAVE_BUILTIN_ATOMIC)
if (NOT HAVE_BUILTIN_ATOMIC)
  message(STATUS "No built-in atomic, using libatomic.")
  set (USE_LIBATOMIC TRUE)
else()
  message(STATUS "Using built-in atomic.")
endif()

# Platform specifics
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  add_definitions(-D_XOPEN_SOURCE_EXTENDED)
  set(CMAKE_PREFIX_PATH /usr/local/opt/ncurses)
  set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
endif()

# Library
add_library(tgchat SHARED
  src/tgchat.cpp
  src/tgchat.h
)
install(TARGETS tgchat DESTINATION lib)

# Headers
target_include_directories(tgchat PRIVATE "../../ext/apathy")
target_include_directories(tgchat PRIVATE "../common/src")
target_include_directories(tgchat PRIVATE "../pcutil/src")
target_include_directories(tgchat PRIVATE "ext/td")

# Dependency tdlib
add_subdirectory(ext/td EXCLUDE_FROM_ALL)

set(TDLIBNAME "libtdclientshared${CMAKE_SHARED_LIBRARY_SUFFIX}")
install(FILES ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${TDLIBNAME} DESTINATION lib)

# Linking
target_link_libraries(tgchat PUBLIC pcutil tdclientshared)
if (USE_LIBATOMIC)
  set_target_properties(proton PROPERTIES LINK_FLAGS "-latomic")
endif()

# Compiler flags
set_target_properties(tgchat PROPERTIES COMPILE_FLAGS
                      "-Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith \
                       -Wcast-qual -Wno-missing-braces -Wswitch-default \
                       -Wunreachable-code -Wundef -Wuninitialized \
                       -Wcast-align")
target_compile_definitions(tgchat PRIVATE PROJECT_VERSION="${PROJECT_VERSION}")
