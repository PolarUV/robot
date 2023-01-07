project (RobotSettings)

add_library(RobotSettings RobotSettings.hpp RobotSettings.cpp RobotSettingsMessage.proto)
protobuf_generate(TARGET RobotSettings)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(RobotSettings ${REQUIRED_LIBS_QUALIFIED})