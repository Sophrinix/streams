link_directories(
  ${Boost_LIBRARY_DIRS}
  ${GUIDEPS_LIBRARY_DIRS}
  ${SOMADEPS_LIBRARY_DIRS}
)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${GUIDEPS_INCLUDE_DIRS})
include_directories(${SOMADEPS_INCLUDE_DIRS})

set(sources_SRCS
  sourcebase.cc
  noisewave.cc
  sourcefactory.cc
  netdatawave.cc
  netdataraw.cc)

add_library(sources
  ${sources_SRCS})

