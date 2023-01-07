project(VideoStream)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(VideoStream Gstreamer.hpp Gstreamer.cpp VideoDeviceMessage.proto)
protobuf_generate(TARGET VideoStream )

target_link_libraries(VideoStream ${CONAN_LIBS})
target_link_libraries(VideoStream gstvideo4linux2)
target_link_libraries(VideoStream gstcodecs-1.0 gstcodecparsers-1.0)