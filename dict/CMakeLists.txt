# add all the source file to the "DIR_TREE_SRCS"
aux_source_directory(. DIR_DICT_SRCS)
file(GLOB_RECURSE DIR_DICT_SRCS
    ${DIR_DICT_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(dict STATIC ${DIR_DICT_SRCS})
set_target_properties(dict PROPERTIES LINKER_LANGUAGE CXX)
