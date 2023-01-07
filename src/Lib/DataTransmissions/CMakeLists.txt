project (DataTransmissions)

add_library(DataTransmissions DataTransmissions.hpp Socket.cpp SPI.cpp UART.cpp I2C.cpp)
target_link_libraries(DataTransmissions ${CONAN_LIBS})

target_precompile_headers(DataTransmissions PUBLIC DataTransmissions.hpp)