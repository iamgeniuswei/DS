
# add all the source file to the "DIR_TREE_SRCS"
aux_source_directory(. DIR_BITMAP_SRCS)
file(GLOB_RECURSE DIR_BITMAP_SRCS
    ${DIR_BITMAP_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(bitmap STATIC ${DIR_BITMAP_SRCS})
set_target_properties(bitmap PROPERTIES LINKER_LANGUAGE CXX)
