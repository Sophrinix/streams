
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(streams)

IF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE RelWithDebInfo)
ENDIF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

find_package(Boost 1.37.0 COMPONENTS thread unit_test_framework filesystem program_options system REQUIRED)
find_package(PkgConfig)

# we should handle this with build/release distinctions, but I'm not that l33t. 

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

pkg_check_modules(GUIDEPS REQUIRED 
  sigc++-2.0>=2.0 
  glibmm-2.4>=2.13.0
  gtkmm-2.4>=2.10
  gtkglextmm-1.2>=1.2
  libglademm-2.4>=2.6)

pkg_check_modules(SOMADEPS REQUIRED
  somanetwork-1.0>=1.0
  somadspio-1.0>=1.0
)

ENABLE_TESTING()

include_directories(src)
include_directories(app)
include_directories(src/ext-common/)

include_directories(src/logging/src)
include_directories(src/logging/boost)

add_subdirectory(src)
add_subdirectory(app)

