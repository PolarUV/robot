project (Video)

#compile .proto to c++ code
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS VideoMessage.proto)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(Video ${PROTO_SRCS} ${PROTO_HDRS} Video.cpp Video.hpp)

target_link_libraries(Video ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(Video ${CONAN_LIBS})