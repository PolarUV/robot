project (Logger)

add_library(Logger Logger.hpp Logger.cpp)
target_link_libraries(Logger ${CONAN_LIBS})

target_precompile_headers(Logger PUBLIC Logger.hpp)