# Project
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(libpcutil LANGUAGES CXX)
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

# Dependencies
find_library(MAGIC_LIBRARY magic)
find_path(MAGIC_INCLUDE_DIR magic.h
  /usr/local/include
  /usr/include
)
find_package(SQLite3 REQUIRED)

# Library
add_library(pcutil SHARED 
  src/apputil.cpp
  src/apputil.h
  src/config.cpp
  src/config.h
  src/emojilist.cpp
  src/emojilist.h
  src/fileutil.cpp
  src/fileutil.h
  src/log.cpp
  src/log.h
  src/messagecache.cpp
  src/messagecache.h
  src/numutil.cpp
  src/numutil.h
  src/profiles.cpp
  src/profiles.h
  src/scopeddirlock.cpp
  src/scopeddirlock.h
  src/status.cpp
  src/status.h
  src/strutil.cpp
  src/strutil.h
  src/timeutil.cpp
  src/timeutil.h
)
install(TARGETS pcutil DESTINATION lib)

# Headers
target_include_directories(pcutil PRIVATE "../ncutil/src" ${MAGIC_INCLUDE_DIR})
target_include_directories(pcutil PRIVATE "../common/src")
target_include_directories(pcutil PRIVATE "../../ext/apathy")
target_include_directories(pcutil PRIVATE "../../ext/emojicpp")
target_include_directories(pcutil PRIVATE "../../ext/sqlite_modern_cpp/hdr")

# Compiler flags
set_target_properties(pcutil PROPERTIES COMPILE_FLAGS
                      "-Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith \
                       -Wcast-qual -Wno-missing-braces -Wswitch-default \
                       -Wunreachable-code -Wundef -Wuninitialized \
                       -Wcast-align")
target_compile_definitions(pcutil PRIVATE PROTON_PROJECT_VERSION="${PROTON_PROJECT_VERSION}")

# Linking
target_link_libraries(pcutil PUBLIC ${MAGIC_LIBRARY} SQLite::SQLite3)
