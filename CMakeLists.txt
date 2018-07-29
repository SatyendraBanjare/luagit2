cmake_minimum_required (VERSION 3.0)
project (luagit2 C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${luagit2_SOURCE_DIR}/cmake")

MESSAGE("${CMAKE_MODULE_PATH}")
 
find_package(Lua 5.3 EXACT REQUIRED)
find_package(LibGit2 REQUIRED)
 
include_directories (
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LUA_INCLUDE_DIR}
    ${LIBGIT2_INCLUDE_DIR}
    ${CMAKE_INSTALL_PREFIX}
)

set(src_dest "src/")
 
set (SOURCES
             ${src_dest}/luagit2/common/lua_common.c
             ${src_dest}/luagit2/libgit2/lua_libgit2.c
             ${src_dest}/luagit2/blame/lua_blame.c
             ${src_dest}/luagit2/blob/lua_blob.c
             ${src_dest}/luagit2/branch/lua_branch.c
             ${src_dest}/luagit2/branch/lua_branch_help.c
             ${src_dest}/luagit2/clone/lua_clone.c
             ${src_dest}/luagit2/commit/lua_commit.c
             ${src_dest}/luagit2/config/lua_config_help.c
             ${src_dest}/luagit2/config/lua_config.c
             ${src_dest}/luagit2/cred/lua_cred.c
             ${src_dest}/luagit2/cred/lua_cred_help.c
             ${src_dest}/luagit2/index/lua_index.c
             ${src_dest}/luagit2/index/lua_index_help.c
             ${src_dest}/luagit2/oid/lua_oid.c
             ${src_dest}/luagit2/reference/lua_reference.c
             ${src_dest}/luagit2/repository/lua_repository.c
             ${src_dest}/luagit2/signature/lua_signature.c
             ${src_dest}/luagit2/signature/lua_signature_help.c
             ${src_dest}/luagit2/tree/lua_tree.c
             ${src_dest}/luagit2/tag/lua_tag.c
             ${src_dest}/luagit2/object/lua_object.c
             ${src_dest}/luagit2/buf/lua_buf.c
             ${src_dest}/luagit2/buf/lua_buf_help.c
             ${src_dest}/luagit2/annotated/lua_annotated.c
             ${src_dest}/main_wrapper.c 
 )

set(lib_dest "lib/lua/5.3")

OPTION(BUILD_SHARED_LIBS ON)
 
add_library (${PROJECT_NAME} SHARED ${SOURCES} ${LUA_LIBRARIES})
target_link_libraries (${PROJECT_NAME} lua5.3 git2)
set_target_properties (${PROJECT_NAME} PROPERTIES PREFIX "")
install(TARGETS ${PROJECT_NAME} DESTINATION "${lib_dest}" )
