
## Package Information ##

set(CPACK_PACKAGE_NAME "HideAndSeek")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "3D Hide and Seek using the Prop Hunt mechanisms")
set(CPACK_PACKAGE_VENDOR "YGNI-RType")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

## Package Type ##

if (WIN32)
    set(CPACK_GENERATOR "NSIS")
elseif (APPLE)
    set(CPACK_GENERATOR "Bundle")
elseif (UNIX)
    set(CPACK_GENERATOR "TGZ")
endif()

set(CPACK_SOURCE_GENERATOR "ZIP;TGZ")

## Libs ##

if (WIN32)
    set(VCPKG_LIB_DIR ${VCPKG_ROOT}/installed/${VCPKG_TRIPLET}/bin)
    file(GLOB VCPKG_SHARED_LIBS "${VCPKG_LIB_DIR}/*.dll")
elseif (APPLE)
    set(VCPKG_LIB_DIR ${VCPKG_ROOT}/installed/${VCPKG_TRIPLET}/lib)
    file(GLOB VCPKG_SHARED_LIBS "${VCPKG_LIB_DIR}/*.dylib")
else()
    set(VCPKG_LIB_DIR ${VCPKG_ROOT}/installed/${VCPKG_TRIPLET}/lib)
    file(GLOB VCPKG_SHARED_LIBS "${VCPKG_LIB_DIR}/*.so")
endif()

install(FILES ${VCPKG_SHARED_LIBS} DESTINATION lib)

##########

include(CPack)
