# Not setting the path, we assume we are in examples/<example_name>/ inside the GEngine repository
if (NOT CMAKE_GENGINE_PATH)
    if (WIN32)
        if (CMAKE_BUILD_TYPE STREQUAL "Release")
            set(CMAKE_GENGINE_PATH ../../build/Release)
        else()
            set(CMAKE_GENGINE_PATH ../../build/Debug)
        endif()
    else()
        set(CMAKE_GENGINE_PATH ../../build)
    endif()
    include_directories(../../include)
else()
    include_directories(${CMAKE_GENGINE_PATH}/../include)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (MSVC)
        add_compile_options(/D_ITERATOR_DEBUG_LEVEL=0)
    endif()
    find_library(GEngine_LIB NAMES GEngined PATHS ${CMAKE_GENGINE_PATH})
else()
    find_library(GEngine_LIB NAMES GEngine PATHS ${CMAKE_GENGINE_PATH})
endif()

include(cmake/automate-vcpkg.cmake)
vcpkg_bootstrap()
vcpkg_install_packages(stduuid nlohmann-json)

find_package(stduuid CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
