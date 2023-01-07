include_directories(Lib)

add_subdirectory(Lib)
add_subdirectory(Robot)

add_executable(polar-uv "Startup.cpp" "Startup.hpp")

target_precompile_headers(polar-uv REUSE_FROM Robot)

target_link_libraries(polar-uv Robot)
target_link_libraries(polar-uv Lib)
target_link_libraries(polar-uv ${CONAN_LIBS})

