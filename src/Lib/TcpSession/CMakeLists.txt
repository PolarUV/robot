project (TcpSession)

add_library(TcpSession TcpSession.hpp TcpSession.cpp)
target_link_libraries(DataTransmissions ${CONAN_LIBS})

target_precompile_headers(TcpSession PUBLIC TcpSession.hpp)