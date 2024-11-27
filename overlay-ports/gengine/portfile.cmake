vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO YGNI-RType/GEngine
    REF v0.6.2
    SHA512 05e22c4bd3af27e5bb27739fe56ef2b5fd8277a7476eeed356b3a12e9babc1dcb3ace1029e5aef00b7435c5ee018818af6456f8c2fdc635f070f497514aa33cf
)

set(ENV{NOT_INSTALL_VCPKG} true)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(PACKAGE_NAME "GEngine")

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)

configure_file("${CMAKE_CURRENT_LIST_DIR}/usage" "${CURRENT_PACKAGES_DIR}/share/${PORT}/usage" COPYONLY)
