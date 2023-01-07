project(Lib)

add_subdirectory(Peripheral)
add_subdirectory(DataTransmissions)
add_subdirectory(Exceptions)
add_subdirectory(TcpSession)
add_subdirectory(VideoStream)
add_subdirectory(Logger)

add_library(Lib Lib.hpp Lib.cpp)

target_precompile_headers(Lib PUBLIC Lib.hpp)

target_link_libraries(Lib Peripheral)
target_link_libraries(Lib DataTransmissions)
target_link_libraries(Lib Exceptions)
target_link_libraries(Lib TcpSession)
target_link_libraries(Lib VideoStream)
target_link_libraries(Lib Logger)