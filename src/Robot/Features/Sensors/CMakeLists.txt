project (Sensors)

add_library(Sensors Sensors.cpp Sensors.hpp SensorsMessage.proto)
protobuf_generate(TARGET Sensors)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(Sensors ${REQUIRED_LIBS_QUALIFIED})