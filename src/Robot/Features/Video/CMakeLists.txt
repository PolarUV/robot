project (Video)

add_library(Video Video.cpp Video.hpp VideoMessage.proto)
protobuf_generate(TARGET Video)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(Video ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(Video ${CONAN_LIBS})