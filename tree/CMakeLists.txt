# add all the source file to the "DIR_TREE_SRCS"
aux_source_directory(. DIR_TREE_SRCS)
file(GLOB_RECURSE DIR_TREE_SRCS
    ${DIR_TREE_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(tree STATIC ${DIR_TREE_SRCS})
set_target_properties(tree PROPERTIES LINKER_LANGUAGE CXX)
