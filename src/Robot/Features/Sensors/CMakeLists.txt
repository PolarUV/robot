project (Sensors)

#compile .proto to c++ code
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS SensorsMessage.proto)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(Sensors ${PROTO_SRCS} ${PROTO_HDRS} Sensors.cpp Sensors.hpp)

target_link_libraries(Sensors ${REQUIRED_LIBS_QUALIFIED})