cmake_minimum_required(VERSION 3.10)
project(hideandseek)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

include(cmake/automate-vcpkg-gengine.cmake)
vcpkg_bootstrap()
vcpkg_install_gengine()

include_directories(include)

file(GLOB_RECURSE SOURCES source/*.cpp)

add_executable(hs_server ${SOURCES})
add_executable(hs_client ${SOURCES})

find_package(GEngine CONFIG REQUIRED)
target_link_libraries(hs_server PRIVATE GEngine)
target_link_libraries(hs_client PRIVATE GEngine)

target_compile_definitions(hs_server PRIVATE GEngine_Server)
target_compile_definitions(hs_client PRIVATE GEngine_Client)
