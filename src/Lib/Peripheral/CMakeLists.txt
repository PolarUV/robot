project ("Peripheral")

add_library(Peripheral STATIC Peripheral.hpp SensorHandler.cpp MS5837_I2C.cpp BNO055_I2C.cpp  ADS1115_I2C.cpp BMP280_I2C.cpp)
target_precompile_headers(Peripheral PUBLIC Peripheral.hpp)

