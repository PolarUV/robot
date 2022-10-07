cmake_minimum_required(VERSION 3.23)
project(polar-uv)

#det compiler specific flag
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(COMPILER_SPECIFIC_FLAGS "-fcoroutines-ts")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(COMPILER_SPECIFIC_FLAGS "-fcoroutines")
endif ()

# build options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${COMPILER_SPECIFIC_FLAGS} -flto -static")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Wduplicated-branches -Wduplicated-cond -Wfloat-equal -Wshadow=compatible-local -Wcast-qual")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -mtune=native")

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CMAKE_COMMAND} -E time")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    add_definitions(-DDEBUG)
endif ()

file(COPY ./Conan/conanfile.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ./Conan/conan.cmake DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ./Settings.json DESTINATION ${CMAKE_BINARY_DIR}/bin)

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE starwalker
        REMOTE conancenter
        SETTINGS ${settings})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Включите подпроекты.
add_subdirectory("src")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set_target_properties(polar-uv PROPERTIES OUTPUT_NAME polar-uvd)
endif ()

install(TARGETS polar-uv DESTINATION /home/pi/polar-uv)
install(FILES Settings.json DESTINATION /home/pi/polar-uv)
