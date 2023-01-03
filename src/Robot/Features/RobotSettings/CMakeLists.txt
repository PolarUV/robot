project (RobotSettings)

#compile .proto to c++ code
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS RobotSettingsMessage.proto)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(RobotSettings ${PROTO_SRCS} ${PROTO_HDRS} RobotSettings.hpp RobotSettings.cpp)

target_link_libraries(RobotSettings ${REQUIRED_LIBS_QUALIFIED})