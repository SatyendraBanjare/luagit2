cmake_minimum_required (VERSION 3.0)
project (luagit2 C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${luagit2_SOURCE_DIR}/cmake")

MESSAGE("${CMAKE_MODULE_PATH}")
 
find_package(Lua REQUIRED)
find_package(LibGit2 REQUIRED)
 
include_directories (
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LUA_INCLUDE_DIR}
    ${LIBGIT2_INCLUDE_DIR}
    ${CMAKE_INSTALL_PREFIX}
)

set(src_dest "src/")
 
set (SOURCES ${src_dest}/main_wrapper.c )

set(lib_dest "lib/")

OPTION(BUILD_SHARED_LIBS ON)
 
add_library (${PROJECT_NAME} SHARED ${SOURCES} ${LUA_LIBRARIES})
target_link_libraries (${PROJECT_NAME} lua5.3 git2)
set_target_properties (${PROJECT_NAME} PROPERTIES PREFIX "")
install(TARGETS ${PROJECT_NAME} DESTINATION "${lib_dest}" )
