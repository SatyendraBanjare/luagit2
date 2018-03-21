cmake_minimum_required (VERSION 3.0)
project (luagit2 C)
 
find_package(Lua REQUIRED)
 
include_directories (
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LUA_INCLUDE_DIR}
)
 
set (SOURCES
    common.c
    binding_main.c
)
 
add_library (${PROJECT_NAME} SHARED ${SOURCES} ${LUA_LIBRARIES})
target_link_libraries (${PROJECT_NAME} lua5.1  git2)
set_target_properties (${PROJECT_NAME} PROPERTIES PREFIX "")
