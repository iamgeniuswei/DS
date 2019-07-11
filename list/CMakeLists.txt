# add all the source file to the "DIR_TREE_SRCS"
aux_source_directory(. DIR_LIST_SRCS)
file(GLOB_RECURSE DIR_LIST_SRCS
    ${DIR_LIST_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(list STATIC ${DIR_LIST_SRCS})
set_target_properties(list PROPERTIES LINKER_LANGUAGE CXX)
